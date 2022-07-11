#include "systemc.h"

SC_MODULE(Output_Ctr) {
  sc_in_clk clock; 

  sc_in<sc_uint<1>> req0;
  sc_in<sc_uint<1>> req1;
  sc_in<sc_uint<1>> req2;
  sc_in<sc_uint<1>> req3;

  int last_req = 0;

  sc_in<sc_uint<1>> rd;
  
  sc_out<sc_uint<1>> gnt0;
  sc_out<sc_uint<1>> gnt1;
  sc_out<sc_uint<1>> gnt2;
  sc_out<sc_uint<1>> gnt3;

  sc_uint<1> req_present;
  sc_uint<1> selecting;
  sc_uint<1> granting;

  void exec() {
    for(int i = 1; i < 5; ++i) {
      switch((last_req + i) % 4) {
        case 0: {
          if(req0.read() == 1) {
            gnt0.write(1);
            gnt1.write(0);
            gnt2.write(0);
            gnt3.write(0);  
            last_req = (last_req + i) % 4;
            return;
          }
        }
        break;
        case 1: {
          if(req1.read() == 1) {
            gnt0.write(0);
            gnt1.write(1);
            gnt2.write(0);
            gnt3.write(0);
            last_req = (last_req + i) % 4;
            return;
          }
        }
        break;
        case 2: {
          if(req2.read() == 1 ) {
            gnt0.write(0);
            gnt1.write(0);
            gnt2.write(1);
            gnt3.write(0);
            last_req = (last_req + i) % 4;
            return;
          }
        }
        break;
        case 3: {
          if(req3.read() == 1) {
            gnt0.write(0);
            gnt1.write(0);
            gnt2.write(0);
            gnt3.write(1);
            last_req = (last_req + i) % 4;
            return;
          }
        }
        break;
      }    
    }  
  }

  SC_CTOR(Output_Ctr) {
    SC_METHOD(exec);
      sensitive << req0 << req1 << req2 << req3 << rd;
  }
};
