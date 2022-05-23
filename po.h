#include "systemc.h"
#include "ULA.h"
#include "ctr.h"
#include "reg_mem.h"
#include "inst_mem.h"
#include "data_mem.h"

SC_MODULE(PO) {

    void do_po() {
      sc_signal<sc_uint<5>> inst_address;
      sc_signal<sc_uint<24>> inst_data;
      
      INST_MEM inst_mem("INST_MEM");
      inst_mem.inst_address(inst_address);
      inst_mem.inst_data(inst_data);
      inst_address.write(0);
      
      
      sc_signal<sc_uint<4>> OP;
      CTR ctr("CTR");
      ctr.OP(OP);
      op.write(inst_data.
      
      
      
    }

    SC_CTOR(ULA) {
        SC_METHOD(do_po);
        sensitive << A << B << OP;
    }
};
