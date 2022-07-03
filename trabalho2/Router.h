#include "Input_Channel.h"
#include "Output_Channel.h"

SC_MODULE(Router) {
	sc_in_clk clock; 


    sc_in<sc_uint<32>> north_router_in
    sc_out<sc_uint<32>> north_router_out;
  
   // input channel
  	sc_signal<sc_uint<32>> p_in;
  	Input_Channel* n_ic;

    // output channel
  	Output_Channel* n_oc;

  
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