// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("scanner_top.vcd"s);
    vlSymsp->_traceDumpOpen();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../src/scanner_top.v", 6, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge scanner_top.u_main.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge scanner_top.u_main.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge scanner_top.u_handler.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge scanner_top.u_handler.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge scanner_top.u_stage.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge scanner_top.u_stage.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(posedge scanner_top.u_source.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(posedge scanner_top.u_source.reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->op_start_btn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14022001860268090730ull);
    vlSelf->interlock_sig = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15931817829965606199ull);
    vlSelf->current_process = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4654458854529506669ull);
    vlSelf->source_status = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12746689601662868919ull);
    vlSelf->env_status = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9710792360509017005ull);
    vlSelf->scanner_top__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12812947826236067141ull);
    vlSelf->scanner_top__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15650801594345044818ull);
    vlSelf->scanner_top__DOT__op_start_btn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14952902326799095939ull);
    vlSelf->scanner_top__DOT__interlock_sig = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7926700989753975234ull);
    vlSelf->scanner_top__DOT__current_process = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11618354724688437399ull);
    vlSelf->scanner_top__DOT__source_status = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1037527027228058965ull);
    vlSelf->scanner_top__DOT__env_status = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8729508578537786447ull);
    vlSelf->scanner_top__DOT__cmd_wl_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12154276803230229555ull);
    vlSelf->scanner_top__DOT__cmd_wl_unload = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13550767882170353556ull);
    vlSelf->scanner_top__DOT__cmd_rl_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7453121866028275886ull);
    vlSelf->scanner_top__DOT__cmd_rl_unload = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2292108196773014325ull);
    vlSelf->scanner_top__DOT__cmd_ws_calib = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16404514474263911920ull);
    vlSelf->scanner_top__DOT__cmd_ws_align = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14330276494574886046ull);
    vlSelf->scanner_top__DOT__cmd_ws_scan = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13411725919856024798ull);
    vlSelf->scanner_top__DOT__cmd_rs_calib = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12635405847460322351ull);
    vlSelf->scanner_top__DOT__cmd_rs_scan = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8352157558362484214ull);
    vlSelf->scanner_top__DOT__cmd_source_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 571562491387769639ull);
    vlSelf->scanner_top__DOT__wl_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5592030771044281575ull);
    vlSelf->scanner_top__DOT__rl_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14682225730256336371ull);
    vlSelf->scanner_top__DOT__ws_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1361286664518995620ull);
    vlSelf->scanner_top__DOT__rs_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18141249669600236841ull);
    vlSelf->scanner_top__DOT__env_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1502841128348960934ull);
    vlSelf->scanner_top__DOT__wafer_index = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10813528689803300710ull);
    vlSelf->scanner_top__DOT__u_main__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16152701881262836679ull);
    vlSelf->scanner_top__DOT__u_main__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16197335308101510550ull);
    vlSelf->scanner_top__DOT__u_main__DOT__start_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9221967417679729333ull);
    vlSelf->scanner_top__DOT__u_main__DOT__safety_sensor = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3157338006077638137ull);
    vlSelf->scanner_top__DOT__u_main__DOT__wl_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14759458685595694597ull);
    vlSelf->scanner_top__DOT__u_main__DOT__rl_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16261732233659929690ull);
    vlSelf->scanner_top__DOT__u_main__DOT__ws_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15043741913488984072ull);
    vlSelf->scanner_top__DOT__u_main__DOT__rs_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2910353522992525162ull);
    vlSelf->scanner_top__DOT__u_main__DOT__env_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 221238033717169482ull);
    vlSelf->scanner_top__DOT__u_main__DOT__cmd_wl_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13629249251345213255ull);
    vlSelf->scanner_top__DOT__u_main__DOT__cmd_wl_unload = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10977256095470001500ull);
    vlSelf->scanner_top__DOT__u_main__DOT__cmd_rl_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13686084585302483729ull);
    vlSelf->scanner_top__DOT__u_main__DOT__cmd_rl_unload = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8121306799536669652ull);
    vlSelf->scanner_top__DOT__u_main__DOT__cmd_ws_calib = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9891827718823144826ull);
    vlSelf->scanner_top__DOT__u_main__DOT__cmd_ws_align = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8230121965310979298ull);
    vlSelf->scanner_top__DOT__u_main__DOT__cmd_ws_scan = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2384080925905102725ull);
    vlSelf->scanner_top__DOT__u_main__DOT__cmd_rs_calib = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10668499796653069486ull);
    vlSelf->scanner_top__DOT__u_main__DOT__cmd_rs_scan = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7046444171189871587ull);
    vlSelf->scanner_top__DOT__u_main__DOT__cmd_source_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10788076406655342419ull);
    vlSelf->scanner_top__DOT__u_main__DOT__process_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6951035311606011558ull);
    vlSelf->scanner_top__DOT__u_main__DOT__wafer_index = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2586858794726645195ull);
    vlSelf->scanner_top__DOT__u_main__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1722897584519879004ull);
    vlSelf->scanner_top__DOT__u_main__DOT__next_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14097626170147389682ull);
    vlSelf->scanner_top__DOT__u_main__DOT__next_wafer_index = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7060288824188260116ull);
    vlSelf->scanner_top__DOT__u_handler__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15308949665557849330ull);
    vlSelf->scanner_top__DOT__u_handler__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9168734954613736520ull);
    vlSelf->scanner_top__DOT__u_handler__DOT__cmd_wl_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6210296152861960393ull);
    vlSelf->scanner_top__DOT__u_handler__DOT__cmd_wl_unload = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6514053315704305434ull);
    vlSelf->scanner_top__DOT__u_handler__DOT__cmd_rl_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9539006482866376323ull);
    vlSelf->scanner_top__DOT__u_handler__DOT__cmd_rl_unload = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5923404467494210899ull);
    vlSelf->scanner_top__DOT__u_handler__DOT__wl_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9961942506849667619ull);
    vlSelf->scanner_top__DOT__u_handler__DOT__rl_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3838908290555836084ull);
    vlSelf->scanner_top__DOT__u_handler__DOT__wl_timer = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11855382992723595187ull);
    vlSelf->scanner_top__DOT__u_handler__DOT__rl_timer = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16817178547037045927ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5888769410840019179ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9250486754618249001ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__cmd_ws_calib = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18151488437370596723ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__cmd_ws_align = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15491756099611104321ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__cmd_ws_scan = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16091263707718665786ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__cmd_rs_calib = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17801359101770092717ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__cmd_rs_scan = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4420175975912318083ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__ws_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6042512207799070228ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__rs_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1771281421227035355ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__ws_timer = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4169406267843681490ull);
    vlSelf->scanner_top__DOT__u_stage__DOT__rs_timer = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5416517944513683699ull);
    vlSelf->scanner_top__DOT__u_source__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18245268581967676010ull);
    vlSelf->scanner_top__DOT__u_source__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13682177493270333422ull);
    vlSelf->scanner_top__DOT__u_source__DOT__cmd_source_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16284947236312540298ull);
    vlSelf->scanner_top__DOT__u_source__DOT__source_on = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5514776509761162578ull);
    vlSelf->scanner_top__DOT__u_source__DOT__env_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8821904672137373552ull);
    vlSelf->scanner_top__DOT__u_source__DOT__env_timer = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8027847163153866221ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__scanner_top__DOT__u_main__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__scanner_top__DOT__u_main__DOT__reset__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__scanner_top__DOT__u_handler__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__scanner_top__DOT__u_handler__DOT__reset__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__scanner_top__DOT__u_stage__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__scanner_top__DOT__u_stage__DOT__reset__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__scanner_top__DOT__u_source__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__scanner_top__DOT__u_source__DOT__reset__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
