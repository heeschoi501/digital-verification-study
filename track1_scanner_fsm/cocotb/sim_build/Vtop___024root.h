// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(op_start_btn,0,0);
        VL_IN8(interlock_sig,0,0);
        VL_OUT8(current_process,3,0);
        VL_OUT8(source_status,0,0);
        VL_OUT8(env_status,0,0);
        CData/*0:0*/ scanner_top__DOT__clk;
        CData/*0:0*/ scanner_top__DOT__reset;
        CData/*0:0*/ scanner_top__DOT__op_start_btn;
        CData/*0:0*/ scanner_top__DOT__interlock_sig;
        CData/*3:0*/ scanner_top__DOT__current_process;
        CData/*0:0*/ scanner_top__DOT__source_status;
        CData/*0:0*/ scanner_top__DOT__env_status;
        CData/*0:0*/ scanner_top__DOT__cmd_wl_load;
        CData/*0:0*/ scanner_top__DOT__cmd_wl_unload;
        CData/*0:0*/ scanner_top__DOT__cmd_rl_load;
        CData/*0:0*/ scanner_top__DOT__cmd_rl_unload;
        CData/*0:0*/ scanner_top__DOT__cmd_ws_calib;
        CData/*0:0*/ scanner_top__DOT__cmd_ws_align;
        CData/*0:0*/ scanner_top__DOT__cmd_ws_scan;
        CData/*0:0*/ scanner_top__DOT__cmd_rs_calib;
        CData/*0:0*/ scanner_top__DOT__cmd_rs_scan;
        CData/*0:0*/ scanner_top__DOT__cmd_source_active;
        CData/*0:0*/ scanner_top__DOT__wl_ready;
        CData/*0:0*/ scanner_top__DOT__rl_ready;
        CData/*0:0*/ scanner_top__DOT__ws_done;
        CData/*0:0*/ scanner_top__DOT__rs_done;
        CData/*0:0*/ scanner_top__DOT__env_ok;
        CData/*7:0*/ scanner_top__DOT__wafer_index;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__clk;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__reset;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__start_op;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__safety_sensor;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__wl_ready;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__rl_ready;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__ws_done;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__rs_done;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__env_ok;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__cmd_wl_load;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__cmd_wl_unload;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__cmd_rl_load;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__cmd_rl_unload;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__cmd_ws_calib;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__cmd_ws_align;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__cmd_ws_scan;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__cmd_rs_calib;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__cmd_rs_scan;
        CData/*0:0*/ scanner_top__DOT__u_main__DOT__cmd_source_active;
        CData/*3:0*/ scanner_top__DOT__u_main__DOT__process_state;
        CData/*7:0*/ scanner_top__DOT__u_main__DOT__wafer_index;
        CData/*3:0*/ scanner_top__DOT__u_main__DOT__state;
        CData/*3:0*/ scanner_top__DOT__u_main__DOT__next_state;
        CData/*7:0*/ scanner_top__DOT__u_main__DOT__next_wafer_index;
        CData/*0:0*/ scanner_top__DOT__u_handler__DOT__clk;
        CData/*0:0*/ scanner_top__DOT__u_handler__DOT__reset;
        CData/*0:0*/ scanner_top__DOT__u_handler__DOT__cmd_wl_load;
        CData/*0:0*/ scanner_top__DOT__u_handler__DOT__cmd_wl_unload;
        CData/*0:0*/ scanner_top__DOT__u_handler__DOT__cmd_rl_load;
        CData/*0:0*/ scanner_top__DOT__u_handler__DOT__cmd_rl_unload;
        CData/*0:0*/ scanner_top__DOT__u_handler__DOT__wl_ready;
        CData/*0:0*/ scanner_top__DOT__u_handler__DOT__rl_ready;
        CData/*3:0*/ scanner_top__DOT__u_handler__DOT__wl_timer;
        CData/*3:0*/ scanner_top__DOT__u_handler__DOT__rl_timer;
    };
    struct {
        CData/*0:0*/ scanner_top__DOT__u_stage__DOT__clk;
        CData/*0:0*/ scanner_top__DOT__u_stage__DOT__reset;
        CData/*0:0*/ scanner_top__DOT__u_stage__DOT__cmd_ws_calib;
        CData/*0:0*/ scanner_top__DOT__u_stage__DOT__cmd_ws_align;
        CData/*0:0*/ scanner_top__DOT__u_stage__DOT__cmd_ws_scan;
        CData/*0:0*/ scanner_top__DOT__u_stage__DOT__cmd_rs_calib;
        CData/*0:0*/ scanner_top__DOT__u_stage__DOT__cmd_rs_scan;
        CData/*0:0*/ scanner_top__DOT__u_stage__DOT__ws_done;
        CData/*0:0*/ scanner_top__DOT__u_stage__DOT__rs_done;
        CData/*4:0*/ scanner_top__DOT__u_stage__DOT__ws_timer;
        CData/*4:0*/ scanner_top__DOT__u_stage__DOT__rs_timer;
        CData/*0:0*/ scanner_top__DOT__u_source__DOT__clk;
        CData/*0:0*/ scanner_top__DOT__u_source__DOT__reset;
        CData/*0:0*/ scanner_top__DOT__u_source__DOT__cmd_source_active;
        CData/*0:0*/ scanner_top__DOT__u_source__DOT__source_on;
        CData/*0:0*/ scanner_top__DOT__u_source__DOT__env_ok;
        CData/*3:0*/ scanner_top__DOT__u_source__DOT__env_timer;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__scanner_top__DOT__u_main__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__scanner_top__DOT__u_main__DOT__reset__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__scanner_top__DOT__u_handler__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__scanner_top__DOT__u_handler__DOT__reset__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__scanner_top__DOT__u_stage__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__scanner_top__DOT__u_stage__DOT__reset__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__scanner_top__DOT__u_source__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__scanner_top__DOT__u_source__DOT__reset__0;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*3:0*/ scanner_top__DOT__u_main__DOT__IDLE = 0U;
    static constexpr CData/*3:0*/ scanner_top__DOT__u_main__DOT__ENV_CHECK = 1U;
    static constexpr CData/*3:0*/ scanner_top__DOT__u_main__DOT__LOAD_RET = 2U;
    static constexpr CData/*3:0*/ scanner_top__DOT__u_main__DOT__LOAD_WFR = 3U;
    static constexpr CData/*3:0*/ scanner_top__DOT__u_main__DOT__SETUP = 4U;
    static constexpr CData/*3:0*/ scanner_top__DOT__u_main__DOT__ALIGN = 5U;
    static constexpr CData/*3:0*/ scanner_top__DOT__u_main__DOT__EXPOSE = 6U;
    static constexpr CData/*3:0*/ scanner_top__DOT__u_main__DOT__UNLOAD = 7U;
    static constexpr CData/*3:0*/ scanner_top__DOT__u_main__DOT__ERROR = 0x0fU;
    static constexpr CData/*7:0*/ scanner_top__DOT__u_main__DOT__LOT_SIZE_U8 = 0x19U;
    static constexpr IData/*31:0*/ scanner_top__DOT__u_main__DOT__LOT_SIZE = 0x00000019U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
