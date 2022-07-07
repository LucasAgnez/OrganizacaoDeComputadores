#include "Input_Channel.h"
#include "Output_Channel.h"

SC_MODULE(Router) {
	sc_in_clk clock;

  sc_in<sc_uint<32>> north_data_in;
  sc_out<sc_uint<32>> north_data_out;
  sc_out<sc_uint<1>> north_ack_in;
  sc_in<sc_uint<1>> north_ack_out;
  sc_in<sc_uint<1>> north_val_in;
  sc_out<sc_uint<1>> north_val_out;
  
  sc_in<sc_uint<32>> south_data_in;
  sc_out<sc_uint<32>> south_data_out;
  sc_out<sc_uint<1>> south_ack_in;
  sc_in<sc_uint<1>> south_ack_out;
  sc_in<sc_uint<1>> south_val_in;
  sc_out<sc_uint<1>> south_val_out;
  
  sc_in<sc_uint<32>> east_data_in;
  sc_out<sc_uint<32>> east_data_out;
  sc_out<sc_uint<1>> east_ack_in;
  sc_in<sc_uint<1>> east_ack_out;
  sc_in<sc_uint<1>> east_val_in;
  sc_out<sc_uint<1>> east_val_out;
  
  sc_in<sc_uint<32>> west_data_in;
  sc_out<sc_uint<32>> west_data_out;
  sc_out<sc_uint<1>> west_ack_in;
  sc_in<sc_uint<1>> west_ack_out;
  sc_in<sc_uint<1>> west_val_in;
  sc_out<sc_uint<1>> west_val_out;
  
  sc_in<sc_uint<32>> local_data_in;
  sc_out<sc_uint<32>> local_data_out;
  sc_out<sc_uint<1>> local_ack_in;
  sc_in<sc_uint<1>> local_ack_out;
  sc_in<sc_uint<1>> local_val_in;
  sc_out<sc_uint<1>> local_val_out;
  
  Input_Channel* n_ic;  
  sc_signal<sc_uint<32>> n_ic_data;
  sc_signal<sc_uint<1>> n_ic_val;
  sc_signal<sc_uint<1>> n_ic_ack;
  sc_signal<sc_uint<32>> n_ic_data_out;
  sc_signal<sc_uint<1>> n_ic_gnt0;
  sc_signal<sc_uint<1>> n_ic_gnt1;
  sc_signal<sc_uint<1>> n_ic_gnt2;
  sc_signal<sc_uint<1>> n_ic_gnt3;
  sc_signal<sc_uint<1>> n_ic_rd0;
  sc_signal<sc_uint<1>> n_ic_rd1;
  sc_signal<sc_uint<1>> n_ic_rd2;
  sc_signal<sc_uint<1>> n_ic_rd3;
  sc_signal<sc_uint<1>> n_ic_n_req;
  sc_signal<sc_uint<1>> n_ic_s_req;
  sc_signal<sc_uint<1>> n_ic_e_req;
  sc_signal<sc_uint<1>> n_ic_w_req;
  sc_signal<sc_uint<1>> n_ic_l_req;
  
  Output_Channel* n_oc;
  sc_signal<sc_uint<32>> n_oc_data0;
  sc_signal<sc_uint<32>> n_oc_data1;
  sc_signal<sc_uint<32>> n_oc_data2;
  sc_signal<sc_uint<32>> n_oc_data3;
  sc_signal<sc_uint<32>> n_oc_data_out;
  sc_signal<sc_uint<1>> n_oc_req0;
  sc_signal<sc_uint<1>> n_oc_req1;
  sc_signal<sc_uint<1>> n_oc_req2;
  sc_signal<sc_uint<1>> n_oc_req3;
  sc_signal<sc_uint<1>> n_oc_gnt0;
  sc_signal<sc_uint<1>> n_oc_gnt1;
  sc_signal<sc_uint<1>> n_oc_gnt2;
  sc_signal<sc_uint<1>> n_oc_gnt3;
  sc_signal<sc_uint<1>> n_oc_rok0;
  sc_signal<sc_uint<1>> n_oc_rok1;
  sc_signal<sc_uint<1>> n_oc_rok2;
  sc_signal<sc_uint<1>> n_oc_rok3;
  sc_signal<sc_uint<1>> n_oc_out_val;
  sc_signal<sc_uint<1>> n_oc_out_ack;

  Input_Channel* s_ic;
  sc_signal<sc_uint<32>> s_ic_data;
  sc_signal<sc_uint<1>> s_ic_val;
  sc_signal<sc_uint<1>> s_ic_ack;
  sc_signal<sc_uint<32>> s_ic_data_out;
  sc_signal<sc_uint<1>> s_ic_gnt0;
  sc_signal<sc_uint<1>> s_ic_gnt1;
  sc_signal<sc_uint<1>> s_ic_gnt2;
  sc_signal<sc_uint<1>> s_ic_gnt3;
  sc_signal<sc_uint<1>> s_ic_rd0;
  sc_signal<sc_uint<1>> s_ic_rd1;
  sc_signal<sc_uint<1>> s_ic_rd2;
  sc_signal<sc_uint<1>> s_ic_rd3;
  sc_signal<sc_uint<1>> s_ic_n_req;
  sc_signal<sc_uint<1>> s_ic_s_req;
  sc_signal<sc_uint<1>> s_ic_e_req;
  sc_signal<sc_uint<1>> s_ic_w_req;
  sc_signal<sc_uint<1>> s_ic_l_req;
 
  Output_Channel* s_oc;
  sc_signal<sc_uint<32>> s_oc_data0;
  sc_signal<sc_uint<32>> s_oc_data1;
  sc_signal<sc_uint<32>> s_oc_data2;
  sc_signal<sc_uint<32>> s_oc_data3;
  sc_signal<sc_uint<32>> s_oc_data_out;
  sc_signal<sc_uint<1>> s_oc_req0;
  sc_signal<sc_uint<1>> s_oc_req1;
  sc_signal<sc_uint<1>> s_oc_req2;
  sc_signal<sc_uint<1>> s_oc_req3;
  sc_signal<sc_uint<1>> s_oc_gnt0;
  sc_signal<sc_uint<1>> s_oc_gnt1;
  sc_signal<sc_uint<1>> s_oc_gnt2;
  sc_signal<sc_uint<1>> s_oc_gnt3;
  sc_signal<sc_uint<1>> s_oc_rok0;
  sc_signal<sc_uint<1>> s_oc_rok1;
  sc_signal<sc_uint<1>> s_oc_rok2;
  sc_signal<sc_uint<1>> s_oc_rok3;
  sc_signal<sc_uint<1>> s_oc_out_val;
  sc_signal<sc_uint<1>> s_oc_out_ack;

  Input_Channel* ic_e;  
  sc_signal<sc_uint<32>> e_ic_data;
  sc_signal<sc_uint<1>> e_ic_val;
  sc_signal<sc_uint<1>> e_ic_ack;
  sc_signal<sc_uint<32>> e_ic_data_out;
  sc_signal<sc_uint<1>> e_ic_gnt0;
  sc_signal<sc_uint<1>> e_ic_gnt1;
  sc_signal<sc_uint<1>> e_ic_gnt2;
  sc_signal<sc_uint<1>> e_ic_gnt3;
  sc_signal<sc_uint<1>> e_ic_rd0;
  sc_signal<sc_uint<1>> e_ic_rd1;
  sc_signal<sc_uint<1>> e_ic_rd2;
  sc_signal<sc_uint<1>> e_ic_rd3;
  sc_signal<sc_uint<1>> e_ic_n_req;
  sc_signal<sc_uint<1>> e_ic_s_req;
  sc_signal<sc_uint<1>> e_ic_e_req;
  sc_signal<sc_uint<1>> e_ic_w_req;
  sc_signal<sc_uint<1>> e_ic_l_req;
  
  Output_Channel* e_oc;
  sc_signal<sc_uint<32>> e_oc_data0;
  sc_signal<sc_uint<32>> e_oc_data1;
  sc_signal<sc_uint<32>> e_oc_data2;
  sc_signal<sc_uint<32>> e_oc_data3;
  sc_signal<sc_uint<32>> e_oc_data_out;
  sc_signal<sc_uint<1>> e_oc_req0;
  sc_signal<sc_uint<1>> e_oc_req1;
  sc_signal<sc_uint<1>> e_oc_req2;
  sc_signal<sc_uint<1>> e_oc_req3;
  sc_signal<sc_uint<1>> e_oc_gnt0;
  sc_signal<sc_uint<1>> e_oc_gnt1;
  sc_signal<sc_uint<1>> e_oc_gnt2;
  sc_signal<sc_uint<1>> e_oc_gnt3;
  sc_signal<sc_uint<1>> e_oc_rok0;
  sc_signal<sc_uint<1>> e_oc_rok1;
  sc_signal<sc_uint<1>> e_oc_rok2;
  sc_signal<sc_uint<1>> e_oc_rok3;
  sc_signal<sc_uint<1>> e_oc_out_val;
  sc_signal<sc_uint<1>> e_oc_out_ack;


  
  Input_Channel* w_ic;  
  sc_signal<sc_uint<32>> w_ic_data;
  sc_signal<sc_uint<1>> w_ic_val;
  sc_signal<sc_uint<1>> w_ic_ack;
  sc_signal<sc_uint<32>> w_ic_data_out;
  sc_signal<sc_uint<1>> w_ic_gnt0;
  sc_signal<sc_uint<1>> w_ic_gnt1;
  sc_signal<sc_uint<1>> w_ic_gnt2;
  sc_signal<sc_uint<1>> w_ic_gnt3;
  sc_signal<sc_uint<1>> w_ic_rd0;
  sc_signal<sc_uint<1>> w_ic_rd1;
  sc_signal<sc_uint<1>> w_ic_rd2;
  sc_signal<sc_uint<1>> w_ic_rd3;
  sc_signal<sc_uint<1>> w_ic_n_req;
  sc_signal<sc_uint<1>> w_ic_s_req;
  sc_signal<sc_uint<1>> w_ic_e_req;
  sc_signal<sc_uint<1>> w_ic_w_req;
  sc_signal<sc_uint<1>> w_ic_l_req;
  
  Output_Channel* w_oc;
  sc_signal<sc_uint<32>> w_oc_data0;
  sc_signal<sc_uint<32>> w_oc_data1;
  sc_signal<sc_uint<32>> w_oc_data2;
  sc_signal<sc_uint<32>> w_oc_data3;
  sc_signal<sc_uint<32>> w_oc_data_out;
  sc_signal<sc_uint<1>> w_oc_req0;
  sc_signal<sc_uint<1>> w_oc_req1;
  sc_signal<sc_uint<1>> w_oc_req2;
  sc_signal<sc_uint<1>> w_oc_req3;
  sc_signal<sc_uint<1>> w_oc_gnt0;
  sc_signal<sc_uint<1>> w_oc_gnt1;
  sc_signal<sc_uint<1>> w_oc_gnt2;
  sc_signal<sc_uint<1>> w_oc_gnt3;
  sc_signal<sc_uint<1>> w_oc_rok0;
  sc_signal<sc_uint<1>> w_oc_rok1;
  sc_signal<sc_uint<1>> w_oc_rok2;
  sc_signal<sc_uint<1>> w_oc_rok3;
  sc_signal<sc_uint<1>> w_oc_out_val;
  sc_signal<sc_uint<1>> w_oc_out_ack;


  
  Input_Channel* l_ic;
  sc_signal<sc_uint<32>> l_ic_data;
  sc_signal<sc_uint<1>> l_ic_val;
  sc_signal<sc_uint<1>> l_ic_ack;
  sc_signal<sc_uint<32>> l_ic_data_out;
  sc_signal<sc_uint<1>> l_ic_gnt0;
  sc_signal<sc_uint<1>> l_ic_gnt1;
  sc_signal<sc_uint<1>> l_ic_gnt2;
  sc_signal<sc_uint<1>> l_ic_gnt3;
  sc_signal<sc_uint<1>> l_ic_rd0;
  sc_signal<sc_uint<1>> l_ic_rd1;
  sc_signal<sc_uint<1>> l_ic_rd2;
  sc_signal<sc_uint<1>> l_ic_rd3;
  sc_signal<sc_uint<1>> l_ic_n_req;
  sc_signal<sc_uint<1>> l_ic_s_req;
  sc_signal<sc_uint<1>> l_ic_e_req;
  sc_signal<sc_uint<1>> l_ic_w_req;
  sc_signal<sc_uint<1>> l_ic_l_req;
  
  Output_Channel* l_oc;
  sc_signal<sc_uint<32>> l_oc_data0;
  sc_signal<sc_uint<32>> l_oc_data1;
  sc_signal<sc_uint<32>> l_oc_data2;
  sc_signal<sc_uint<32>> l_oc_data3;
  sc_signal<sc_uint<32>> l_oc_data_out;
  sc_signal<sc_uint<1>> l_oc_req0;
  sc_signal<sc_uint<1>> l_oc_req1;
  sc_signal<sc_uint<1>> l_oc_req2;
  sc_signal<sc_uint<1>> l_oc_req3;
  sc_signal<sc_uint<1>> l_oc_gnt0;
  sc_signal<sc_uint<1>> l_oc_gnt1;
  sc_signal<sc_uint<1>> l_oc_gnt2;
  sc_signal<sc_uint<1>> l_oc_gnt3;
  sc_signal<sc_uint<1>> l_oc_rok0;
  sc_signal<sc_uint<1>> l_oc_rok1;
  sc_signal<sc_uint<1>> l_oc_rok2;
  sc_signal<sc_uint<1>> l_oc_rok3;
  sc_signal<sc_uint<1>> l_oc_out_val;
  sc_signal<sc_uint<1>> l_oc_out_ack;

  void n_input_channels_ini(){
    n_ic->clock(clock);
    n_ic->data(n_ic_data);
    n_ic->val(n_ic_val);
    n_ic->ack(n_ic_ack);
    n_ic->data_out(n_ic_data_out);
    n_ic->gnt0(n_ic_gnt0);
    n_ic->gnt1(n_ic_gnt1);
    n_ic->gnt2(n_ic_gnt2);
    n_ic->gnt3(n_ic_gnt3);
    n_ic->rd0(n_ic_rd0);
    n_ic->rd1(n_ic_rd1);
    n_ic->rd2(n_ic_rd2);
    n_ic->rd3(n_ic_rd3);
    n_ic->n_req(n_ic_n_req);
    n_ic->s_req(n_ic_s_req);
    n_ic->e_req(n_ic_e_req);
    n_ic->w_req(n_ic_w_req);
    n_ic->l_req(n_ic_l_req);
  }
  void s_input_channels_ini(){
    s_ic->clock(clock);
    s_ic->data(s_ic_data);
    s_ic->val(s_ic_val);
    s_ic->ack(s_ic_ack);
    s_ic->data_out(s_ic_data_out);
    s_ic->gnt0(s_ic_gnt0);
    s_ic->gnt1(s_ic_gnt1);
    s_ic->gnt2(s_ic_gnt2);
    s_ic->gnt3(s_ic_gnt3);
    s_ic->rd0(s_ic_rd0);
    s_ic->rd1(s_ic_rd1);
    s_ic->rd2(s_ic_rd2);
    s_ic->rd3(s_ic_rd3);
    s_ic->n_req(s_ic_n_req);
    s_ic->s_req(s_ic_s_req);
    s_ic->e_req(s_ic_e_req);
    s_ic->w_req(s_ic_w_req);
    s_ic->l_req(s_ic_l_req);
  }
  void e_input_channels_ini(){
    e_ic->clock(clock);
    e_ic->data(e_ic_data);
    e_ic->val(e_ic_val);
    e_ic->ack(e_ic_ack);
    e_ic->data_out(e_ic_data_out);
    e_ic->gnt0(e_ic_gnt0);
    e_ic->gnt1(e_ic_gnt1);
    e_ic->gnt2(e_ic_gnt2);
    e_ic->gnt3(e_ic_gnt3);
    e_ic->rd0(e_ic_rd0);
    e_ic->rd1(e_ic_rd1);
    e_ic->rd2(e_ic_rd2);
    e_ic->rd3(e_ic_rd3);
    e_ic->n_req(e_ic_n_req);
    e_ic->s_req(e_ic_s_req);
    e_ic->e_req(e_ic_e_req);
    e_ic->w_req(e_ic_w_req);
    e_ic->l_req(e_ic_l_req);
  }
  void w_input_channels_ini(){
    w_ic->clock(clock);
    w_ic->data(w_ic_data);
    w_ic->val(w_ic_val);
    w_ic->ack(w_ic_ack);
    w_ic->data_out(w_ic_data_out);
    w_ic->gnt0(w_ic_gnt0);
    w_ic->gnt1(w_ic_gnt1);
    w_ic->gnt2(w_ic_gnt2);
    w_ic->gnt3(w_ic_gnt3);
    w_ic->rd0(w_ic_rd0);
    w_ic->rd1(w_ic_rd1);
    w_ic->rd2(w_ic_rd2);
    w_ic->rd3(w_ic_rd3);
    w_ic->n_req(w_ic_n_req);
    w_ic->s_req(w_ic_s_req);
    w_ic->e_req(w_ic_e_req);
    w_ic->w_req(w_ic_w_req);
    w_ic->l_req(w_ic_l_req);
  }
  void l_input_channels_ini(){
    l_ic->clock(clock);
    l_ic->data(l_ic_data);
    l_ic->val(l_ic_val);
    l_ic->ack(l_ic_ack);
    l_ic->data_out(l_ic_data_out);
    l_ic->gnt0(l_ic_gnt0);
    l_ic->gnt1(l_ic_gnt1);
    l_ic->gnt2(l_ic_gnt2);
    l_ic->gnt3(l_ic_gnt3);
    l_ic->rd0(l_ic_rd0);
    l_ic->rd1(l_ic_rd1);
    l_ic->rd2(l_ic_rd2);
    l_ic->rd3(l_ic_rd3);
    l_ic->n_req(l_ic_n_req);
    l_ic->s_req(l_ic_s_req);
    l_ic->e_req(l_ic_e_req);
    l_ic->w_req(l_ic_w_req);
    l_ic->l_req(l_ic_l_req);
  }
  
  void n_output_channels_ini(){
    n_oc->clock(clock);
    n_oc->data0(n_oc_data0);
    n_oc->data1(n_oc_data1);
    n_oc->data2(n_oc_data2);
    n_oc->data3(n_oc_data3);
    n_oc->data_out(n_oc_data_out);
    n_oc->req0(n_oc_req0);
    n_oc->req1(n_oc_req1);
    n_oc->req2(n_oc_req2);
    n_oc->req3(n_oc_req3);
    n_oc->gnt0(n_oc_gnt0);
    n_oc->gnt1(n_oc_gnt1);
    n_oc->gnt2(n_oc_gnt2);
    n_oc->gnt3(n_oc_gnt3);
    n_oc->rok0(n_oc_rok0);
    n_oc->rok1(n_oc_rok1);
    n_oc->rok2(n_oc_rok2);
    n_oc->rok3(n_oc_rok3);
    n_oc->out_val(n_oc_out_val);
    n_oc->out_ack(n_oc_out_ack);
  }
  void s_output_channels_ini(){
    s_oc->clock(clock);
    s_oc->data0(s_oc_data0);
    s_oc->data1(s_oc_data1);
    s_oc->data2(s_oc_data2);
    s_oc->data3(s_oc_data3);
    s_oc->data_out(s_oc_data_out);
    s_oc->req0(s_oc_req0);
    s_oc->req1(s_oc_req1);
    s_oc->req2(s_oc_req2);
    s_oc->req3(s_oc_req3);
    s_oc->gnt0(s_oc_gnt0);
    s_oc->gnt1(s_oc_gnt1);
    s_oc->gnt2(s_oc_gnt2);
    s_oc->gnt3(s_oc_gnt3);
    s_oc->rok0(s_oc_rok0);
    s_oc->rok1(s_oc_rok1);
    s_oc->rok2(s_oc_rok2);
    s_oc->rok3(s_oc_rok3);
    s_oc->out_val(s_oc_out_val);
    s_oc->out_ack(s_oc_out_ack);
  }
  void e_output_channels_ini(){
    e_oc->clock(clock);
    e_oc->data0(e_oc_data0);
    e_oc->data1(e_oc_data1);
    e_oc->data2(e_oc_data2);
    e_oc->data3(e_oc_data3);
    e_oc->data_out(e_oc_data_out);
    e_oc->req0(e_oc_req0);
    e_oc->req1(e_oc_req1);
    e_oc->req2(e_oc_req2);
    e_oc->req3(e_oc_req3);
    e_oc->gnt0(e_oc_gnt0);
    e_oc->gnt1(e_oc_gnt1);
    e_oc->gnt2(e_oc_gnt2);
    e_oc->gnt3(e_oc_gnt3);
    e_oc->rok0(e_oc_rok0);
    e_oc->rok1(e_oc_rok1);
    e_oc->rok2(e_oc_rok2);
    e_oc->rok3(e_oc_rok3);
    e_oc->out_val(e_oc_out_val);
    e_oc->out_ack(e_oc_out_ack);
  }
  void w_output_channels_ini(){
    w_oc->clock(clock);
    w_oc->data0(w_oc_data0);
    w_oc->data1(w_oc_data1);
    w_oc->data2(w_oc_data2);
    w_oc->data3(w_oc_data3);
    w_oc->data_out(w_oc_data_out);
    w_oc->req0(w_oc_req0);
    w_oc->req1(w_oc_req1);
    w_oc->req2(w_oc_req2);
    w_oc->req3(w_oc_req3);
    w_oc->gnt0(w_oc_gnt0);
    w_oc->gnt1(w_oc_gnt1);
    w_oc->gnt2(w_oc_gnt2);
    w_oc->gnt3(w_oc_gnt3);
    w_oc->rok0(w_oc_rok0);
    w_oc->rok1(w_oc_rok1);
    w_oc->rok2(w_oc_rok2);
    w_oc->rok3(w_oc_rok3);
    w_oc->out_val(w_oc_out_val);
    w_oc->out_ack(w_oc_out_ack);
  }
  void l_output_channels_ini(){
    l_oc->clock(clock);
    l_oc->data0(l_oc_data0);
    l_oc->data1(l_oc_data1);
    l_oc->data2(l_oc_data2);
    l_oc->data3(l_oc_data3);
    l_oc->data_out(l_oc_data_out);
    l_oc->req0(l_oc_req0);
    l_oc->req1(l_oc_req1);
    l_oc->req2(l_oc_req2);
    l_oc->req3(l_oc_req3);
    l_oc->gnt0(l_oc_gnt0);
    l_oc->gnt1(l_oc_gnt1);
    l_oc->gnt2(l_oc_gnt2);
    l_oc->gnt3(l_oc_gnt3);
    l_oc->rok0(l_oc_rok0);
    l_oc->rok1(l_oc_rok1);
    l_oc->rok2(l_oc_rok2);
    l_oc->rok3(l_oc_rok3);
    l_oc->out_val(l_oc_out_val);
    l_oc->out_ack(l_oc_out_ack);
  }
  
  void input_channels_ini() {
    n_input_channel_ini();
    s_input_channel_ini();
    e_input_channel_ini();
    w_input_channel_ini();
    l_input_channel_ini();
    
  }
  void output_channels_ini() {
    n_output_channel_ini();
    s_output_channel_ini();
    e_output_channel_ini();
    w_output_channel_ini();
    l_output_channel_ini();
  }
  void exec() {
  }

  SC_CTOR(Router) {
    input_channels_ini();
    output_channels_ini();
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};