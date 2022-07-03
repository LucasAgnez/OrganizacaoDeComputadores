#include "systemc.h"

SC_MODULE(Input_Channel) {
  sc_in_clk clock; 

  sc_in<sc_uint<32>> data;

  sc_in<sc_uint<1>> val;
  sc_out<sc_uint<1>> ack;

  sc_out<sc_uint<32>> data_out;
  sc_out<sc_uint<1>> north;
  sc_out<sc_uint<1>> south;
  sc_out<sc_uint<1>> east;
  sc_out<sc_uint<1>> west;
  
  sc_out<sc_uint<1>> core;
  
    

  SC_CTOR(Input_Channel) {
    SC_METHOD(do_write);
      sensitive << clock.pos();
  }
};