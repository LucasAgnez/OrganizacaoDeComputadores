#include "systemc.h"

SC_MODULE(Router) {
	sc_in_clk clock; 

    sc_in<sc_uint<32>> proc_in;
    sc_out<sc_uint<32>> proc_out

    sc_in<sc_uint<32>> north_router_in
    sc_out<sc_uint<32>> north_router_out;
  
	sc_in<sc_uint<32>> south_router_in
    sc_out<sc_uint<32>> south_router_out;
  
	sc_in<sc_uint<32>> east_router_in
    sc_out<sc_uint<32>> east_router_out;
  
	sc_in<sc_uint<32>> west_router_in
    sc_out<sc_uint<32>> west_router_out;
  	
  	IN_C* proc_ic; // input channel
  	sc_signal<sc_uint<32>> p_in;
  	IN_C* n_ic;
 	sc_signal<sc_uint<32>> n_in;
  	IN_C* s_ic;
  	sc_signal<sc_uint<32>> s_in;
  	IN_C* e_ic;
  	sc_signal<sc_uint<32>> e_in;
  	IN_C* w_ic;
  	sc_signal<sc_uint<32>> w_in;
  
  	OUT_C* proc_oc; // output channel
  	OUT_C* n_oc;
  	OUT_C* s_oc;
  	OUT_C* e_oc;
  	OUT_C* w_oc;
  
  
    void input_channel_ini() {
      

    }
  	void output_channel_ini() {

    }

    SC_CTOR(Router) {
      SC_METHOD(input_channel_ini);
        sensitive << clock.pos();
      SC_METHOD(output_channel_ini);
        sensitive << clock.neg();
    }
};
