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

  Input_Channel *n_ic;
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
  sc_signal<sc_uint<1>> n_ic_rok;

  Output_Channel *n_oc;
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
  sc_signal<sc_uint<1>> n_oc_rd;

  Input_Channel *s_ic;
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
  sc_signal<sc_uint<1>> s_ic_rok;

  Output_Channel *s_oc;
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
  sc_signal<sc_uint<1>> s_oc_rd;

  Input_Channel *e_ic;
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
  sc_signal<sc_uint<1>> e_ic_rok;

  Output_Channel *e_oc;
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
  sc_signal<sc_uint<1>> e_oc_rd;

  Input_Channel *w_ic;
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
  sc_signal<sc_uint<1>> w_ic_rok;

  Output_Channel *w_oc;
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
  sc_signal<sc_uint<1>> w_oc_rd;

  Input_Channel *l_ic;
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
  sc_signal<sc_uint<1>> l_ic_rok;

  Output_Channel *l_oc;
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
  sc_signal<sc_uint<1>> l_oc_rd;

  void n_input_channel_ini() {
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
    n_ic->rok(n_ic_rok);
  }
  void s_input_channel_ini() {
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
    s_ic->rok(s_ic_rok);
  }
  void e_input_channel_ini() {
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
    e_ic->rok(e_ic_rok);
  }
  void w_input_channel_ini() {
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
    w_ic->rok(w_ic_rok);
  }
  void l_input_channel_ini() {
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
    l_ic->rok(l_ic_rok);
  }

  void n_output_channel_ini() {
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
    n_oc->rd(n_oc_rd);
  }
  void s_output_channel_ini() {
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
    s_oc->rd(s_oc_rd);
  }
  void e_output_channel_ini() {
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
    e_oc->rd(e_oc_rd);
  }
  void w_output_channel_ini() {
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
    w_oc->rd(w_oc_rd);
  }
  void l_output_channel_ini() {
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
    l_oc->rd(l_oc_rd);
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
    
        /* North input channel */
    n_ic_data.write(north_data_in.read());
    north_ack_in.write(n_ic_ack.read());
    n_ic_val.write(north_val_in.read());
    // north ic rd
    n_ic_rd0.write(s_oc_rd.read());
    n_ic_rd1.write(e_oc_rd.read());
    n_ic_rd2.write(w_oc_rd.read());
    n_ic_rd3.write(l_oc_rd.read());
    // north ic gnt
    n_ic_gnt0.write(s_oc_gnt3.read());
    n_ic_gnt1.write(e_oc_gnt2.read());
    n_ic_gnt2.write(w_oc_gnt1.read());
    n_ic_gnt3.write(l_oc_gnt0.read());
    /* North output channel */
    north_data_out.write(n_oc_data_out.read());
    n_oc_out_ack.write(north_ack_out.read());
    north_val_out.write(n_oc_out_val.read());
    // north oc rok
    n_oc_rok0.write(s_ic_rok.read());
    n_oc_rok1.write(e_ic_rok.read());
    n_oc_rok2.write(w_ic_rok.read());
    n_oc_rok3.write(l_ic_rok.read());
    // north oc req
    n_oc_req0.write(s_ic_n_req.read());
    n_oc_req1.write(e_ic_n_req.read());
    n_oc_req2.write(w_ic_n_req.read());
    n_oc_req3.write(l_ic_n_req.read());
    // north oc data
    n_oc_data0.write(s_ic_data_out.read());
    n_oc_data1.write(e_ic_data_out.read());
    n_oc_data2.write(w_ic_data_out.read());
    n_oc_data3.write(l_ic_data_out.read());

    
        /* South input channel */
    s_ic_data.write(south_data_in.read());
    south_ack_in.write(s_ic_ack.read());
    s_ic_val.write(south_val_in.read());
    // south ic rd
    s_ic_rd0.write(e_oc_rd.read());
    s_ic_rd1.write(w_oc_rd.read());
    s_ic_rd2.write(l_oc_rd.read());
    s_ic_rd3.write(n_oc_rd.read());
    // south ic gnt
    s_ic_gnt0.write(e_oc_gnt3.read());
    s_ic_gnt1.write(w_oc_gnt2.read());
    s_ic_gnt2.write(l_oc_gnt1.read());
    s_ic_gnt3.write(n_oc_gnt0.read());
    /* South output channel */
    south_data_out.write(s_oc_data_out.read());
    s_oc_out_ack.write(south_ack_out.read());
    south_val_out.write(s_oc_out_val.read());
    // south oc rok
    s_oc_rok0.write(e_ic_rok.read());
    s_oc_rok1.write(w_ic_rok.read());
    s_oc_rok2.write(l_ic_rok.read());
    s_oc_rok3.write(n_ic_rok.read());
    // south oc req
    s_oc_req0.write(e_ic_s_req.read());
    s_oc_req1.write(w_ic_s_req.read());
    s_oc_req2.write(l_ic_s_req.read());
    s_oc_req3.write(n_ic_s_req.read());
    // south oc data
    s_oc_data0.write(e_ic_data_out.read());
    s_oc_data1.write(w_ic_data_out.read());
    s_oc_data2.write(l_ic_data_out.read());
    s_oc_data3.write(n_ic_data_out.read());


        /* East input channel */
    e_ic_data.write(east_data_in.read());
    east_ack_in.write(e_ic_ack.read());
    e_ic_val.write(east_val_in.read());
    // east ic rd
    e_ic_rd0.write(w_oc_rd.read());
    e_ic_rd1.write(l_oc_rd.read());
    e_ic_rd2.write(n_oc_rd.read());
    e_ic_rd3.write(s_oc_rd.read());
    // east ic gnt
    e_ic_gnt0.write(w_oc_gnt3.read());
    e_ic_gnt1.write(l_oc_gnt2.read());
    e_ic_gnt2.write(n_oc_gnt1.read());
    e_ic_gnt3.write(s_oc_gnt0.read());
    /* East output channel */
    east_data_out.write(e_oc_data_out.read());
    e_oc_out_ack.write(east_ack_out.read());
    east_val_out.write(e_oc_out_val.read());
    // east oc rok
    e_oc_rok0.write(w_ic_rok.read());
    e_oc_rok1.write(l_ic_rok.read());
    e_oc_rok2.write(n_ic_rok.read());
    e_oc_rok3.write(s_ic_rok.read());
    // east oc req
    e_oc_req0.write(w_ic_e_req.read());
    e_oc_req1.write(l_ic_e_req.read());
    e_oc_req2.write(n_ic_e_req.read());
    e_oc_req3.write(s_ic_e_req.read());
    // east oc data
    e_oc_data0.write(w_ic_data_out.read());
    e_oc_data1.write(l_ic_data_out.read());
    e_oc_data2.write(n_ic_data_out.read());
    e_oc_data3.write(s_ic_data_out.read());


        /* West input channel */
    w_ic_data.write(west_data_in.read());
    west_ack_in.write(w_ic_ack.read());
    w_ic_val.write(west_val_in.read());
    // west ic rd
    w_ic_rd0.write(l_oc_rd.read());
    w_ic_rd1.write(n_oc_rd.read());
    w_ic_rd2.write(s_oc_rd.read());
    w_ic_rd3.write(e_oc_rd.read());
    // west ic gnt
    w_ic_gnt0.write(l_oc_gnt3.read());
    w_ic_gnt1.write(n_oc_gnt2.read());
    w_ic_gnt2.write(s_oc_gnt1.read());
    w_ic_gnt3.write(e_oc_gnt0.read());
    /* West output channel */
    west_data_out.write(w_oc_data_out.read());
    w_oc_out_ack.write(west_ack_out.read());
    west_val_out.write(w_oc_out_val.read());
    // west oc rok
    w_oc_rok0.write(l_ic_rok.read());
    w_oc_rok1.write(n_ic_rok.read());
    w_oc_rok2.write(s_ic_rok.read());
    w_oc_rok3.write(e_ic_rok.read());
    // west oc req
    w_oc_req0.write(l_ic_w_req.read());
    w_oc_req1.write(n_ic_w_req.read());
    w_oc_req2.write(s_ic_w_req.read());
    w_oc_req3.write(e_ic_w_req.read());
    // west oc data
    w_oc_data0.write(l_ic_data_out.read());
    w_oc_data1.write(n_ic_data_out.read());
    w_oc_data2.write(s_ic_data_out.read());
    w_oc_data3.write(e_ic_data_out.read());


        /* Local input channel */
    l_ic_data.write(local_data_in.read());
    local_ack_in.write(l_ic_ack.read());
    l_ic_val.write(local_val_in.read());
    // local ic rd
    l_ic_rd0.write(n_oc_rd.read());
    l_ic_rd1.write(s_oc_rd.read());
    l_ic_rd2.write(e_oc_rd.read());
    l_ic_rd3.write(w_oc_rd.read());
    // local ic gnt
    l_ic_gnt0.write(n_oc_gnt3.read());
    l_ic_gnt1.write(s_oc_gnt2.read());
    l_ic_gnt2.write(e_oc_gnt1.read());
    l_ic_gnt3.write(w_oc_gnt0.read());
    /* Local output channel */
    local_data_out.write(l_oc_data_out.read());
    l_oc_out_ack.write(local_ack_out.read());
    local_val_out.write(l_oc_out_val.read());
    // local oc rok
    l_oc_rok0.write(n_ic_rok.read());
    l_oc_rok1.write(s_ic_rok.read());
    l_oc_rok2.write(e_ic_rok.read());
    l_oc_rok3.write(w_ic_rok.read());
    // local oc req
    l_oc_req0.write(n_ic_l_req.read());
    l_oc_req1.write(s_ic_l_req.read());
    l_oc_req2.write(e_ic_l_req.read());
    l_oc_req3.write(w_ic_l_req.read());
    // local oc data
    l_oc_data0.write(n_ic_data_out.read());
    l_oc_data1.write(s_ic_data_out.read());
    l_oc_data2.write(e_ic_data_out.read());
    l_oc_data3.write(w_ic_data_out.read());
    
  }

  SC_CTOR(Router) {
    n_ic = new Input_Channel("N_Input_Channel");
    n_oc = new Output_Channel("N_Output_Channel");
    s_ic = new Input_Channel("S_Input_Channel");
    s_oc = new Output_Channel("S_Output_Channel");
    e_ic = new Input_Channel("E_Input_Channel");
    e_oc = new Output_Channel("E_Output_Channel");
    w_ic = new Input_Channel("W_Input_Channel");
    w_oc = new Output_Channel("W_Output_Channel");
    l_ic = new Input_Channel("L_Input_Channel");
    l_oc = new Output_Channel("L_Output_Channel");
    input_channels_ini();
    output_channels_ini();
    SC_METHOD(exec);
    sensitive << clock.pos();
  }
};