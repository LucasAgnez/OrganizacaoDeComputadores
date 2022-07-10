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
  sc_out<sc_uint<1>> l_req;

  void routing() {
    sc_uint<2> X;
    sc_uint<2> Y;
    sc_uint<1> left_right; // se 0, para o leste
    sc_uint<1> up_down; // se 0, para o sul
    X = data_in.read() >> 30;
    left_right = data_in.read() >> 29;
    Y = data_in.read() >> 27;
    up_down = data_in.read() >> 26;
    std::cout << "IC x: " << X << std::endl;
    std::cout << "IC y: " << Y << std::endl;
    std::cout << "IC left_right: " << left_right << std::endl;
    std::cout << "IC up_down: " << up_down << std::endl;
    if(X == 0 && Y == 0){
      n_req.write(0);
      s_req.write(0);
      e_req.write(0);
      w_req.write(0);
      l_req.write(1);
      std::cout << "AAAAAA" << std::endl;
    }
    else if(X>0){
      X--;
      if(left_right == 0){
        n_req.write(0);
        s_req.write(0);
        e_req.write(1);
        w_req.write(0);
        l_req.write(0);
      }
      else if(left_right == 1){
        n_req.write(0);
        s_req.write(0);
        e_req.write(0);
        w_req.write(1);
        l_req.write(0);
      }
    }
    else if(Y>0){
      Y--;
      if(up_down == 0){
        n_req.write(0);
        s_req.write(1);
        e_req.write(0);
        w_req.write(0);
        l_req.write(0);
        std::cout << "AAAAAA" << std::endl;
      }
      else if(up_down == 1){
        n_req.write(1);
        s_req.write(0);
        e_req.write(0);
        w_req.write(0);
        l_req.write(0);
      }
    }
    if(rok.read() == 1){
      std::cout << "IC l_req: " << l_req.read() << std::endl;
      std::cout << "IC Data in: " << data_in.read() << std::endl;
      std::cout << "IC Data out: " << data_out.read() << std::endl;
      std::cout << "IC n_req: " << n_req.read() << std::endl;
      std::cout << "IC s_req: " << s_req.read() << std::endl;
      std::cout << "IC up_down: " << up_down << std::endl;
      std::cout << "IC e_req: " << e_req.read() << std::endl;
      std::cout << "IC w_req: " << w_req.read() << std::endl;

      sc_uint<6> new_header;
      new_header = (X<<4) + (left_right<<3) + (Y<<1) + up_down;
      sc_uint<32> new_data = data_in.read() << 6;
      new_data = new_data >> 6;
      new_data = new_data + (new_header << 26);
      data_out.write(new_data);
      std::cout << "IC new data: " << new_data << std::endl;

    }
  }

  SC_CTOR(Input_Ctr) {
    SC_METHOD(routing);
      sensitive << data_in << rok;
  }
};