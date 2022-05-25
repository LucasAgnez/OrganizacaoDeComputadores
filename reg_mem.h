#include "systemc.h"

SC_MODULE(REG_MEM) {
  	sc_in_clk clock;
  
	sc_in<sc_uint<5>> r1_address;
	sc_in<sc_uint<5>> r2_address;
	
	sc_in<sc_uint<1>> reg_write;
	sc_in<sc_uint<5>> write_address;
	sc_in<sc_uint<32>> write_data;
	
	sc_out<sc_uint<32>> r1_value;
	sc_out<sc_uint<32>> r2_value;

	sc_uint<32> registers[32];
	


	void do_read() {
		registers[0] = 0;
		r1_value.write(registers[r1_address.read()]);
		r2_value.write(registers[r2_address.read()]);
	}
  
	void do_write() {
		registers[0] = 0;
		if(reg_write.read() == 1){
			registers[write_address.read()] = write_data.read();
		}
	}

	SC_CTOR(REG_MEM) {
		SC_METHOD(do_read)
			sensitive << clock.pos();
		SC_METHOD(do_write)
			sensitive << clock.pos();
	}

};
