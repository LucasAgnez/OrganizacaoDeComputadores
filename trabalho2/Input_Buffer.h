#include "systemc.h"

SC_MODULE(Input_Buffer) {
  sc_in_clk clock; 

  sc_in<sc_uint<32>> data_in;
  sc_out<sc_uint<32>> data_out;

  sc_in<sc_uint<1>> wr;
  sc_out<sc_uint<1>> wok;
  sc_in<sc_uint<1>> rd;
  sc_out<sc_uint<1>> rok;

  FIFO* bff;
  
  void exec() {
    if(!bff->is_full()){
      wok.write(1);
    }
    else{
      wok.write(0);
    }
    if(!bff->is_empty()){
      rok.write(1);
    }
    else{
      rok.write(0);
    }
    bff->add(data_in);
    data_out.write(bff->ptr());
  }

  SC_CTOR(Input_Buffer) {
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};