#include "systemc.h"

SC_MODULE(equals) {
	sc_in<bool> A, B;
	sc_out<bool> S;

	void do_equals() {
		if (A == B){
      S.write(true);
    }
    else{
      S.write(false);
    }
	}

	SC_CTOR(equals) {
		SC_METHOD(equals);
		sensitive << A << B;
	}
};
