// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.reset));
    bufp->chgBit(oldp+2,(vlSelfRef.op_start_btn));
    bufp->chgBit(oldp+3,(vlSelfRef.interlock_sig));
    bufp->chgCData(oldp+4,(vlSelfRef.current_process),4);
    bufp->chgBit(oldp+5,(vlSelfRef.source_status));
    bufp->chgBit(oldp+6,(vlSelfRef.env_status));
    bufp->chgBit(oldp+7,(vlSelfRef.scanner_top__DOT__clk));
    bufp->chgBit(oldp+8,(vlSelfRef.scanner_top__DOT__reset));
    bufp->chgBit(oldp+9,(vlSelfRef.scanner_top__DOT__op_start_btn));
    bufp->chgBit(oldp+10,(vlSelfRef.scanner_top__DOT__interlock_sig));
    bufp->chgCData(oldp+11,(vlSelfRef.scanner_top__DOT__current_process),4);
    bufp->chgBit(oldp+12,(vlSelfRef.scanner_top__DOT__source_status));
    bufp->chgBit(oldp+13,(vlSelfRef.scanner_top__DOT__env_status));
    bufp->chgBit(oldp+14,(vlSelfRef.scanner_top__DOT__cmd_wl_load));
    bufp->chgBit(oldp+15,(vlSelfRef.scanner_top__DOT__cmd_wl_unload));
    bufp->chgBit(oldp+16,(vlSelfRef.scanner_top__DOT__cmd_rl_load));
    bufp->chgBit(oldp+17,(vlSelfRef.scanner_top__DOT__cmd_rl_unload));
    bufp->chgBit(oldp+18,(vlSelfRef.scanner_top__DOT__cmd_ws_calib));
    bufp->chgBit(oldp+19,(vlSelfRef.scanner_top__DOT__cmd_ws_align));
    bufp->chgBit(oldp+20,(vlSelfRef.scanner_top__DOT__cmd_ws_scan));
    bufp->chgBit(oldp+21,(vlSelfRef.scanner_top__DOT__cmd_rs_calib));
    bufp->chgBit(oldp+22,(vlSelfRef.scanner_top__DOT__cmd_rs_scan));
    bufp->chgBit(oldp+23,(vlSelfRef.scanner_top__DOT__cmd_source_active));
    bufp->chgBit(oldp+24,(vlSelfRef.scanner_top__DOT__wl_ready));
    bufp->chgBit(oldp+25,(vlSelfRef.scanner_top__DOT__rl_ready));
    bufp->chgBit(oldp+26,(vlSelfRef.scanner_top__DOT__ws_done));
    bufp->chgBit(oldp+27,(vlSelfRef.scanner_top__DOT__rs_done));
    bufp->chgBit(oldp+28,(vlSelfRef.scanner_top__DOT__env_ok));
    bufp->chgCData(oldp+29,(vlSelfRef.scanner_top__DOT__wafer_index),8);
    bufp->chgBit(oldp+30,(vlSelfRef.scanner_top__DOT__u_handler__DOT__clk));
    bufp->chgBit(oldp+31,(vlSelfRef.scanner_top__DOT__u_handler__DOT__reset));
    bufp->chgBit(oldp+32,(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_wl_load));
    bufp->chgBit(oldp+33,(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_wl_unload));
    bufp->chgBit(oldp+34,(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_rl_load));
    bufp->chgBit(oldp+35,(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_rl_unload));
    bufp->chgBit(oldp+36,(vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_ready));
    bufp->chgBit(oldp+37,(vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_ready));
    bufp->chgCData(oldp+38,(vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_timer),4);
    bufp->chgCData(oldp+39,(vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_timer),4);
    bufp->chgBit(oldp+40,(vlSelfRef.scanner_top__DOT__u_main__DOT__clk));
    bufp->chgBit(oldp+41,(vlSelfRef.scanner_top__DOT__u_main__DOT__reset));
    bufp->chgBit(oldp+42,(vlSelfRef.scanner_top__DOT__u_main__DOT__start_op));
    bufp->chgBit(oldp+43,(vlSelfRef.scanner_top__DOT__u_main__DOT__safety_sensor));
    bufp->chgBit(oldp+44,(vlSelfRef.scanner_top__DOT__u_main__DOT__wl_ready));
    bufp->chgBit(oldp+45,(vlSelfRef.scanner_top__DOT__u_main__DOT__rl_ready));
    bufp->chgBit(oldp+46,(vlSelfRef.scanner_top__DOT__u_main__DOT__ws_done));
    bufp->chgBit(oldp+47,(vlSelfRef.scanner_top__DOT__u_main__DOT__rs_done));
    bufp->chgBit(oldp+48,(vlSelfRef.scanner_top__DOT__u_main__DOT__env_ok));
    bufp->chgBit(oldp+49,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_load));
    bufp->chgBit(oldp+50,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_unload));
    bufp->chgBit(oldp+51,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_load));
    bufp->chgBit(oldp+52,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_unload));
    bufp->chgBit(oldp+53,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_calib));
    bufp->chgBit(oldp+54,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_align));
    bufp->chgBit(oldp+55,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_scan));
    bufp->chgBit(oldp+56,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_calib));
    bufp->chgBit(oldp+57,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_scan));
    bufp->chgBit(oldp+58,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_source_active));
    bufp->chgCData(oldp+59,(vlSelfRef.scanner_top__DOT__u_main__DOT__process_state),4);
    bufp->chgCData(oldp+60,(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index),8);
    bufp->chgCData(oldp+61,(vlSelfRef.scanner_top__DOT__u_main__DOT__state),4);
    bufp->chgCData(oldp+62,(vlSelfRef.scanner_top__DOT__u_main__DOT__next_state),4);
    bufp->chgCData(oldp+63,(vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index),8);
    bufp->chgBit(oldp+64,(vlSelfRef.scanner_top__DOT__u_source__DOT__clk));
    bufp->chgBit(oldp+65,(vlSelfRef.scanner_top__DOT__u_source__DOT__reset));
    bufp->chgBit(oldp+66,(vlSelfRef.scanner_top__DOT__u_source__DOT__cmd_source_active));
    bufp->chgBit(oldp+67,(vlSelfRef.scanner_top__DOT__u_source__DOT__source_on));
    bufp->chgBit(oldp+68,(vlSelfRef.scanner_top__DOT__u_source__DOT__env_ok));
    bufp->chgCData(oldp+69,(vlSelfRef.scanner_top__DOT__u_source__DOT__env_timer),4);
    bufp->chgBit(oldp+70,(vlSelfRef.scanner_top__DOT__u_stage__DOT__clk));
    bufp->chgBit(oldp+71,(vlSelfRef.scanner_top__DOT__u_stage__DOT__reset));
    bufp->chgBit(oldp+72,(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_calib));
    bufp->chgBit(oldp+73,(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_align));
    bufp->chgBit(oldp+74,(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_scan));
    bufp->chgBit(oldp+75,(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_rs_calib));
    bufp->chgBit(oldp+76,(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_rs_scan));
    bufp->chgBit(oldp+77,(vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_done));
    bufp->chgBit(oldp+78,(vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_done));
    bufp->chgCData(oldp+79,(vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_timer),5);
    bufp->chgCData(oldp+80,(vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_timer),5);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
