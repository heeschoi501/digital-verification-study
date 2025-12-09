// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"op_start_btn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"interlock_sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"current_process",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+6,0,"source_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"env_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("scanner_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+8,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"op_start_btn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"interlock_sig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"current_process",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+13,0,"source_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"env_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"cmd_wl_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"cmd_wl_unload",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"cmd_rl_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"cmd_rl_unload",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"cmd_ws_calib",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"cmd_ws_align",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"cmd_ws_scan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"cmd_rs_calib",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"cmd_rs_scan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"cmd_source_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"wl_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"rl_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"ws_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"rs_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"env_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"wafer_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("u_handler", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+31,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"cmd_wl_load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"cmd_wl_unload",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"cmd_rl_load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"cmd_rl_unload",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"wl_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"rl_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"wl_timer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+40,0,"rl_timer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_main", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"LOT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+41,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"start_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"safety_sensor",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"wl_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"rl_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"ws_done",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rs_done",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"env_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"cmd_wl_load",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"cmd_wl_unload",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"cmd_rl_load",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"cmd_rl_unload",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"cmd_ws_calib",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"cmd_ws_align",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"cmd_ws_scan",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"cmd_rs_calib",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"cmd_rs_scan",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"cmd_source_active",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"process_state",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+61,0,"wafer_index",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+83,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+84,0,"ENV_CHECK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+85,0,"LOAD_RET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+86,0,"LOAD_WFR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+87,0,"SETUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+88,0,"ALIGN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+89,0,"EXPOSE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+90,0,"UNLOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+91,0,"ERROR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+92,0,"LOT_SIZE_U8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+62,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+63,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+64,0,"next_wafer_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_source", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+65,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"cmd_source_active",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"source_on",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"env_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"env_timer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+71,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"cmd_ws_calib",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"cmd_ws_align",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"cmd_ws_scan",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"cmd_rs_calib",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"cmd_rs_scan",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"ws_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"rs_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"ws_timer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+81,0,"rs_timer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+82,(0x00000019U),32);
    bufp->fullCData(oldp+83,(0U),4);
    bufp->fullCData(oldp+84,(1U),4);
    bufp->fullCData(oldp+85,(2U),4);
    bufp->fullCData(oldp+86,(3U),4);
    bufp->fullCData(oldp+87,(4U),4);
    bufp->fullCData(oldp+88,(5U),4);
    bufp->fullCData(oldp+89,(6U),4);
    bufp->fullCData(oldp+90,(7U),4);
    bufp->fullCData(oldp+91,(0x0fU),4);
    bufp->fullCData(oldp+92,(0x19U),8);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.clk));
    bufp->fullBit(oldp+2,(vlSelfRef.reset));
    bufp->fullBit(oldp+3,(vlSelfRef.op_start_btn));
    bufp->fullBit(oldp+4,(vlSelfRef.interlock_sig));
    bufp->fullCData(oldp+5,(vlSelfRef.current_process),4);
    bufp->fullBit(oldp+6,(vlSelfRef.source_status));
    bufp->fullBit(oldp+7,(vlSelfRef.env_status));
    bufp->fullBit(oldp+8,(vlSelfRef.scanner_top__DOT__clk));
    bufp->fullBit(oldp+9,(vlSelfRef.scanner_top__DOT__reset));
    bufp->fullBit(oldp+10,(vlSelfRef.scanner_top__DOT__op_start_btn));
    bufp->fullBit(oldp+11,(vlSelfRef.scanner_top__DOT__interlock_sig));
    bufp->fullCData(oldp+12,(vlSelfRef.scanner_top__DOT__current_process),4);
    bufp->fullBit(oldp+13,(vlSelfRef.scanner_top__DOT__source_status));
    bufp->fullBit(oldp+14,(vlSelfRef.scanner_top__DOT__env_status));
    bufp->fullBit(oldp+15,(vlSelfRef.scanner_top__DOT__cmd_wl_load));
    bufp->fullBit(oldp+16,(vlSelfRef.scanner_top__DOT__cmd_wl_unload));
    bufp->fullBit(oldp+17,(vlSelfRef.scanner_top__DOT__cmd_rl_load));
    bufp->fullBit(oldp+18,(vlSelfRef.scanner_top__DOT__cmd_rl_unload));
    bufp->fullBit(oldp+19,(vlSelfRef.scanner_top__DOT__cmd_ws_calib));
    bufp->fullBit(oldp+20,(vlSelfRef.scanner_top__DOT__cmd_ws_align));
    bufp->fullBit(oldp+21,(vlSelfRef.scanner_top__DOT__cmd_ws_scan));
    bufp->fullBit(oldp+22,(vlSelfRef.scanner_top__DOT__cmd_rs_calib));
    bufp->fullBit(oldp+23,(vlSelfRef.scanner_top__DOT__cmd_rs_scan));
    bufp->fullBit(oldp+24,(vlSelfRef.scanner_top__DOT__cmd_source_active));
    bufp->fullBit(oldp+25,(vlSelfRef.scanner_top__DOT__wl_ready));
    bufp->fullBit(oldp+26,(vlSelfRef.scanner_top__DOT__rl_ready));
    bufp->fullBit(oldp+27,(vlSelfRef.scanner_top__DOT__ws_done));
    bufp->fullBit(oldp+28,(vlSelfRef.scanner_top__DOT__rs_done));
    bufp->fullBit(oldp+29,(vlSelfRef.scanner_top__DOT__env_ok));
    bufp->fullCData(oldp+30,(vlSelfRef.scanner_top__DOT__wafer_index),8);
    bufp->fullBit(oldp+31,(vlSelfRef.scanner_top__DOT__u_handler__DOT__clk));
    bufp->fullBit(oldp+32,(vlSelfRef.scanner_top__DOT__u_handler__DOT__reset));
    bufp->fullBit(oldp+33,(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_wl_load));
    bufp->fullBit(oldp+34,(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_wl_unload));
    bufp->fullBit(oldp+35,(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_rl_load));
    bufp->fullBit(oldp+36,(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_rl_unload));
    bufp->fullBit(oldp+37,(vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_ready));
    bufp->fullBit(oldp+38,(vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_ready));
    bufp->fullCData(oldp+39,(vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_timer),4);
    bufp->fullCData(oldp+40,(vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_timer),4);
    bufp->fullBit(oldp+41,(vlSelfRef.scanner_top__DOT__u_main__DOT__clk));
    bufp->fullBit(oldp+42,(vlSelfRef.scanner_top__DOT__u_main__DOT__reset));
    bufp->fullBit(oldp+43,(vlSelfRef.scanner_top__DOT__u_main__DOT__start_op));
    bufp->fullBit(oldp+44,(vlSelfRef.scanner_top__DOT__u_main__DOT__safety_sensor));
    bufp->fullBit(oldp+45,(vlSelfRef.scanner_top__DOT__u_main__DOT__wl_ready));
    bufp->fullBit(oldp+46,(vlSelfRef.scanner_top__DOT__u_main__DOT__rl_ready));
    bufp->fullBit(oldp+47,(vlSelfRef.scanner_top__DOT__u_main__DOT__ws_done));
    bufp->fullBit(oldp+48,(vlSelfRef.scanner_top__DOT__u_main__DOT__rs_done));
    bufp->fullBit(oldp+49,(vlSelfRef.scanner_top__DOT__u_main__DOT__env_ok));
    bufp->fullBit(oldp+50,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_load));
    bufp->fullBit(oldp+51,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_unload));
    bufp->fullBit(oldp+52,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_load));
    bufp->fullBit(oldp+53,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_unload));
    bufp->fullBit(oldp+54,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_calib));
    bufp->fullBit(oldp+55,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_align));
    bufp->fullBit(oldp+56,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_scan));
    bufp->fullBit(oldp+57,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_calib));
    bufp->fullBit(oldp+58,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_scan));
    bufp->fullBit(oldp+59,(vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_source_active));
    bufp->fullCData(oldp+60,(vlSelfRef.scanner_top__DOT__u_main__DOT__process_state),4);
    bufp->fullCData(oldp+61,(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index),8);
    bufp->fullCData(oldp+62,(vlSelfRef.scanner_top__DOT__u_main__DOT__state),4);
    bufp->fullCData(oldp+63,(vlSelfRef.scanner_top__DOT__u_main__DOT__next_state),4);
    bufp->fullCData(oldp+64,(vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index),8);
    bufp->fullBit(oldp+65,(vlSelfRef.scanner_top__DOT__u_source__DOT__clk));
    bufp->fullBit(oldp+66,(vlSelfRef.scanner_top__DOT__u_source__DOT__reset));
    bufp->fullBit(oldp+67,(vlSelfRef.scanner_top__DOT__u_source__DOT__cmd_source_active));
    bufp->fullBit(oldp+68,(vlSelfRef.scanner_top__DOT__u_source__DOT__source_on));
    bufp->fullBit(oldp+69,(vlSelfRef.scanner_top__DOT__u_source__DOT__env_ok));
    bufp->fullCData(oldp+70,(vlSelfRef.scanner_top__DOT__u_source__DOT__env_timer),4);
    bufp->fullBit(oldp+71,(vlSelfRef.scanner_top__DOT__u_stage__DOT__clk));
    bufp->fullBit(oldp+72,(vlSelfRef.scanner_top__DOT__u_stage__DOT__reset));
    bufp->fullBit(oldp+73,(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_calib));
    bufp->fullBit(oldp+74,(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_align));
    bufp->fullBit(oldp+75,(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_scan));
    bufp->fullBit(oldp+76,(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_rs_calib));
    bufp->fullBit(oldp+77,(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_rs_scan));
    bufp->fullBit(oldp+78,(vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_done));
    bufp->fullBit(oldp+79,(vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_done));
    bufp->fullCData(oldp+80,(vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_timer),5);
    bufp->fullCData(oldp+81,(vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_timer),5);
}
