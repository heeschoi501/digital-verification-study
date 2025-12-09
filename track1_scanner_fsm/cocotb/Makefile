# file: cocotb/Makefile

# 시뮬레이터: Verilator 사용
SIM           = verilator
TOPLEVEL_LANG = verilog

# Verilator 파형 옵션
EXTRA_ARGS += --trace --trace-structs

# 🔹 Verilog 소스 경로 (지금 구조: ../src/*.v)
VERILOG_SOURCES = \
    ../src/scanner_top.v \
    ../src/scanner_main_controller.v \
    ../src/scanner_stage_module.v \
    ../src/scanner_handler_module.v \
    ../src/scanner_source_control.v

# DUT top 모듈 이름
TOPLEVEL = scanner_top

# cocotb 테스트 파이썬 파일 이름 (test_scanner_top.py)
# (확장자 .py 는 쓰지 않습니다)
MODULE = test_scanner_top

# cocotb 공용 Makefile include
include $(shell cocotb-config --makefiles)/Makefile.sim
