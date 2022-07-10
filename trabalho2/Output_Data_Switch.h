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
    std::cout << "ODS data0: " << data0.read() << std::endl;
    std::cout << "ODS data1: " << data1.read() << std::endl;
    std::cout << "ODS data2: " << data2.read() << std::endl;
    std::cout << "ODS data3: " << data3.read() << std::endl;
    std::cout << "ODS req0: " << req0.read() << std::endl;
    std::cout << "ODS req1: " << req1.read() << std::endl;
    std::cout << "ODS req2: " << req2.read() << std::endl;
    std::cout << "ODS req3: " << req3.read() << std::endl;
    if (req0.read() == 1){
      data_out.write(data0.read());
    }
    else if (req1.read() == 1){
      data_out.write(data1.read());
    }
    else if (req2.read() == 1){
      data_out.write(data2.read());
    }
    else if (req3.read() == 1){
      data_out.write(data3.read());
    }
    std::cout << "ODS data out: " << data_out.read() << std::endl;
  }
    

  SC_CTOR(Output_Data_Switch) {
    SC_METHOD(choose_out);
      sensitive << data0 << data1 << data2 << data3 << req0 << req1 << req2 << req3;
  }
};