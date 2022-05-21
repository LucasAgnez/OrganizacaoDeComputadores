#include "systemc.h"

SC_MODULE(not) {
	sc_out<sc_uint<32>> A;
	sc_out<sc_uint<32>> S;

	void do_not() {
		for(int i=0; i<32; i++){
			S[i].write(~(A[i].read() ));
		}
	}

	SC_CTOR(not) {
		SC_METHOD(do_not);
		sensitive << A ;
	}
};
