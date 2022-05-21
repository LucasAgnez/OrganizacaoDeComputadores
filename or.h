#include "systemc.h"

SC_MODULE(or) {
	sc_in<sc_uint<32>> A, B;
	sc_out<sc_uint<32>> S;

	void do_or() {
		for(int i=; i<32; i++){
			S[i].write( (A[i].read() | B[i].read()) );
		}
	}

	SC_CTOR(or) {
		SC_METHOD(do_or);
		sensitive << A << B;
	}
};
