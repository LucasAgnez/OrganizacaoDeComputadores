#include "systemc.h"

SC_MODULE(and) {
	sc_in<bool> A, B;
	sc_out<bool> CO;

	void do_and() {
		CO.write( (A.read() && B.read()) );
	}

	SC_CTOR(and) {
		SC_METHOD(do_and);
		sensitive << A << B;
	}
};
