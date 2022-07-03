#include "systemc.h"

SC_MODULE(FIFO) {
  sc_in_clk clock; 

  sc_in<sc_uint<32>> data_in;
  sc_out<sc_uint<32>> data_out;

  sc_in<sc_uint<1>> wr;
  sc_out<sc_uint<1>> wok;
  sc_in<sc_uint<1>> rd;
  sc_out<sc_uint<1>> rok;

  FIFO* bff;
  
  void exec() {

  }

  SC_CTOR(FIFO) {
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};