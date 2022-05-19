#include "systemc.h"

SC_MODULE(xor) {
	sc_in<bool> A, B;
	sc_out<bool> S;

	void do_xor() {
		S.write( (A.read() ^ B.read()) );
	}

	SC_CTOR(xor) {
		SC_METHOD(do_xor);
		sensitive << A << B;
	}
};
