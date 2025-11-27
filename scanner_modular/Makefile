SIM = verilator
TOPLEVEL_LANG = verilog

# [핵심 수정] Verilator에게 "파형 녹화 기능(--trace)을 켜라"고 강제 명령
EXTRA_ARGS += --trace --trace-structs

# 소스 파일 목록
VERILOG_SOURCES = $(PWD)/submodules.v \
                  $(PWD)/main_controller.v \
                  $(PWD)/scanner_top.v

TOPLEVEL = scanner_top
COCOTB_TEST_MODULES = test_modular

include $(shell cocotb-config --makefiles)/Makefile.sim