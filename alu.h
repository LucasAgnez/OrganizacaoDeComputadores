#include "systemc.h"

SC_MODULE(alu) {
  	sc_in_clk clock; 
  
    sc_in<sc_uint<5>> A;
    sc_in<sc_uint<5>> B;
    sc_in<sc_uint<4>> OP;
    sc_out<sc_uint<5>> S;
    sc_out<sc_uint<1>> zero;
    
    

    void do_alu() {
      
      switch(OP.read()) {
        case 0: {
          S.write(A.read() & B.read());
            break;
        }
        case 1: {
          S.write(A.read() | B.read());
            break;
        }
        case 2: {
          S.write(A.read() ^ B.read());
            break;
        }
        case 3: {
          S.write(~A.read());
            break;
        }
        case 4: {
          S.write(A.read() + B.read());
            break;
        }
        case 5: {
          S.write(A.read() - B.read());
            break;
        }
      }
      
      if(S.read() == 0){
        zero.write("1");
      }
      else {
        zero.write("0");
      }
    }

    SC_CTOR(alu) {
        SC_METHOD(do_alu);
        sensitive << clock.pos();
    }
};
