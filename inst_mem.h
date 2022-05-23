#include "systemc.h"

SC_MODULE(INST_MEM) {
	sc_in<sc_uint<5>> inst_address;
	sc_out<sc_uint<24>> inst_data;

	sc_uint<32> instructions[128];


    void do_read() {
		do_feacth();
		inst_data.write(instructions[inst_address].read());
    }
  
  	void do_fetch() {
  		instructions[0] = 228645379;
      	instructions[1] = 218645379;
      	instructions[2] = 218645379;
    }

    SC_CTOR(INST_MEM) {
      SC_METHOD(do_read)
        sensitive << inst_address;
    }

};
  