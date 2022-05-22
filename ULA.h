#include "systemc.h"

SC_MODULE(ULA) {
    sc_in<sc_uint<32>> A;
    sc_in<sc_uint<32>> B;
    sc_in<sc_uint<4>> OP;
    sc_out<sc_uint<32>> S;
    sc_out<sc_uint<1>> zero;
    
    

    void do_ula() {
      zero.write("0");
      switch(OP.read()) {
        case 0000: {
          S.write(A.read() & B.read());
            break;
        }
        case 0001: {
          S.write(A.read() | B.read());
            break;
        }
        case 0010: {
          S.write(A.read() ^ B.read());
            break;
        }
        case 0011: {
          S.write(~A.read());
            break;
        }
        case 0100: {
            if (A == B){
                zero.write("1");
            }
        }
        case 0101: {
          S.write(A.read() + B.read());
            break;
        }
        case 0110: {
          S.write(A.read() - B.read());
            break;
        }
        case 0111: {
            \\leitura
            break;
        }
        case 1000: {
            \\escrita
            break;
        }
        case 1001: {
            \\salto inc
            break;
        }  
        case 1010: {
            \\salto neg
            break;
        }
        case 1011: {
            \\salto zero
            break;
        }
      }
    }

    SC_CTOR(ULA) {
        SC_METHOD(do_ula);
        sensitive << A << B << OP;
    }
};
