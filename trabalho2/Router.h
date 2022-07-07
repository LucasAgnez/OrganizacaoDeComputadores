#include "Input_Channel.h"
#include "Output_Channel.h"

SC_MODULE(Router) {
	sc_in_clk clock; 


  sc_in<sc_uint<32>> north_data_in
  sc_out<sc_uint<32>> north_data_out;
  
  Input_Channel* n_ic;  
  Output_Channel* n_oc;

  sc_in<sc_uint<32>> south_data_in
  sc_out<sc_uint<32>> south_data_out;
  Input_Channel* s_ic;
  Output_Channel* s_oc;

  sc_in<sc_uint<32>> east_data_in
  sc_out<sc_uint<32>> east_data_out;
  Input_Channel* e_ic;
  Output_Channel* e_oc;

  sc_in<sc_uint<32>> west_data_in
  sc_out<sc_uint<32>> west_data_out;
  Input_Channel* w_ic;
  Output_Channel* w_oc;

  sc_in<sc_uint<32>> local_data_in
  sc_out<sc_uint<32>> local_data_out;
  Input_Channel* l_ic;
  Output_Channel* l_oc;

  void input_channel_ini() {
    

  }
  void output_channel_ini() {

  }

  SC_CTOR(Router) {
    input_channel_ini();
    output_channel_ini();
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};