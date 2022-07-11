#include "systemc.h"

SC_MODULE(Input_Buffer) {
  sc_in_clk clock; 

  sc_in<sc_uint<32>> data_in;
  sc_out<sc_uint<32>> data_out;

  sc_in<sc_uint<1>> wr;
  sc_out<sc_uint<1>> wok;
  sc_in<sc_uint<1>> rd;
  sc_out<sc_uint<1>> rok;

  sc_uint<32> data;

  bool full = false;
  
  void exec() {
    if(full){
      wok.write(0);
      rok.write(1);
      data_out.write(data);
      if(rd.read() == 1){
        full = 0;
      }
    }
    else{
      wok.write(1);
      rok.write(0);
      data = data_in.read();
      if(wr.read() == 1){
        full = 1;
      }
    }
  }

  SC_CTOR(Input_Buffer) {
    SC_METHOD(exec);
      sensitive << wr << rd << data_in;
  }
};
