#include "systemc.h"

enum Estado{S0, S1, S2};

SC_MODULE(Input_Flow_Ctr) {
  sc_in_clk clock; 

  sc_in<sc_uint<1>> val;
  sc_out<sc_uint<1>> ack;

  sc_in<sc_uint<1>> wok;
  sc_out<sc_uint<1>> wr;

  Estado estado = S0;

  void exec() {
    switch(estado){
      case S0: {
        std::cout << "estado: " << estado << std::endl;
        std::cout << "val: " << val.read() << std::endl;
        std::cout << "wok: " << wok.read() << std::endl;
        if(val.read() == 1 && wok.read() == 1) {
          estado = S1;
          ack.write(1);
          wr.write(1);
        }
      }
      break;
      case S1: {
        std::cout << "estado: " << estado << std::endl;
        if(val.read() == 0){
          estado = S0;
          ack.write(0);
          wr.write(0);
        }
        else{
          estado = S2;
          ack.write(1);
          wr.write(0);
        }
      }
      break;
      case S2: {
        std::cout << "estado: " << estado << std::endl;
        if(val.read() == 0){
          estado = S0;
          ack.write(0);
          wr.write(0);
        }
      }
      break;
    };
  }

  SC_CTOR(Input_Flow_Ctr) {
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};