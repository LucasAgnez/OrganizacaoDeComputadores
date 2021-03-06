#include "systemc.h"

SC_MODULE(CTR) {
  	sc_in_clk clock;
  
    sc_in<sc_uint<4>> OP;
    
  	sc_out<sc_uint<1>> regWrite;
  	sc_out<sc_uint<1>> memToReg;
  	sc_out<sc_uint<1>> memWrite;
  	sc_out<sc_uint<1>> memRead;
  	sc_out<sc_uint<1>> aluSrc;
  	sc_out<sc_uint<1>> regDst;
  	sc_out<sc_uint<1>> branch;
  	
  
    void do_ctr() {
      
      switch(OP.read()) {
        case 0: {
          regWrite.write(1);
          memToReg.write(1);
          memWrite.write(0);
          memRead.write(0);
          aluSrc.write(0);
          regDst.write(1);
          branch.write(0);
    	  break;
        }
        case 1: {
          regWrite.write(1);
          memToReg.write(1);
          memWrite.write(0);
          memRead.write(0);
          aluSrc.write(0);
          regDst.write(1);
          branch.write(0);
          break;
        }
        case 2: {
          regWrite.write(1);
          memToReg.write(1);
          memWrite.write(0);
          memRead.write(0);
          aluSrc.write(0);
          regDst.write(1);
          branch.write(0);
          break;
        }
        case 3: {
          regWrite.write(1);
          memToReg.write(1);
          memWrite.write(0);
          memRead.write(0);
          aluSrc.write(0);
          regDst.write(1);
          branch.write(0);
          break;
        }
        case 4: {
          regWrite.write(1);
          memToReg.write(1);
          memWrite.write(0);
          memRead.write(0);
          aluSrc.write(0);
          regDst.write(1);
          branch.write(0);
          break;
        }
        case 5: {
          regWrite.write(1);
          memToReg.write(1);
          memWrite.write(0);
          memRead.write(0);
          aluSrc.write(0);
          regDst.write(1);
          branch.write(0);
          break;
        }
        case 6: {
          regWrite.write(1);
          memToReg.write(1);
          memWrite.write(0);
          memRead.write(0);
          aluSrc.write(0);
          regDst.write(1);
          branch.write(0);
          break;
        }
        case 7: {
          regWrite.write(1);
          memToReg.write(0);
          memWrite.write(0);
          memRead.write(1);
          aluSrc.write(1);
          regDst.write(0);
          branch.write(0);
          break;
        }
        case 8: {
          regWrite.write(0);
          memToReg.write(0); //DC
          memWrite.write(1);
          memRead.write(0);
          aluSrc.write(1);
          regDst.write(0);
          branch.write(0);
          break;
        }
        case 9: {
          regWrite.write(0);
          memToReg.write(0); //DC
          memRead.write(0); //DC
          aluSrc.write(0); //DC
          regDst.write(0); //DC
          branch.write(1);
          break;
        }
        case 10: {
          regWrite.write(0);
          memToReg.write(0); //DC
          memWrite.write(0); //DC
          memRead.write(0); //DC
          aluSrc.write(0);
          regDst.write(0); //DC
          branch.write(1);
          break;
        }
        case 11: {
          regWrite.write(0);
          memToReg.write(0); //DC
          memWrite.write(0); //DC
          memRead.write(0); //DC
          aluSrc.write(0);
          regDst.write(0); //DC
          branch.write(1);
          break;
        }
        default: {
          regWrite.write(0); //DC
          memToReg.write(0); //DC
          memWrite.write(0); //DC
          memRead.write(0); //DC
          aluSrc.write(0); //DC
          regDst.write(0); //DC
          branch.write(0); //DC
          break;
        }
      }
      
    }

    SC_CTOR(CTR) {
      //OP.write(0);
      //regWrite.write(0);
//       memToReg.write(0);
//       memWrite.write(0);
//       memRead.write(0);
//       aluSrc.write(0);
//       regDst.write(0);
//       branch.write(0);
      
      SC_METHOD(do_ctr);
        sensitive << clock.pos();
    }
};
