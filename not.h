#include "systemc.h"

SC_MODULE(NOT) {
	sc_in<sc_lv<32>> A;
	sc_out<sc_lv<32>> S;

	void do_not() {
		S.write(~(A.read() ));
	}

	SC_CTOR(NOT) {
		SC_METHOD(do_not);
		sensitive << A ;
	}
};
