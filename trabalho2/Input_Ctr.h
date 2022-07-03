#include "systemc.h"

SC_MODULE(Input_Ctr) {
  sc_in_clk clock; 

  sc_in<sc_uint<32>> data_in;
  sc_out<sc_uint<32>> data_out;

  sc_in<sc_uint<1>> rok;

  sc_in<sc_uint<1>> n_req;
  sc_in<sc_uint<1>> s_req;
  sc_in<sc_uint<1>> e_req;
  sc_in<sc_uint<1>> w_req;
  sc_in<sc_uint<1>> c_req;

  void routing() {
    //aqui vai ser a logica de roteamento
    data_out.write(data_in);
  }

  SC_CTOR(Input_Ctr) {
    SC_METHOD(routing);
      sensitive << clock.pos();
  }
};