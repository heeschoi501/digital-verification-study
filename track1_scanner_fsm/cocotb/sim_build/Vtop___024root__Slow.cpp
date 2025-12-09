// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*3:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__IDLE;
constexpr CData/*3:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__ENV_CHECK;
constexpr CData/*3:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__LOAD_RET;
constexpr CData/*3:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__LOAD_WFR;
constexpr CData/*3:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__SETUP;
constexpr CData/*3:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__ALIGN;
constexpr CData/*3:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__EXPOSE;
constexpr CData/*3:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__UNLOAD;
constexpr CData/*3:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__ERROR;
constexpr CData/*7:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__LOT_SIZE_U8;
constexpr IData/*31:0*/ Vtop___024root::scanner_top__DOT__u_main__DOT__LOT_SIZE;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
