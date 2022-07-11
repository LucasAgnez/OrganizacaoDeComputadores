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
    bool ok = ((gnt0.read()==1 && rd0.read()==1)|| (gnt1.read()==1 && rd1.read()==1) ||
              (gnt2.read()==1 && rd2.read()==1)|| (gnt3.read()==1 && rd3.read()==1));
    if(ok){
      rd.write(1);
    } else{
      rd.write(0);
    }
  }
  SC_CTOR(Input_Read_Switch) {
    SC_METHOD(exec);
      sensitive << gnt0 << gnt1 << gnt2 << gnt3 << rd0 << rd1 << rd2 << rd3;
  }
};
