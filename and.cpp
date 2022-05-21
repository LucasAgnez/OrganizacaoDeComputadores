#include "systemc.h"

SC_MODULE(and) {
	sc_in<sc_uint<32>> A, B;
	sc_out<sc_uint<32>> CO;

	void do_and() {
		for(int i=0; i<32; i++){
			CO[i].write( (A[i].read() && B[i].read()) );
		}
	}

	SC_CTOR(and) {
		SC_METHOD(do_and);
		sensitive << A << B;
	}
};
