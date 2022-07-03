#include "systemc.h"

SC_MODULE(Input_Read_Switch) {
  sc_in_clk clock; 
  

  SC_CTOR(Input_Read_Switch) {
    SC_METHOD(exec);
      sensitive << clock.pos();
  }
};