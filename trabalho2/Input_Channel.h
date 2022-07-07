#include "systemc.h"
#include "Input_Ctr.h"
#include "Input_Buffer.h"
#include "Input_Flow_Ctr.h"
#include "Input_Read_Switch.h"

SC_MODULE(Input_Channel) {
  sc_in_clk clock; 

  sc_in<sc_uint<32>> data;

  sc_in<sc_uint<1>> val;
  sc_out<sc_uint<1>> ack;

  sc_out<sc_uint<32>> data_out;

  sc_in<sc_uint<1>> gnt0;
  sc_in<sc_uint<1>> gnt1;
  sc_in<sc_uint<1>> gnt2;
  sc_in<sc_uint<1>> gnt3;

  sc_in<sc_uint<1>> rd0;
  sc_in<sc_uint<1>> rd1;
  sc_in<sc_uint<1>> rd2;
  sc_in<sc_uint<1>> rd3;

  Input_Ctr* IC;
  sc_signal<sc_uint<32>> ic_data_in;
  sc_signal<sc_uint<32>> ic_data_out;
  sc_signal<sc_uint<1>> ic_rok;
  sc_signal<sc_uint<1>> ic_n_req;
  sc_signal<sc_uint<1>> ic_s_req;
  sc_signal<sc_uint<1>> ic_e_req;
  sc_signal<sc_uint<1>> ic_w_req;
  sc_signal<sc_uint<1>> ic_c_req;
  
  Input_Buffer* IB;
  sc_signal<sc_uint<32>> ib_data_in;
  sc_signal<sc_uint<32>> ib_data_out;
  sc_signal<sc_uint<1>> ib_wr;
  sc_signal<sc_uint<1>> ib_wok;
  sc_signal<sc_uint<1>> ib_rd;
  sc_signal<sc_uint<1>> ib_rok;

  Input_Flow_Ctr* IFC;
  sc_signal<sc_uint<1>> ifc_val;
  sc_signal<sc_uint<1>> ifc_ack;
  sc_signal<sc_uint<1>> ifc_wok;
  sc_signal<sc_uint<1>> ifc_wr;

  
  Input_Read_Switch* IRS;
  sc_signal<sc_uint<1>> irs_gnt0;
  sc_signal<sc_uint<1>> irs_gnt1;
  sc_signal<sc_uint<1>> irs_gnt2;
  sc_signal<sc_uint<1>> irs_gnt3;
  sc_signal<sc_uint<1>> irs_rd0;
  sc_signal<sc_uint<1>> irs_rd1;
  sc_signal<sc_uint<1>> irs_rd2;
  sc_signal<sc_uint<1>> irs_rd3;
  sc_signal<sc_uint<1>> irs_rd;

  void input_ctr_ini() {
    IC->clock(clock);
    IC->data_in(ic_data_in);
    IC->data_out(ic_data_out);
    IC->rok(ic_rok);
    IC->n_req(ic_n_req);
    IC->s_req(ic_s_req);
    IC->e_req(ic_e_req);
    IC->w_req(ic_w_req);
    IC->c_req(ic_c_req);
  }
  
  void input_buffer_ini() {
    IB->clock(clock); 
    IB->data_in(ib_data_in);
    IB->data_out(ib_data_out);
    IB->wr(ib_wr);
    IB->wok(ib_wok);
    IB->rd(ib_rd);
    IB->rok(ib_rok);
  }
  void input_flow_ctr_ini() {
    IFC->clock(clock);
    IFC->val(ifc_val);
    IFC->ack(ifc_ack);
    IFC->wok(ifc_wok);
    IFC->wr(ifc_wr);
  }
  void input_read_switch_ini() {
    IRS->clock(clock);
    IRS->gnt0(irs_gnt0);
    IRS->gnt1(irs_gnt1);
    IRS->gnt2(irs_gnt2);
    IRS->gnt3(irs_gnt3);
    IRS->rd0(irs_rd0);
    IRS->rd1(irs_rd1);
    IRS->rd2(irs_rd2);
    IRS->rd3(irs_rd3);
    IRS->rd(irs_rd);
  }

  
  void input_channel_ini() {
    input_ctr_ini();
    input_buffer_ini();
    input_flow_ctr_ini();
    input_read_switch_ini();
  }

  SC_CTOR(Input_Channel) {
    input_channel_ini();
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};