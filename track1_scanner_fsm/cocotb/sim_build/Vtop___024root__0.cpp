// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.scanner_top__DOT__wafer_index = vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index;
    vlSelfRef.scanner_top__DOT__current_process = vlSelfRef.scanner_top__DOT__u_main__DOT__process_state;
    vlSelfRef.scanner_top__DOT__source_status = vlSelfRef.scanner_top__DOT__u_source__DOT__source_on;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_align = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_load = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_unload = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_load = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_calib = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_scan = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_calib = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_scan = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_source_active = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_unload = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_align = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state)))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_calib = 1U;
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_calib = 1U;
                }
            }
            if ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_unload = 1U;
                    if ((0x18U == (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index))) {
                        vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_unload = 1U;
                    }
                }
                if ((1U & (~ (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state)))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_scan = 1U;
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_scan = 1U;
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_source_active = 1U;
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_load = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state)))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_load = 1U;
                }
            }
        }
    }
    vlSelfRef.scanner_top__DOT__clk = vlSelfRef.clk;
    vlSelfRef.scanner_top__DOT__reset = vlSelfRef.reset;
    vlSelfRef.scanner_top__DOT__rs_done = vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_done;
    vlSelfRef.scanner_top__DOT__interlock_sig = vlSelfRef.interlock_sig;
    vlSelfRef.scanner_top__DOT__op_start_btn = vlSelfRef.op_start_btn;
    vlSelfRef.scanner_top__DOT__ws_done = vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_done;
    vlSelfRef.scanner_top__DOT__rl_ready = vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_ready;
    vlSelfRef.scanner_top__DOT__wl_ready = vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_ready;
    vlSelfRef.scanner_top__DOT__env_ok = vlSelfRef.scanner_top__DOT__u_source__DOT__env_ok;
    vlSelfRef.current_process = vlSelfRef.scanner_top__DOT__current_process;
    vlSelfRef.source_status = vlSelfRef.scanner_top__DOT__source_status;
    vlSelfRef.scanner_top__DOT__cmd_ws_align = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_align;
    vlSelfRef.scanner_top__DOT__cmd_wl_load = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_load;
    vlSelfRef.scanner_top__DOT__cmd_wl_unload = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_unload;
    vlSelfRef.scanner_top__DOT__cmd_rl_load = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_load;
    vlSelfRef.scanner_top__DOT__cmd_ws_calib = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_calib;
    vlSelfRef.scanner_top__DOT__cmd_ws_scan = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_scan;
    vlSelfRef.scanner_top__DOT__cmd_rs_calib = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_calib;
    vlSelfRef.scanner_top__DOT__cmd_rs_scan = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_scan;
    vlSelfRef.scanner_top__DOT__cmd_source_active = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_source_active;
    vlSelfRef.scanner_top__DOT__cmd_rl_unload = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_unload;
    vlSelfRef.scanner_top__DOT__u_main__DOT__clk = vlSelfRef.scanner_top__DOT__clk;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__clk 
        = vlSelfRef.scanner_top__DOT__clk;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__clk = vlSelfRef.scanner_top__DOT__clk;
    vlSelfRef.scanner_top__DOT__u_source__DOT__clk 
        = vlSelfRef.scanner_top__DOT__clk;
    vlSelfRef.scanner_top__DOT__u_main__DOT__reset 
        = vlSelfRef.scanner_top__DOT__reset;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__reset 
        = vlSelfRef.scanner_top__DOT__reset;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__reset 
        = vlSelfRef.scanner_top__DOT__reset;
    vlSelfRef.scanner_top__DOT__u_source__DOT__reset 
        = vlSelfRef.scanner_top__DOT__reset;
    vlSelfRef.scanner_top__DOT__u_main__DOT__rs_done 
        = vlSelfRef.scanner_top__DOT__rs_done;
    vlSelfRef.scanner_top__DOT__u_main__DOT__safety_sensor 
        = vlSelfRef.scanner_top__DOT__interlock_sig;
    vlSelfRef.scanner_top__DOT__u_main__DOT__start_op 
        = vlSelfRef.scanner_top__DOT__op_start_btn;
    vlSelfRef.scanner_top__DOT__u_main__DOT__ws_done 
        = vlSelfRef.scanner_top__DOT__ws_done;
    vlSelfRef.scanner_top__DOT__u_main__DOT__rl_ready 
        = vlSelfRef.scanner_top__DOT__rl_ready;
    vlSelfRef.scanner_top__DOT__u_main__DOT__wl_ready 
        = vlSelfRef.scanner_top__DOT__wl_ready;
    vlSelfRef.scanner_top__DOT__env_status = vlSelfRef.scanner_top__DOT__env_ok;
    vlSelfRef.scanner_top__DOT__u_main__DOT__env_ok 
        = vlSelfRef.scanner_top__DOT__env_ok;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_align 
        = vlSelfRef.scanner_top__DOT__cmd_ws_align;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_wl_load 
        = vlSelfRef.scanner_top__DOT__cmd_wl_load;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_wl_unload 
        = vlSelfRef.scanner_top__DOT__cmd_wl_unload;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_rl_load 
        = vlSelfRef.scanner_top__DOT__cmd_rl_load;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_calib 
        = vlSelfRef.scanner_top__DOT__cmd_ws_calib;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_scan 
        = vlSelfRef.scanner_top__DOT__cmd_ws_scan;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_rs_calib 
        = vlSelfRef.scanner_top__DOT__cmd_rs_calib;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_rs_scan 
        = vlSelfRef.scanner_top__DOT__cmd_rs_scan;
    vlSelfRef.scanner_top__DOT__u_source__DOT__cmd_source_active 
        = vlSelfRef.scanner_top__DOT__cmd_source_active;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_rl_unload 
        = vlSelfRef.scanner_top__DOT__cmd_rl_unload;
    vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index 
        = vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index;
    vlSelfRef.env_status = vlSelfRef.scanner_top__DOT__env_status;
    vlSelfRef.scanner_top__DOT__u_main__DOT__next_state 
        = vlSelfRef.scanner_top__DOT__u_main__DOT__state;
    if ((8U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
        if ((4U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index 
                        = vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index;
                    vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 0x0fU;
                } else {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index = 0U;
                    vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 0U;
                }
            } else {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index = 0U;
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 0U;
            }
        } else {
            vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index = 0U;
            vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
        if ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                if (((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wl_ready) 
                     & (((0x18U == (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index)) 
                         & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__rl_ready)) 
                        | (0x18U != (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index))))) {
                    if ((0x18U == (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index))) {
                        vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index = 0U;
                        vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 0U;
                    } else {
                        vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index 
                            = (0x000000ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index)));
                        vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 3U;
                    }
                }
            } else if (vlSelfRef.scanner_top__DOT__u_main__DOT__safety_sensor) {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 0x0fU;
            } else if (((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__ws_done) 
                        & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__rs_done))) {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 7U;
            }
        } else if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if (vlSelfRef.scanner_top__DOT__u_main__DOT__ws_done) {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 6U;
            }
        } else if (((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__ws_done) 
                    & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__rs_done))) {
            vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 5U;
        }
    } else {
        if ((1U & (~ ((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state)))) {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index = 0U;
            }
        }
        if ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                if (vlSelfRef.scanner_top__DOT__u_main__DOT__wl_ready) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 4U;
                }
            } else if (vlSelfRef.scanner_top__DOT__u_main__DOT__rl_ready) {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if (vlSelfRef.scanner_top__DOT__u_main__DOT__env_ok) {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 2U;
            }
        } else if (vlSelfRef.scanner_top__DOT__u_main__DOT__start_op) {
            vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 1U;
        }
    }
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((((IData)(vlSelfRef.scanner_top__DOT__u_source__DOT__reset) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_source__DOT__reset__0))) 
                                                         << 3U) 
                                                        | (((IData)(vlSelfRef.scanner_top__DOT__u_source__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_source__DOT__clk__0))) 
                                                           << 2U)) 
                                                       | ((((IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__reset) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_stage__DOT__reset__0))) 
                                                           << 1U) 
                                                          | ((IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_stage__DOT__clk__0))))) 
                                                      << 4U) 
                                                     | (((((IData)(vlSelfRef.scanner_top__DOT__u_handler__DOT__reset) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_handler__DOT__reset__0))) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.scanner_top__DOT__u_handler__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_handler__DOT__clk__0))) 
                                                            << 2U)) 
                                                        | ((((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__reset) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_main__DOT__reset__0))) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_main__DOT__clk__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_main__DOT__clk__0 
        = vlSelfRef.scanner_top__DOT__u_main__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_main__DOT__reset__0 
        = vlSelfRef.scanner_top__DOT__u_main__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_handler__DOT__clk__0 
        = vlSelfRef.scanner_top__DOT__u_handler__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_handler__DOT__reset__0 
        = vlSelfRef.scanner_top__DOT__u_handler__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_stage__DOT__clk__0 
        = vlSelfRef.scanner_top__DOT__u_stage__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_stage__DOT__reset__0 
        = vlSelfRef.scanner_top__DOT__u_stage__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_source__DOT__clk__0 
        = vlSelfRef.scanner_top__DOT__u_source__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__scanner_top__DOT__u_source__DOT__reset__0 
        = vlSelfRef.scanner_top__DOT__u_source__DOT__reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vdly__scanner_top__DOT__u_stage__DOT__ws_timer;
    __Vdly__scanner_top__DOT__u_stage__DOT__ws_timer = 0;
    CData/*4:0*/ __Vdly__scanner_top__DOT__u_stage__DOT__rs_timer;
    __Vdly__scanner_top__DOT__u_stage__DOT__rs_timer = 0;
    // Body
    __Vdly__scanner_top__DOT__u_stage__DOT__rs_timer 
        = vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_timer;
    __Vdly__scanner_top__DOT__u_stage__DOT__ws_timer 
        = vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_timer;
    if (vlSelfRef.scanner_top__DOT__u_stage__DOT__reset) {
        vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_done = 0U;
        __Vdly__scanner_top__DOT__u_stage__DOT__rs_timer = 0U;
        vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_done = 0U;
        __Vdly__scanner_top__DOT__u_stage__DOT__ws_timer = 0U;
    } else {
        if (((IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_rs_calib) 
             | (IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_rs_scan))) {
            if ((6U > (IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_timer))) {
                __Vdly__scanner_top__DOT__u_stage__DOT__rs_timer 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_timer)));
                vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_done = 0U;
            } else {
                vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_done = 1U;
            }
        } else {
            vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_done = 0U;
            __Vdly__scanner_top__DOT__u_stage__DOT__rs_timer = 0U;
        }
        if ((((IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_calib) 
              | (IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_align)) 
             | (IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_scan))) {
            if ((6U > (IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_timer))) {
                __Vdly__scanner_top__DOT__u_stage__DOT__ws_timer 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_timer)));
                vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_done = 0U;
            } else {
                vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_done = 1U;
            }
        } else {
            vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_done = 0U;
            __Vdly__scanner_top__DOT__u_stage__DOT__ws_timer = 0U;
        }
    }
    vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_timer 
        = __Vdly__scanner_top__DOT__u_stage__DOT__rs_timer;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_timer 
        = __Vdly__scanner_top__DOT__u_stage__DOT__ws_timer;
    vlSelfRef.scanner_top__DOT__rs_done = vlSelfRef.scanner_top__DOT__u_stage__DOT__rs_done;
    vlSelfRef.scanner_top__DOT__ws_done = vlSelfRef.scanner_top__DOT__u_stage__DOT__ws_done;
    vlSelfRef.scanner_top__DOT__u_main__DOT__rs_done 
        = vlSelfRef.scanner_top__DOT__rs_done;
    vlSelfRef.scanner_top__DOT__u_main__DOT__ws_done 
        = vlSelfRef.scanner_top__DOT__ws_done;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__scanner_top__DOT__u_handler__DOT__wl_timer;
    __Vdly__scanner_top__DOT__u_handler__DOT__wl_timer = 0;
    CData/*3:0*/ __Vdly__scanner_top__DOT__u_handler__DOT__rl_timer;
    __Vdly__scanner_top__DOT__u_handler__DOT__rl_timer = 0;
    // Body
    __Vdly__scanner_top__DOT__u_handler__DOT__wl_timer 
        = vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_timer;
    __Vdly__scanner_top__DOT__u_handler__DOT__rl_timer 
        = vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_timer;
    if (vlSelfRef.scanner_top__DOT__u_handler__DOT__reset) {
        vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_ready = 0U;
        __Vdly__scanner_top__DOT__u_handler__DOT__wl_timer = 0U;
        vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_ready = 0U;
        __Vdly__scanner_top__DOT__u_handler__DOT__rl_timer = 0U;
    } else {
        if (((IData)(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_wl_load) 
             | (IData)(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_wl_unload))) {
            if ((4U > (IData)(vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_timer))) {
                __Vdly__scanner_top__DOT__u_handler__DOT__wl_timer 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_timer)));
                vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_ready = 0U;
            } else {
                vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_ready = 1U;
            }
        } else {
            vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_ready = 0U;
            __Vdly__scanner_top__DOT__u_handler__DOT__wl_timer = 0U;
        }
        if (((IData)(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_rl_load) 
             | (IData)(vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_rl_unload))) {
            if ((3U > (IData)(vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_timer))) {
                __Vdly__scanner_top__DOT__u_handler__DOT__rl_timer 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_timer)));
                vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_ready = 0U;
            } else {
                vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_ready = 1U;
            }
        } else {
            vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_ready = 0U;
            __Vdly__scanner_top__DOT__u_handler__DOT__rl_timer = 0U;
        }
    }
    vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_timer 
        = __Vdly__scanner_top__DOT__u_handler__DOT__wl_timer;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_timer 
        = __Vdly__scanner_top__DOT__u_handler__DOT__rl_timer;
    vlSelfRef.scanner_top__DOT__wl_ready = vlSelfRef.scanner_top__DOT__u_handler__DOT__wl_ready;
    vlSelfRef.scanner_top__DOT__rl_ready = vlSelfRef.scanner_top__DOT__u_handler__DOT__rl_ready;
    vlSelfRef.scanner_top__DOT__u_main__DOT__wl_ready 
        = vlSelfRef.scanner_top__DOT__wl_ready;
    vlSelfRef.scanner_top__DOT__u_main__DOT__rl_ready 
        = vlSelfRef.scanner_top__DOT__rl_ready;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vdly__scanner_top__DOT__u_source__DOT__env_ok;
    __Vdly__scanner_top__DOT__u_source__DOT__env_ok = 0;
    CData/*3:0*/ __Vdly__scanner_top__DOT__u_source__DOT__env_timer;
    __Vdly__scanner_top__DOT__u_source__DOT__env_timer = 0;
    // Body
    __Vdly__scanner_top__DOT__u_source__DOT__env_timer 
        = vlSelfRef.scanner_top__DOT__u_source__DOT__env_timer;
    __Vdly__scanner_top__DOT__u_source__DOT__env_ok 
        = vlSelfRef.scanner_top__DOT__u_source__DOT__env_ok;
    if (vlSelfRef.scanner_top__DOT__u_source__DOT__reset) {
        __Vdly__scanner_top__DOT__u_source__DOT__env_ok = 0U;
        __Vdly__scanner_top__DOT__u_source__DOT__env_timer = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.scanner_top__DOT__u_source__DOT__env_ok)))) {
        if ((0x0aU > (IData)(vlSelfRef.scanner_top__DOT__u_source__DOT__env_timer))) {
            __Vdly__scanner_top__DOT__u_source__DOT__env_timer 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.scanner_top__DOT__u_source__DOT__env_timer)));
        } else {
            __Vdly__scanner_top__DOT__u_source__DOT__env_ok = 1U;
        }
    }
    vlSelfRef.scanner_top__DOT__u_source__DOT__source_on 
        = ((1U & (~ (IData)(vlSelfRef.scanner_top__DOT__u_source__DOT__reset))) 
           && ((IData)(vlSelfRef.scanner_top__DOT__u_source__DOT__cmd_source_active) 
               & (IData)(vlSelfRef.scanner_top__DOT__u_source__DOT__env_ok)));
    vlSelfRef.scanner_top__DOT__u_source__DOT__env_timer 
        = __Vdly__scanner_top__DOT__u_source__DOT__env_timer;
    vlSelfRef.scanner_top__DOT__u_source__DOT__env_ok 
        = __Vdly__scanner_top__DOT__u_source__DOT__env_ok;
    vlSelfRef.scanner_top__DOT__source_status = vlSelfRef.scanner_top__DOT__u_source__DOT__source_on;
    vlSelfRef.scanner_top__DOT__env_ok = vlSelfRef.scanner_top__DOT__u_source__DOT__env_ok;
    vlSelfRef.source_status = vlSelfRef.scanner_top__DOT__source_status;
    vlSelfRef.scanner_top__DOT__env_status = vlSelfRef.scanner_top__DOT__env_ok;
    vlSelfRef.scanner_top__DOT__u_main__DOT__env_ok 
        = vlSelfRef.scanner_top__DOT__env_ok;
    vlSelfRef.env_status = vlSelfRef.scanner_top__DOT__env_status;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.scanner_top__DOT__u_main__DOT__reset) {
        vlSelfRef.scanner_top__DOT__u_main__DOT__process_state = 0U;
        vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index = 0U;
        vlSelfRef.scanner_top__DOT__u_main__DOT__state = 0U;
    } else {
        vlSelfRef.scanner_top__DOT__u_main__DOT__process_state 
            = vlSelfRef.scanner_top__DOT__u_main__DOT__next_state;
        vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index 
            = vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index;
        vlSelfRef.scanner_top__DOT__u_main__DOT__state 
            = vlSelfRef.scanner_top__DOT__u_main__DOT__next_state;
    }
    vlSelfRef.scanner_top__DOT__current_process = vlSelfRef.scanner_top__DOT__u_main__DOT__process_state;
    vlSelfRef.scanner_top__DOT__wafer_index = vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_align = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_load = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_unload = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_load = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_calib = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_scan = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_calib = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_scan = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_source_active = 0U;
    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_unload = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_align = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state)))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_calib = 1U;
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_calib = 1U;
                }
            }
            if ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_unload = 1U;
                    if ((0x18U == (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index))) {
                        vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_unload = 1U;
                    }
                }
                if ((1U & (~ (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state)))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_scan = 1U;
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_scan = 1U;
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_source_active = 1U;
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_load = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state)))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_load = 1U;
                }
            }
        }
    }
    vlSelfRef.current_process = vlSelfRef.scanner_top__DOT__current_process;
    vlSelfRef.scanner_top__DOT__cmd_ws_align = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_align;
    vlSelfRef.scanner_top__DOT__cmd_wl_load = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_load;
    vlSelfRef.scanner_top__DOT__cmd_wl_unload = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_wl_unload;
    vlSelfRef.scanner_top__DOT__cmd_rl_load = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_load;
    vlSelfRef.scanner_top__DOT__cmd_ws_calib = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_calib;
    vlSelfRef.scanner_top__DOT__cmd_ws_scan = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_ws_scan;
    vlSelfRef.scanner_top__DOT__cmd_rs_calib = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_calib;
    vlSelfRef.scanner_top__DOT__cmd_rs_scan = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rs_scan;
    vlSelfRef.scanner_top__DOT__cmd_source_active = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_source_active;
    vlSelfRef.scanner_top__DOT__cmd_rl_unload = vlSelfRef.scanner_top__DOT__u_main__DOT__cmd_rl_unload;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_align 
        = vlSelfRef.scanner_top__DOT__cmd_ws_align;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_wl_load 
        = vlSelfRef.scanner_top__DOT__cmd_wl_load;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_wl_unload 
        = vlSelfRef.scanner_top__DOT__cmd_wl_unload;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_rl_load 
        = vlSelfRef.scanner_top__DOT__cmd_rl_load;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_calib 
        = vlSelfRef.scanner_top__DOT__cmd_ws_calib;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_ws_scan 
        = vlSelfRef.scanner_top__DOT__cmd_ws_scan;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_rs_calib 
        = vlSelfRef.scanner_top__DOT__cmd_rs_calib;
    vlSelfRef.scanner_top__DOT__u_stage__DOT__cmd_rs_scan 
        = vlSelfRef.scanner_top__DOT__cmd_rs_scan;
    vlSelfRef.scanner_top__DOT__u_source__DOT__cmd_source_active 
        = vlSelfRef.scanner_top__DOT__cmd_source_active;
    vlSelfRef.scanner_top__DOT__u_handler__DOT__cmd_rl_unload 
        = vlSelfRef.scanner_top__DOT__cmd_rl_unload;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index 
        = vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index;
    if ((8U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
        vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index 
            = ((4U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))
                ? ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))
                    ? ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))
                        ? (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index)
                        : 0U) : 0U) : 0U);
    } else if ((4U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
        if ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                if (((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wl_ready) 
                     & (((0x18U == (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index)) 
                         & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__rl_ready)) 
                        | (0x18U != (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index))))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index 
                        = ((0x18U == (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index))
                            ? 0U : (0x000000ffU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index))));
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state) 
                         >> 1U)))) {
        if ((1U & (~ (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state)))) {
            vlSelfRef.scanner_top__DOT__u_main__DOT__next_wafer_index = 0U;
        }
    }
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.scanner_top__DOT__u_main__DOT__next_state 
        = vlSelfRef.scanner_top__DOT__u_main__DOT__state;
    if ((8U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
        vlSelfRef.scanner_top__DOT__u_main__DOT__next_state 
            = ((4U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))
                ? ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))
                    ? ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))
                        ? 0x0fU : 0U) : 0U) : 0U);
    } else if ((4U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
        if ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
                if (((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wl_ready) 
                     & (((0x18U == (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index)) 
                         & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__rl_ready)) 
                        | (0x18U != (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index))))) {
                    vlSelfRef.scanner_top__DOT__u_main__DOT__next_state 
                        = ((0x18U == (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__wafer_index))
                            ? 0U : 3U);
                }
            } else if (vlSelfRef.scanner_top__DOT__u_main__DOT__safety_sensor) {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 0x0fU;
            } else if (((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__ws_done) 
                        & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__rs_done))) {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 7U;
            }
        } else if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if (vlSelfRef.scanner_top__DOT__u_main__DOT__ws_done) {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 6U;
            }
        } else if (((IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__ws_done) 
                    & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__rs_done))) {
            vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 5U;
        }
    } else if ((2U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
            if (vlSelfRef.scanner_top__DOT__u_main__DOT__wl_ready) {
                vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 4U;
            }
        } else if (vlSelfRef.scanner_top__DOT__u_main__DOT__rl_ready) {
            vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.scanner_top__DOT__u_main__DOT__state))) {
        if (vlSelfRef.scanner_top__DOT__u_main__DOT__env_ok) {
            vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 2U;
        }
    } else if (vlSelfRef.scanner_top__DOT__u_main__DOT__start_op) {
        vlSelfRef.scanner_top__DOT__u_main__DOT__next_state = 1U;
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x00000000000000ffULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../src/scanner_top.v", 6, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../src/scanner_top.v", 6, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../src/scanner_top.v", 6, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.op_start_btn & 0xfeU)))) {
        Verilated::overWidthError("op_start_btn");
    }
    if (VL_UNLIKELY(((vlSelfRef.interlock_sig & 0xfeU)))) {
        Verilated::overWidthError("interlock_sig");
    }
}
#endif  // VL_DEBUG
