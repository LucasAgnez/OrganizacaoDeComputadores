#include "systemc.h"

SC_MODULE(Input_Ctr) {
  sc_in_clk clock; 

  sc_in<sc_uint<32>> data_in;
  sc_out<sc_uint<32>> data_out;

  sc_in<sc_uint<1>> rok;

  sc_out<sc_uint<1>> n_req;
  sc_out<sc_uint<1>> s_req;
  sc_out<sc_uint<1>> e_req;
  sc_out<sc_uint<1>> w_req;
  sc_out<sc_uint<1>> c_req;

  void routing() {
    sc_uint<2> X;
    sc_uint<2> Y;
    sc_uint<1> left_right; // se 0, vem do oeste
    sc_uint<1> up_down; // se 0, vem de norte
    X = data_in.read() >> 30;
    left_right = data_in.read() >> 29;
    Y = data_in.read() >> 28;
    up_down = data_in.read() >> 26;
    if(X>0){
      X--;
      if(left_right == 0){
        n_req.write(0);
        s_req.write(0);
        e_req.write(1);
        w_req.write(0);
        c_req.write(0);
      }
      else if(left_right == 1){
        n_req.write(0);
        s_req.write(0);
        e_req.write(0);
        w_req.write(1);
        c_req.write(0);
      }
    }
    else if(Y>0){
      Y--;
      if(up_down == 0){
        n_req.write(0);
        s_req.write(1);
        e_req.write(0);
        w_req.write(0);
        c_req.write(0);
      }
      else if(up_down == 1){
        n_req.write(1);
        s_req.write(0);
        e_req.write(0);
        w_req.write(0);
        c_req.write(0);
      }
    }
    else{
      n_req.write(0);
      s_req.write(0);
      e_req.write(0);
      w_req.write(0);
      c_req.write(1);
    }
    if(rok == 1){
      sc_uint<6> new_header;
      new_header = (X<<4) + (left_right<<3) + (Y<<1) + up_down;
      sc_uint<32> new_data = data_in.read() << 6;
      new_data = new_data >> 6;
      new_data = new_data + (new_header << 26);
      data_out.write(new_data);
    }
  }

  SC_CTOR(Input_Ctr) {
    SC_METHOD(routing);
      sensitive << clock.pos();
  }
};