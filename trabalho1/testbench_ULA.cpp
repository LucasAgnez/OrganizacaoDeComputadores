#include "systemc.h"
#include "ULA.h"

int sc_main (int argc, char* argv[]) {
	sc_signal<sc_uint<32>>  x, y;
  	sc_signal<sc_uint<4>> OP;
	sc_signal<sc_uint<32>>  s;
  	sc_signal<sc_uint<1>> zero;

  	ULA a("ULA");
    a.A(x);
  	a.OP(OP);
  	a.B(y);
    a.S(s);
  	a.zero(zero);  
  	x.write("1111");
  	y.write("1111");
  	OP.write("0000");  
  	//1001 = 9
  	//
  	
  
  
  	sc_start();
  
	cout << s.read() <<endl;
  
  	return 0;
}
