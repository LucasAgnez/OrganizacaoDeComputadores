#include "systemc.h"

SC_MODULE(Output_Data_Switch) {
  sc_in_clk clock; 

  sc_in<sc_uint<32>> data0;
  sc_in<sc_uint<32>> data1;
  sc_in<sc_uint<32>> data2;
  sc_in<sc_uint<32>> data3;


  sc_out<sc_uint<32>> data_out;
  
  sc_out<sc_uint<2>> eop;
  
  int eop_count = 0;
  
  sc_in<sc_uint<1>> req0;
  sc_in<sc_uint<1>> req1;
  sc_in<sc_uint<1>> req2;
  sc_in<sc_uint<1>> req3;

  void choose_out() {
    if (req0.read() == 1 && data0.read() != 0){
      data_out.write(data0.read());
      eop_count++;
    }
    else if (req1.read() == 1 && data1.read() != 0){
      data_out.write(data1.read());
      eop_count++;
    }
    else if (req2.read() == 1 && data2.read() != 0){
      data_out.write(data2.read());
      eop_count++;
    }
    else if (req3.read() == 1 && data3.read() != 0){
      data_out.write(data3.read());
      eop_count++;
    }
    else{
      data_out.write(0);
    }
    eop.write(eop_count);
  }
    

  SC_CTOR(Output_Data_Switch) {
    SC_METHOD(choose_out);
      sensitive << data0 << data1 << data2 << data3 << req0 << req1 << req2 << req3;
  }
};
