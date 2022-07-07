#include "systemc.h"
#include "Output_Ctr.h"
#include "Output_Data_Switch.h"
#include "Output_Flow_Ctr.h"
#include "Output_Write_Switch.h"

SC_MODULE(Output_Channel) {
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

  sc_out<sc_uint<1>> gnt0;
  sc_out<sc_uint<1>> gnt1;
  sc_out<sc_uint<1>> gnt2;
  sc_out<sc_uint<1>> gnt3;

  sc_in<sc_uint<1>> rok0;
  sc_in<sc_uint<1>> rok1;
  sc_in<sc_uint<1>> rok2;
  sc_in<sc_uint<1>> rok3;

  sc_out<sc_uint<1>> out_val;
  sc_in<sc_uint<1>> out_ack;

  Output_Ctr* output_ctr;
  

  
  Output_Data_Switch* output_data_switch;
  Output_Flow_Ctr* output_flow_ctr;
  Output_Write_Switch* output_write_switch;

  void output_ctr_ini(){
    
  }
  void output_data_switch_ini(){
    
  }
  void output_flow_ctr_ini(){
    
  }
  void output_write_switch_ini(){
    
  }
  void output_channel_ini(){
    output_ctr_ini();
    output_data_switch_ini();
    output_flow_ctr_ini();
    output_write_switch_ini();
  }

  SC_CTOR(Output_Channel) {
    output_channel_ini();
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};
