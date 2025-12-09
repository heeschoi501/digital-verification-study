#!/usr/bin/env python3
import os
import shutil

# ------------------------------------------------------
# 1. 프로젝트 설정
# ------------------------------------------------------
# Verilog 소스 파일들이 있는 폴더 (지금 구조 기준: ./src)
SRC_DIR = "src"

# Yosys / Graphviz(dot) 실행 파일 이름
YOSYS_CMD = "yosys"
DOT_CMD   = "dot"

# 2. 스케매틱을 보고 싶은 모듈 이름들
#    → Verilog에서 module 이름과 정확히 일치해야 합니다.
modules_to_draw = [
    "scanner_top",            # 전체 스캐너 Top
    "scanner_main_controller",# 메인 FSM
    "wafer_stage_controller", # 웨이퍼 스테이지
    "reticle_stage_controller",# 레티클 스테이지
    "wafer_handler",          # 웨이퍼 핸들러(로더)
    "reticle_handler",        # 레티클 핸들러(로더)
    "light_source_ctrl",      # 광원 제어
    "env_control_ctrl"        # 환경 제어
]

# 3. Yosys에 읽어들일 Verilog 파일 목록
verilog_files = [
    os.path.join(SRC_DIR, "scanner_top.v"),
    os.path.join(SRC_DIR, "scanner_main_controller.v"),
    os.path.join(SRC_DIR, "scanner_stage_module.v"),
    os.path.join(SRC_DIR, "scanner_handler_module.v"),
    os.path.join(SRC_DIR, "scanner_source_control.v"),
]

# ------------------------------------------------------
# 유틸: 바이너리 존재 여부 확인
# ------------------------------------------------------
def check_binary_exists(cmd_name: str) -> bool:
    """PATH 상에 실행파일이 있는지 확인"""
    return shutil.which(cmd_name) is not None

# ------------------------------------------------------
# 모듈 단위로 스케매틱 그리기
# ------------------------------------------------------
def draw_module(module_name: str):
    print(f"\n📸 [{module_name}] 스케매틱 생성 중...")

    # Yosys 스크립트 문자열 생성
    # - 여러 .v 파일 read_verilog
    # - hierarchy -top {module_name} 로 top 지정
    # - show 명령으로 .dot 생성
    read_cmds = "\n".join([f"read_verilog {vf}" for vf in verilog_files])

    yosys_script = f"""
{read_cmds}
hierarchy -check -top {module_name}
proc; opt; memory; opt; fsm; opt
show -format dot -prefix {module_name} -colors 2 -width -stretch
"""

    # temp.ys 로 저장
    with open("temp.ys", "w") as f:
        f.write(yosys_script)

    # Yosys 실행 (조용 모드: -Q -q)
    yosys_ret = os.system(f"{YOSYS_CMD} -Q -q temp.ys")

    if yosys_ret != 0:
        print(f"   -> ❌ Yosys 실행 실패 (모듈 이름/경로를 확인하세요)")
        return

    dot_file = f"{module_name}.dot"
    png_file = f"{module_name}.png"

    if not os.path.exists(dot_file):
        print(f"   -> ❌ .dot 파일({dot_file})이 생성되지 않았습니다. 모듈 이름이 맞는지 확인하세요.")
        return

    # Graphviz dot → png 변환
    dot_ret = os.system(f"{DOT_CMD} -Tpng {dot_file} -o {png_file}")
    if dot_ret != 0:
        print(f"   -> ❌ dot 실행 실패 (Graphviz 설치 여부를 확인하세요)")
    else:
        print(f"   -> ✅ 생성 완료: {png_file}")

    # .dot 파일은 지워도 되고, 남겨두셔도 됩니다.
    try:
        os.remove(dot_file)
    except OSError:
        pass

# ------------------------------------------------------
# 메인 실행부
# ------------------------------------------------------
if __name__ == "__main__":
    print("=== 🏛️ 스캐너 RTL 스케매틱 추출 시작 ===")

    # 0) Yosys / dot 여부 체크
    if not check_binary_exists(YOSYS_CMD):
        print(f"❌ '{YOSYS_CMD}' 명령을 찾을 수 없습니다. 우분투에서 다음을 실행해 주세요:")
        print("   sudo apt-get install yosys")
        exit(1)

    if not check_binary_exists(DOT_CMD):
        print(f"❌ '{DOT_CMD}' 명령을 찾을 수 없습니다. 우분투에서 다음을 실행해 주세요:")
        print("   sudo apt-get install graphviz")
        exit(1)

    # 1) Verilog 파일 존재 체크
    missing_files = [vf for vf in verilog_files if not os.path.exists(vf)]
    if missing_files:
        print("❌ 아래 Verilog 파일들을 찾을 수 없습니다:")
        for mf in missing_files:
            print(f"   - {mf}")
        print("   → SRC_DIR 경로나 파일 이름을 다시 확인해 주세요.")
        exit(1)

    # 2) 각 모듈에 대해 스케매틱 생성
    for mod in modules_to_draw:
        draw_module(mod)

    # 3) 임시 Yosys 스크립트 제거
    if os.path.exists("temp.ys"):
        os.remove("temp.ys")

    print("\n=== ✨ 모든 작업 완료! 현재 폴더에 생성된 *.png 파일들을 확인해 주세요. ===")
