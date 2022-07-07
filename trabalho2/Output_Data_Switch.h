#include "systemc.h"

SC_MODULE(Output_Data_Switch) {
  sc_in_clk clock; 

  sc_in<sc_uint<32>> data0;
  sc_in<sc_uint<32>> data1;
  sc_in<sc_uint<32>> data2;
  sc_in<sc_uint<32>> data3;


  sc_out<sc_uint<32>> data_out;
  
  sc_in<sc_uint<1>> req0;
  sc_in<sc_uint<1>> req1;
  sc_in<sc_uint<1>> req2;
  sc_in<sc_uint<1>> req3;

  void choose_out() {
    if (req0.read() == 1){
      data_out.write(data0);
    }
    else if (req1.read() == 1){
      data_out.write(data1);
    }
    else if (data2.read() == 1){
      data_out.write(data2);
    }
    else if (req3.read() == 1){
      data_out.write(data3);
    }
  }
    

  SC_CTOR(Output_Data_Switch) {
    SC_METHOD(choose_out);
      sensitive << clock.pos();
  }
};