import os

# 1. 보고 싶은 모듈들의 이름 목록 (Verilog 모듈명과 일치해야 함)
modules_to_draw = [
    "scanner_top",       # 전체 연결도
    "main_controller",   # 핵심 두뇌 (FSM)
    "wafer_loader",      # 웨이퍼 로더
    "reticle_loader",    # 레티클 로더
    "wafer_stage",       # 웨이퍼 스테이지
    "reticle_stage",     # 레티클 스테이지
    "light_source",      # 레이저 소스
    "env_control"        # 환경 제어
]

def draw_module(module_name):
    print(f"📸 [{module_name}] 설계도를 그리는 중...")

    # Yosys 명령어 스크립트 생성
    # 핵심: hierarchy -top {module_name} -> 이 모듈을 주인공으로 설정함
    yosys_script = f"""
    read_verilog submodules.v
    read_verilog main_controller.v
    read_verilog scanner_top.v
    hierarchy -check -top {module_name}
    proc; opt; memory; opt; fsm; opt
    show -format dot -prefix {module_name} -colors 2 -width -stretch
    """

    # 스크립트 파일 저장
    with open("temp.ys", "w") as f:
        f.write(yosys_script)

    # Yosys 실행 (회로 합성 -> .dot 파일 생성)
    os.system("yosys -Q -q temp.ys")

    # Graphviz 실행 (.dot -> .png 변환)
    if os.path.exists(f"{module_name}.dot"):
        os.system(f"dot -Tpng {module_name}.dot -o {module_name}.png")
        print(f"   -> ✅ 생성 완료: {module_name}.png")
        # 임시 파일 삭제
        os.remove(f"{module_name}.dot")
    else:
        print(f"   -> ❌ 실패: {module_name} 모듈을 찾을 수 없습니다.")

# --- 메인 실행 ---
if __name__ == "__main__":
    print("=== 🏛️ 전체 모듈 RTL 회로도 추출 시작 ===")
    
    for mod in modules_to_draw:
        draw_module(mod)
        
    # 임시 스크립트 삭제
    if os.path.exists("temp.ys"): os.remove("temp.ys")
    
    print("\n=== ✨ 모든 작업 완료! 탐색기를 확인하세요. ===")