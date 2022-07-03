#include "systemc.h"

SC_MODULE(Output_Data_Switch) {
  sc_in_clk clock; 

  sc_in<sc_uint<32>> n_data;
  sc_in<sc_uint<32>> s_data;
  sc_in<sc_uint<32>> e_data;
  sc_in<sc_uint<32>> w_data;
  sc_in<sc_uint<32>> c_data;


  sc_out<sc_uint<32>> data_out;
  
  sc_in<sc_uint<1>> north;
  sc_in<sc_uint<1>> south;
  sc_in<sc_uint<1>> east;
  sc_in<sc_uint<1>> west;
  sc_in<sc_uint<1>> core;

  void choose_out() {
    if (north.read() == 1){
      data_out.write(n_data);
    }
    else if (south.read() == 1){
      data_out.write(s_data);
    }
    else if (east.read() == 1){
      data_out.write(e_data);
    }
    else if (west.read() == 1){
      data_out.write(w_data);
    }
    else if (core.read() == 1){
      data_out.write(c_data);
    }
  }
    

  SC_CTOR(Output_Data_Switch) {
    SC_METHOD(choose_out);
      sensitive << clock.pos();
  }
};