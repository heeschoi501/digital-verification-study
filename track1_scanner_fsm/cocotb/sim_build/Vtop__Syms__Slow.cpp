// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(262);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_scanner_top = new VerilatedScope{this, "scanner_top", "scanner_top", "scanner_top", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_scanner_top__u_handler = new VerilatedScope{this, "scanner_top.u_handler", "u_handler", "scanner_handler_module", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_scanner_top__u_main = new VerilatedScope{this, "scanner_top.u_main", "u_main", "scanner_main_controller", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_scanner_top__u_source = new VerilatedScope{this, "scanner_top.u_source", "u_source", "scanner_source_control", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_scanner_top__u_stage = new VerilatedScope{this, "scanner_top.u_stage", "u_stage", "scanner_stage_module", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_scanner_top);
    __Vhier.add(__Vscopep_scanner_top, __Vscopep_scanner_top__u_handler);
    __Vhier.add(__Vscopep_scanner_top, __Vscopep_scanner_top__u_main);
    __Vhier.add(__Vscopep_scanner_top, __Vscopep_scanner_top__u_source);
    __Vhier.add(__Vscopep_scanner_top, __Vscopep_scanner_top__u_stage);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("current_process", &(TOP.current_process), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("env_status", &(TOP.env_status), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("interlock_sig", &(TOP.interlock_sig), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("op_start_btn", &(TOP.op_start_btn), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("reset", &(TOP.reset), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("source_status", &(TOP.source_status), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("clk", &(TOP.scanner_top__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("cmd_rl_load", &(TOP.scanner_top__DOT__cmd_rl_load), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("cmd_rl_unload", &(TOP.scanner_top__DOT__cmd_rl_unload), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("cmd_rs_calib", &(TOP.scanner_top__DOT__cmd_rs_calib), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("cmd_rs_scan", &(TOP.scanner_top__DOT__cmd_rs_scan), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("cmd_source_active", &(TOP.scanner_top__DOT__cmd_source_active), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("cmd_wl_load", &(TOP.scanner_top__DOT__cmd_wl_load), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("cmd_wl_unload", &(TOP.scanner_top__DOT__cmd_wl_unload), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("cmd_ws_align", &(TOP.scanner_top__DOT__cmd_ws_align), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("cmd_ws_calib", &(TOP.scanner_top__DOT__cmd_ws_calib), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("cmd_ws_scan", &(TOP.scanner_top__DOT__cmd_ws_scan), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("current_process", &(TOP.scanner_top__DOT__current_process), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top->varInsert("env_ok", &(TOP.scanner_top__DOT__env_ok), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("env_status", &(TOP.scanner_top__DOT__env_status), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("interlock_sig", &(TOP.scanner_top__DOT__interlock_sig), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("op_start_btn", &(TOP.scanner_top__DOT__op_start_btn), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("reset", &(TOP.scanner_top__DOT__reset), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("rl_ready", &(TOP.scanner_top__DOT__rl_ready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("rs_done", &(TOP.scanner_top__DOT__rs_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("source_status", &(TOP.scanner_top__DOT__source_status), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("wafer_index", &(TOP.scanner_top__DOT__wafer_index), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_scanner_top->varInsert("wl_ready", &(TOP.scanner_top__DOT__wl_ready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top->varInsert("ws_done", &(TOP.scanner_top__DOT__ws_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_handler->varInsert("clk", &(TOP.scanner_top__DOT__u_handler__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_handler->varInsert("cmd_rl_load", &(TOP.scanner_top__DOT__u_handler__DOT__cmd_rl_load), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_handler->varInsert("cmd_rl_unload", &(TOP.scanner_top__DOT__u_handler__DOT__cmd_rl_unload), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_handler->varInsert("cmd_wl_load", &(TOP.scanner_top__DOT__u_handler__DOT__cmd_wl_load), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_handler->varInsert("cmd_wl_unload", &(TOP.scanner_top__DOT__u_handler__DOT__cmd_wl_unload), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_handler->varInsert("reset", &(TOP.scanner_top__DOT__u_handler__DOT__reset), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_handler->varInsert("rl_ready", &(TOP.scanner_top__DOT__u_handler__DOT__rl_ready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_handler->varInsert("rl_timer", &(TOP.scanner_top__DOT__u_handler__DOT__rl_timer), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_handler->varInsert("wl_ready", &(TOP.scanner_top__DOT__u_handler__DOT__wl_ready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_handler->varInsert("wl_timer", &(TOP.scanner_top__DOT__u_handler__DOT__wl_timer), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("ALIGN", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__ALIGN))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("ENV_CHECK", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__ENV_CHECK))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("ERROR", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__ERROR))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("EXPOSE", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__EXPOSE))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("IDLE", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__IDLE))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("LOAD_RET", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__LOAD_RET))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("LOAD_WFR", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__LOAD_WFR))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("LOT_SIZE", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__LOT_SIZE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_scanner_top__u_main->varInsert("LOT_SIZE_U8", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__LOT_SIZE_U8))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_scanner_top__u_main->varInsert("SETUP", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__SETUP))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("UNLOAD", const_cast<void*>(static_cast<const void*>(&(TOP.scanner_top__DOT__u_main__DOT__UNLOAD))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("clk", &(TOP.scanner_top__DOT__u_main__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("cmd_rl_load", &(TOP.scanner_top__DOT__u_main__DOT__cmd_rl_load), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("cmd_rl_unload", &(TOP.scanner_top__DOT__u_main__DOT__cmd_rl_unload), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("cmd_rs_calib", &(TOP.scanner_top__DOT__u_main__DOT__cmd_rs_calib), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("cmd_rs_scan", &(TOP.scanner_top__DOT__u_main__DOT__cmd_rs_scan), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("cmd_source_active", &(TOP.scanner_top__DOT__u_main__DOT__cmd_source_active), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("cmd_wl_load", &(TOP.scanner_top__DOT__u_main__DOT__cmd_wl_load), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("cmd_wl_unload", &(TOP.scanner_top__DOT__u_main__DOT__cmd_wl_unload), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("cmd_ws_align", &(TOP.scanner_top__DOT__u_main__DOT__cmd_ws_align), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("cmd_ws_calib", &(TOP.scanner_top__DOT__u_main__DOT__cmd_ws_calib), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("cmd_ws_scan", &(TOP.scanner_top__DOT__u_main__DOT__cmd_ws_scan), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("env_ok", &(TOP.scanner_top__DOT__u_main__DOT__env_ok), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("next_state", &(TOP.scanner_top__DOT__u_main__DOT__next_state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("next_wafer_index", &(TOP.scanner_top__DOT__u_main__DOT__next_wafer_index), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_scanner_top__u_main->varInsert("process_state", &(TOP.scanner_top__DOT__u_main__DOT__process_state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("reset", &(TOP.scanner_top__DOT__u_main__DOT__reset), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("rl_ready", &(TOP.scanner_top__DOT__u_main__DOT__rl_ready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("rs_done", &(TOP.scanner_top__DOT__u_main__DOT__rs_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("safety_sensor", &(TOP.scanner_top__DOT__u_main__DOT__safety_sensor), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("start_op", &(TOP.scanner_top__DOT__u_main__DOT__start_op), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("state", &(TOP.scanner_top__DOT__u_main__DOT__state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_main->varInsert("wafer_index", &(TOP.scanner_top__DOT__u_main__DOT__wafer_index), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_scanner_top__u_main->varInsert("wl_ready", &(TOP.scanner_top__DOT__u_main__DOT__wl_ready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_main->varInsert("ws_done", &(TOP.scanner_top__DOT__u_main__DOT__ws_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_source->varInsert("clk", &(TOP.scanner_top__DOT__u_source__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_source->varInsert("cmd_source_active", &(TOP.scanner_top__DOT__u_source__DOT__cmd_source_active), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_source->varInsert("env_ok", &(TOP.scanner_top__DOT__u_source__DOT__env_ok), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_source->varInsert("env_timer", &(TOP.scanner_top__DOT__u_source__DOT__env_timer), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_scanner_top__u_source->varInsert("reset", &(TOP.scanner_top__DOT__u_source__DOT__reset), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_source->varInsert("source_on", &(TOP.scanner_top__DOT__u_source__DOT__source_on), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_stage->varInsert("clk", &(TOP.scanner_top__DOT__u_stage__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_stage->varInsert("cmd_rs_calib", &(TOP.scanner_top__DOT__u_stage__DOT__cmd_rs_calib), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_stage->varInsert("cmd_rs_scan", &(TOP.scanner_top__DOT__u_stage__DOT__cmd_rs_scan), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_stage->varInsert("cmd_ws_align", &(TOP.scanner_top__DOT__u_stage__DOT__cmd_ws_align), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_stage->varInsert("cmd_ws_calib", &(TOP.scanner_top__DOT__u_stage__DOT__cmd_ws_calib), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_stage->varInsert("cmd_ws_scan", &(TOP.scanner_top__DOT__u_stage__DOT__cmd_ws_scan), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_stage->varInsert("reset", &(TOP.scanner_top__DOT__u_stage__DOT__reset), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_stage->varInsert("rs_done", &(TOP.scanner_top__DOT__u_stage__DOT__rs_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_stage->varInsert("rs_timer", &(TOP.scanner_top__DOT__u_stage__DOT__rs_timer), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_scanner_top__u_stage->varInsert("ws_done", &(TOP.scanner_top__DOT__u_stage__DOT__ws_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_scanner_top__u_stage->varInsert("ws_timer", &(TOP.scanner_top__DOT__u_stage__DOT__ws_timer), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_scanner_top);
    __Vhier.remove(__Vscopep_scanner_top, __Vscopep_scanner_top__u_handler);
    __Vhier.remove(__Vscopep_scanner_top, __Vscopep_scanner_top__u_main);
    __Vhier.remove(__Vscopep_scanner_top, __Vscopep_scanner_top__u_source);
    __Vhier.remove(__Vscopep_scanner_top, __Vscopep_scanner_top__u_stage);
    if (__Vm_dumping) _traceDumpClose();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_scanner_top, __Vscopep_scanner_top = nullptr);
    VL_DO_CLEAR(delete __Vscopep_scanner_top__u_handler, __Vscopep_scanner_top__u_handler = nullptr);
    VL_DO_CLEAR(delete __Vscopep_scanner_top__u_main, __Vscopep_scanner_top__u_main = nullptr);
    VL_DO_CLEAR(delete __Vscopep_scanner_top__u_source, __Vscopep_scanner_top__u_source = nullptr);
    VL_DO_CLEAR(delete __Vscopep_scanner_top__u_stage, __Vscopep_scanner_top__u_stage = nullptr);
    // Tear down sub module instances
}

void Vtop__Syms::_traceDump() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vtop__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        const std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vtop__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}
