#include "systemc.h"
#include "and.cpp"

int sc_main (int argc, char* argv[]) {
	sc_signal<sc_lv<4>>  x, y;
	sc_signal<sc_lv<4>>  s;
	
  	AND a("AND");
    a.A(x);
    a.B(y);
    a.S(s);
    x.write("1011");
    y.write("1110");
  
  	sc_start();
  
	cout << s.read()<<endl;
  
  return 0;
}
