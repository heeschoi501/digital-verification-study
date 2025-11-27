import os
import sys

def generate_schematic():
    print("🎨 회로도 생성을 시작합니다...")

    # 1. Yosys에게 내릴 명령서(Script) 만들기
    # - Verilog 파일들을 읽고(read_verilog)
    # - Top 모듈을 찾아서(hierarchy)
    # - 최적화(proc; opt)를 거친 뒤
    # - 도면 파일(.dot)을 만들어라(show)
    
    yosys_cmd = """
    read_verilog submodules.v
    read_verilog main_controller.v
    read_verilog scanner_top.v
    hierarchy -check -top scanner_top
    proc; opt; memory; opt
    show -format dot -prefix scanner_schematic -colors 2 -width -stretch
    """
    
    # 명령서를 파일로 저장
    with open("run_yosys.ys", "w") as f:
        f.write(yosys_cmd)

    # 2. Yosys 실행 (회로 해석 -> .dot 파일 생성)
    print("   -> [1/2] Verilog 해석 및 합성 중 (Yosys)...")
    exit_code = os.system("yosys -Q -q run_yosys.ys") # -Q -q: 조용히 실행
    
    if exit_code != 0:
        print("❌ Yosys 실행 실패! 문법 에러를 확인하세요.")
        return

    # 3. Graphviz 실행 (.dot -> .png 이미지 변환)
    print("   -> [2] 이미지로 변환 중 (Graphviz)...")
    # scanner_schematic.dot 파일을 scanner_schematic.png로 변환
    os.system("dot -Tpng scanner_schematic.dot -o scanner_schematic.png")

    # 4. 결과 알림
    if os.path.exists("scanner_schematic.png"):
        print("\n✅ [성공] 'scanner_schematic.png' 파일이 생성되었습니다!")
        print("   -> VS Code 왼쪽 탐색기에서 이미지 파일을 클릭해서 확인하세요.")
    else:
        print("❌ 이미지 생성 실패.")

if __name__ == "__main__":
    generate_schematic()