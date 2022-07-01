#include "systemc.h"

SC_MODULE(ALU) {
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
          if(A.read() == B.read()) {
            S.write(1);
          }
          else{
            S.write(0);
          }
          break;
        }
        case 5: {
          S.write(A.read() + B.read());
          break;
        }
        case 6: {
          S.write(A.read() - B.read());
          break;
        }
        case 7: {
          S.write(A.read() + B.read());
          break;
        }
        case 8: {
          S.write(A.read() + B.read());
          break;
        }
        case 9: {
          S.write(0);
          break;
        }
        case 10: {
          if((A.read() - B.read()) < 0){
            S.write("0");
          }
          break;
        }
        case 11: {
          S.write(A.read() - B.read());
          break;
        }
        
        default: {
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

    SC_CTOR(ALU) {

      SC_METHOD(do_alu);
      sensitive << A << B << OP;
    }
};
