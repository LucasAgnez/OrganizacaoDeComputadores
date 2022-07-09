#include "systemc.h"

SC_MODULE(Output_Write_Switch) {
  sc_in_clk clock;

  sc_in<sc_uint<1>> gnt0;
  sc_in<sc_uint<1>> gnt1;
  sc_in<sc_uint<1>> gnt2;
  sc_in<sc_uint<1>> gnt3;

  sc_in<sc_uint<1>> rok0;
  sc_in<sc_uint<1>> rok1;
  sc_in<sc_uint<1>> rok2;
  sc_in<sc_uint<1>> rok3;

  sc_out<sc_uint<1>> rok;
  
  void exec() {
    bool ok = ((gnt0.read()==1 && rok0.read()==1)|| (gnt1.read()==1 && rok1.read()==1) ||
              (gnt2.read()==1 && rok2.read()==1)|| (gnt3.read()==1 && rok3.read()==1));
    if(ok){
      rok.write(1);
    } else{
      rok.write(0);
    }
  }

  SC_CTOR(Output_Write_Switch) {
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};