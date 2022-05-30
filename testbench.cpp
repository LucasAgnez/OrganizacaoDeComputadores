#include "systemc.h"
#include "processor.h"


int sc_main (int argc, char* argv[]) {
  	sc_signal<bool> clock;

    PROCESSOR a("PROCESSOR");
  	a.clock(clock);

  	// Open VCD file
    sc_trace_file *wf = sc_create_vcd_trace_file("processor");
    // Dump the desired signals
    sc_trace(wf, clock, "clock");

  	for(int i = 0; i<6; i++) {
      clock = 1;
      sc_start(100, SC_NS);
      clock = 0;
      sc_start(100, SC_NS);
      cout << "---------------------" << endl;
    }


    //sc_start(1, SC_SEC);



  return 0;
}
