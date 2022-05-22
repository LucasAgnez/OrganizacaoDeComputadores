#include "systemc.h"

SC_MODULE(xor) {
	sc_in<sc_lv<32>> A, B;
	sc_out<sc_lv<32>> S;

	void do_xor() {
		S.write( (A.read() ^ B.read()) );
	}

	SC_CTOR(xor) {
		SC_METHOD(do_xor);
		sensitive << A << B;
	}
};
