#include "systemc.h"


SC_MODULE(Output_Flow_Ctr) {
  sc_in_clk clock; 

  sc_out<sc_uint<1>> out_val;
  sc_in<sc_uint<1>> out_ack;

  sc_in<sc_uint<1>> rok;
  sc_out<sc_uint<1>> rd;

  Estado estado = S0;

  void exec() {
    switch(estado){
      case S0: {
        if(rok.read() == 1 && out_ack.read() == 0) {
          estado = S1;
          out_val.write(1);
          rd.write(0);
        }
      }
      break;
      case S1: {
        if(out_ack.read() == 1){
          estado = S2;
          out_val.write(0);
          rd.write(1);
        }
      }
      break;
      case S2: {
        if(rok.read() == 0 || out_ack.read() == 1){
          estado = S0;
          out_val.write(0);
          rd.write(0);

        }
        else if(rok.read() == 1 && out_ack.read() == 0){
          estado = S1;
          out_val.write(1);
          rd.write(0);
        }
      }
      break;
    };
  }

  SC_CTOR(Output_Flow_Ctr) {
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};