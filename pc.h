#include "systemc.h"

SC_MODULE(PC) {
  	sc_in_clk clock;


	sc_in<sc_uint<5>> inst_address;
  	//sc_in<sc_uint<1>> enable;
 	sc_out<sc_uint<5>> next_inst_address;
  
  	void do_pc
	//	if(enable){
			next_inst_address.write(inst_address);
	//	}
	}

	SC_CTOR(pc){
		SC_METHOD(do_pc);
			sensitive << clock.neg();
			//sensitive << endereco;
	}
};
