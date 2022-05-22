#include "systemc.h"
#include "and.h"

int sc_main (int argc, char* argv[]) {
    sc_signal<sc_lv<32>>  x, y;
    sc_signal<sc_lv<32>>  s;

    AND a("a");
    a.A(x);
    a.B(y);
    a.S(s);
    x.write("1011");
    y.write("1110");
  
    sc_start();
  
    cout << s.read()<<endl;
  
  return 0;
}
