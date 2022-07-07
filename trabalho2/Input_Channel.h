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

  sc_out<sc_uint<1>> n_req;
  sc_out<sc_uint<1>> s_req;
  sc_out<sc_uint<1>> e_req;
  sc_out<sc_uint<1>> w_req;
  sc_out<sc_uint<1>> l_req;

  Input_Ctr* input_ctr;
  sc_signal<sc_uint<32>> ic_data_in;
  sc_signal<sc_uint<32>> ic_data_out;
  sc_signal<sc_uint<1>> ic_rok;
  sc_signal<sc_uint<1>> ic_n_req;
  sc_signal<sc_uint<1>> ic_s_req;
  sc_signal<sc_uint<1>> ic_e_req;
  sc_signal<sc_uint<1>> ic_w_req;
  sc_signal<sc_uint<1>> ic_c_req;
  
  Input_Buffer* input_buffer;
  sc_signal<sc_uint<32>> ib_data_in;
  sc_signal<sc_uint<32>> ib_data_out;
  sc_signal<sc_uint<1>> ib_wr;
  sc_signal<sc_uint<1>> ib_wok;
  sc_signal<sc_uint<1>> ib_rd;
  sc_signal<sc_uint<1>> ib_rok;

  Input_Flow_Ctr* input_flow_ctr;
  sc_signal<sc_uint<1>> ifc_val;
  sc_signal<sc_uint<1>> ifc_ack;
  sc_signal<sc_uint<1>> ifc_wok;
  sc_signal<sc_uint<1>> ifc_wr;

  
  Input_Read_Switch* input_read_switch;
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
    input_ctr->clock(clock);
    input_ctr->data_in(ic_data_in);
    input_ctr->data_out(ic_data_out);
    input_ctr->rok(ic_rok);
    input_ctr->n_req(ic_n_req);
    input_ctr->s_req(ic_s_req);
    input_ctr->e_req(ic_e_req);
    input_ctr->w_req(ic_w_req);
    input_ctr->c_req(ic_c_req);
  }
  
  void input_buffer_ini() {
    input_buffer->clock(clock); 
    input_buffer->data_in(ib_data_in);
    input_buffer->data_out(ib_data_out);
    input_buffer->wr(ib_wr);
    input_buffer->wok(ib_wok);
    input_buffer->rd(ib_rd);
    input_buffer->rok(ib_rok);
  }
  void input_flow_ctr_ini() {
    input_flow_ctr->clock(clock);
    input_flow_ctr->val(ifc_val);
    input_flow_ctr->ack(ifc_ack);
    input_flow_ctr->wok(ifc_wok);
    input_flow_ctr->wr(ifc_wr);
  }
  void input_read_switch_ini() {
    input_read_switch->clock(clock);
    input_read_switch->gnt0(irs_gnt0);
    input_read_switch->gnt1(irs_gnt1);
    input_read_switch->gnt2(irs_gnt2);
    input_read_switch->gnt3(irs_gnt3);
    input_read_switch->rd0(irs_rd0);
    input_read_switch->rd1(irs_rd1);
    input_read_switch->rd2(irs_rd2);
    input_read_switch->rd3(irs_rd3);
    input_read_switch->rd(irs_rd);
  }

  void input_channel_ini() {
    input_ctr_ini();
    input_buffer_ini();
    input_flow_ctr_ini();
    input_read_switch_ini();
  }
  void exec() {
    //IFC connections
    ifc_val.write(val.read());
    ack.write(ifc_ack.read());
    ifc_wok.write(ib_wok.read());
    
    //Buffer connections
    ib_wr.write(ifc_wr.read());
    ib_data_in.write(data.read());
    ib_rd.write(irs_rd.read());
   
    //IC connections
    ic_data_in.write(ib_data_out.read());
    ic_rok.write(ib_rok.read());
    data_out.write(ic_data_out.read());
    n_req.write(ic_n_req.read());
    s_req.write(ic_s_req.read());
    e_req.write(ic_e_req.read());
    w_req.write(ic_w_req.read());
    l_req.write(ic_c_req.read());

    //IRS connections
    irs_gnt0.write(gnt0.read());
    irs_gnt1.write(gnt1.read());
    irs_gnt2.write(gnt2.read());
    irs_gnt3.write(gnt3.read());
    irs_rd0.write(rd0.read());
    irs_rd1.write(rd1.read());
    irs_rd2.write(rd2.read());
    irs_rd3.write(rd3.read());
  }
  SC_CTOR(Input_Channel) {
    input_channel_ini();
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};