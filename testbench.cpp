#include "systemc.h"
#include "ULA.h"
#include "ctr.h"

int sc_main (int argc, char* argv[]) {
  	sc_signal<bool> clock;
  
  	sc_signal<sc_uint<32>> x, y;
  	sc_signal<sc_uint<4>> op;
  	sc_signal<sc_uint<1>> z;
    sc_signal<sc_uint<32>>  s;
  
    ULA a("a");
    a.A(x);
    a.B(y);
    a.S(s);
  	a.OP(op);
  	a.zero(z);
  	a.clock(clock);
  
  	// Open VCD file
    sc_trace_file *wf = sc_create_vcd_trace_file("processor");
    // Dump the desired signals
    sc_trace(wf, clock, "clock");
  	sc_trace(wf, x, "x");
    sc_trace(wf, y, "y");
  	sc_trace(wf, s, "s");
  
  	int j, k;
  	j = 5;
  	k = 6;
  	op.write(4);
  	x.write(j);
  	y.write(k);
  	for(int i=0; i<5; i++) {
      clock = 0; 
      sc_start(1, SC_NS);
      clock = 1; 
      x.write(j++);
      y.write(k++);
      sc_start(1, SC_NS);
      cout << s.read()<<endl;
    }
    
  	
  	
    //sc_start(1, SC_SEC);
  
    
  
  return 0;
}
