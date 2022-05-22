#include "systemc.h"

SC_MODULE(and) {
	sc_in<sc_lv<32>> A, B;
	sc_out<sc_lv<32>> S;
	
	void do_and() {
		S.write( (A.read() & B.read()) );
	}

	SC_CTOR(and) {
		SC_METHOD(do_and);
		sensitive << A << B;
	}
};
