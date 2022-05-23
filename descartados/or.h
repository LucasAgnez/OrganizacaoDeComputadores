#include "systemc.h"

SC_MODULE(OR) {
	sc_in<sc_lv<32>> A, B;
	sc_out<sc_lv<32>> S;

	void do_or() {
		S.write(A.read() | B.read());
	}

	SC_CTOR(OR) {
		SC_METHOD(do_or);
		sensitive << A << B;
	}
};
