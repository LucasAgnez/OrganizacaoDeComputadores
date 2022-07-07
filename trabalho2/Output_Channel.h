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
  sc_signal<sc_uint<1>> output_ctr_req0;
  sc_signal<sc_uint<1>> output_ctr_req1;
  sc_signal<sc_uint<1>> output_ctr_req2;
  sc_signal<sc_uint<1>> output_ctr_req3;
  sc_signal<sc_uint<1>> output_ctr_rd;
  sc_signal<sc_uint<1>> output_ctr_gnt0;
  sc_signal<sc_uint<1>> output_ctr_gnt1;
  sc_signal<sc_uint<1>> output_ctr_gnt2;
  sc_signal<sc_uint<1>> output_ctr_gnt3;

  
  Output_Data_Switch* output_data_switch;
  sc_signal<sc_uint<32>> output_data_switch_data0;
  sc_signal<sc_uint<32>> output_data_switch_data1;
  sc_signal<sc_uint<32>> output_data_switch_data2;
  sc_signal<sc_uint<32>> output_data_switch_data3;
  sc_signal<sc_uint<32>> output_data_switch_data_out;
  sc_signal<sc_uint<1>> output_data_switch_req0;
  sc_signal<sc_uint<1>> output_data_switch_req1;
  sc_signal<sc_uint<1>> output_data_switch_req2;
  sc_signal<sc_uint<1>> output_data_switch_req3;

  
  Output_Flow_Ctr* output_flow_ctr;
  sc_signal<sc_uint<1>> output_flow_ctr_out_val;
  sc_signal<sc_uint<1>> output_flow_ctr_out_ack;
  sc_signal<sc_uint<1>> output_flow_ctr_rok;
  sc_signal<sc_uint<1>> output_flow_ctr_rd;

  
  Output_Write_Switch* output_write_switch;
  sc_signal<sc_uint<1>> output_write_switch_gnt0;
  sc_signal<sc_uint<1>> output_write_switch_gnt1;
  sc_signal<sc_uint<1>> output_write_switch_gnt2;
  sc_signal<sc_uint<1>> output_write_switch_gnt3;
  sc_signal<sc_uint<1>> output_write_switch_rok0;
  sc_signal<sc_uint<1>> output_write_switch_rok1;
  sc_signal<sc_uint<1>> output_write_switch_rok2;
  sc_signal<sc_uint<1>> output_write_switch_rok3;
  sc_out<sc_uint<1>> output_write_switch_rok;

  void output_ctr_ini(){
    output_ctr->clock(clock);
    output_ctr->req0(output_ctr_req0);
    output_ctr->req1(output_ctr_req1);
    output_ctr->req2(output_ctr_req2);
    output_ctr->req3(output_ctr_req3);
    output_ctr->rd(output_ctr_rd);
    output_ctr->gnt0(output_ctr_gnt0);
    output_ctr->gnt1(output_ctr_gnt1);
    output_ctr->gnt2(output_ctr_gnt2);
    output_ctr->gnt3(output_ctr_gnt3);
  }
  void output_data_switch_ini(){
    output_data_switch->clock(clock);
    output_data_switch->data0(output_data_switch_data0);
    output_data_switch->data1(output_data_switch_data1);
    output_data_switch->data2(output_data_switch_data2);
    output_data_switch->data3(output_data_switch_data3);
    output_data_switch->data_out(output_data_switch_data_out);
    output_data_switch->req0(output_data_switch_req0);
    output_data_switch->req1(output_data_switch_req1);
    output_data_switch->req2(output_data_switch_req2);
    output_data_switch->req3(output_data_switch_req3);
  }
  void output_flow_ctr_ini(){
    output_flow_ctr->clock(clock);
    output_flow_ctr->out_val(output_flow_ctr_out_val);
    output_flow_ctr->out_ack(output_flow_ctr_out_ack);
    output_flow_ctr->rok(output_flow_ctr_rok);
    output_flow_ctr->rd(output_flow_ctr_rd);
  }
  void output_write_switch_ini(){
    output_write_switch->clock(clock);
    output_write_switch->gnt0(output_write_switch_gnt0);
    output_write_switch->gnt1(output_write_switch_gnt1);
    output_write_switch->gnt2(output_write_switch_gnt2);
    output_write_switch->gnt3(output_write_switch_gnt3);
    output_write_switch->rok0(output_write_switch_gnt0);
    output_write_switch->rok1(output_write_switch_rok1);
    output_write_switch->rok2(output_write_switch_rok2);
    output_write_switch->rok3(output_write_switch_rok3);
    output_write_switch->rok(output_write_switch_rok);
  }
  void output_channel_ini(){
    output_ctr_ini();
    output_data_switch_ini();
    output_flow_ctr_ini();
    output_write_switch_ini();
  }

  void exec(){
    //ODS connections
    output_data_switch_data0.write(data0.read());
    output_data_switch_data1.write(data1.read());
    output_data_switch_data2.write(data2.read());
    output_data_switch_data3.write(data3.read());
    output_data_switch_req0.write(output_ctr_gnt0.read());
    output_data_switch_req1.write(output_ctr_gnt1.read());
    output_data_switch_req2.write(output_ctr_gnt2.read());
    output_data_switch_req3.write(output_ctr_gnt3.read());
    data_out.write(output_data_switch_data_out.read());
    
    //OC connections
    output_ctr_req0.write(req0.read());
    output_ctr_req1.write(req1.read());
    output_ctr_req2.write(req2.read());
    output_ctr_req3.write(req3.read());
    gnt0.write(output_ctr_gnt0.read());
    gnt1.write(output_ctr_gnt1.read());
    gnt2.write(output_ctr_gnt2.read());
    gnt3.write(output_ctr_gnt3.read());
    output_ctr_rd.write(output_flow_ctr_rd.read());
    
    
    //OWS connections
    output_write_switch_gnt0.write(output_ctr_gnt0.read());
    output_write_switch_gnt1.write(output_ctr_gnt1.read());
    output_write_switch_gnt2.write(output_ctr_gnt2.read());
    output_write_switch_gnt3.write(output_ctr_gnt3.read());
    output_write_switch_rok0.write(rok0.read());
    output_write_switch_rok1.write(rok1.read());
    output_write_switch_rok2.write(rok2.read());
    output_write_switch_rok3.write(rok3.read());
    
    //OFC connections
    output_flow_ctr_rok.write(output_write_switch_rok.read());
    output_flow_ctr_out_ack.write(out_ack.read());
    out_val.write(output_flow_ctr_out_val.read());
  }

  SC_CTOR(Output_Channel) {
    output_channel_ini();
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};
