#include "systemc.h"

SC_MODULE(Input_Read_Switch) {
  sc_in_clk clock; 

  sc_in<sc_uint<1>> gnt0;
  sc_in<sc_uint<1>> gnt1;
  sc_in<sc_uint<1>> gnt2;
  sc_in<sc_uint<1>> gnt3;

  sc_in<sc_uint<1>> rd0;
  sc_in<sc_uint<1>> rd1;
  sc_in<sc_uint<1>> rd2;
  sc_in<sc_uint<1>> rd3;

  sc_out<sc_uint<1>> rd;

  void exec() {
    bool ok = ((gnt0==1 && rd0==1)|| (gnt1==1 && rd1==1) ||
              (gnt2==1 && rd2==1)|| (gnt3==1 && rd3==1));
    if(ok){
      rd.write(1);
    } else{
      rd.write(0);
    }
  }
  SC_CTOR(Input_Read_Switch) {
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};