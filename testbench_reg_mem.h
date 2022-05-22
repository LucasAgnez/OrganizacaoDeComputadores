#include "systemc.h"
#include "reg_mem.h"

int sc_main (int argc, char* argv[]) {
	sc_signal<sc_uint<32>>  x, y;
  	sc_signal<sc_uint<5>> r1_a, r2_a, w_a;
	sc_signal<sc_uint<32>>  r1_v, r2_v, w_d;
  	sc_signal<sc_uint<1>> reg_write;

  	REG_MEM a("REG_MEM");
  	
  	a.r1_address(r1_a);
  	a.r2_address(r2_a);
  	a.reg_write(reg_write);
    a.r1_value(r1_v);
  	a.r2_value(r2_v);
  	a.write_address(w_a);
  	a.write_data(w_d);
  	
  	
  	r1_a.write(0);
  	r2_a.write(1);
  	reg_write.write(0);
  	w_a.write(0);
  
	cout << r1_v.read() << " " << r2_v.read() << endl;
  
  
  	reg_write.write(1);
  	w_d.write(666);
	w_a.write(1);
  	cout << r1_v.read() << " " << r2_v.read() << endl;
  	sc_start();  
  
  	return 0;
}
