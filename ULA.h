#include "systemc.h"

SC_MODULE(ULA) {
    sc_in<sc_uint<32>> A;
    sc_in<sc_uint<32>> B;
    sc_in<sc_uint<4>> OP;
    sc_out<sc_uint<32>> S;
    sc_out<sc_uint<1>> zero;
    
    

    void do_ula() {
      switch(OP.read()) {
        case 0000: {
          S.write(A.read() & B.read());
            break;
        }
        case 0101: {
          S.write(A.read() + B.read());
            break;
        }
      }
      zero.write(0);
        
   
    }

    SC_CTOR(ULA) {
        SC_METHOD(do_ula);
        sensitive << A << B << OP;
    }
};