#include "systemc.h"

SC_MODULE(or) {
	sc_in<bool> A, B;
	sc_out<bool> S;

	void do_or() {
		S.write( (A.read() | B.read()) );
	}

	SC_CTOR(or) {
		SC_METHOD(do_or);
		sensitive << A << B;
	}
};
