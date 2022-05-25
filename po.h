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

        sc_signal<sc_uint<32>> x;
        sc_signal<sc_uint<32>> y;
        sc_signal<sc_uint<4>> ulaop;
        sc_signal<sc_uint<32>> s;
        sc_signal<sc_uint<1>> zero;

        ALU a("ALU");
        a.A(x);
        a.OP(ulaop);
        a.B(y);
        a.S(s);
        a.zero(zero);

        sc_signal<sc_uint<1>> regWrite;
        sc_signal<sc_uint<1>> memToReg;
        sc_signal<sc_uint<1>> memWrite;
        sc_signal<sc_uint<1>> memRead;
        sc_signal<sc_uint<1>> aluSrc;
        sc_signal<sc_uint<4>> ctrop;

        CTR ctr("CTR");
        ctr.OP(ctrop);
        ctr.regWrite(regWrite);
        ctr.memToReg(memToReg);
        ctr.memWrite(memWrite);
        ctr.memRead(memRead);
        ctr.aluSrc(aluSrc);

        // ctrop.write(inst_data.

        sc_signal<sc_uint<5>> data_address;
        sc_signal<sc_uint<1>> mem_write;
        sc_signal<sc_uint<1>> mem_read;
        sc_signal<sc_uint<32>> write_data;
        sc_signal<sc_uint<32>> data_value;

        DATA_MEM dm("DATA MEM");
        dm.data_address(data_address);
        dm.mem_write.(mem_write);
        dm.mem_read.(mem_read);
        dm.write_data.(write_data);
        dm.data_value.(data_value);

        
        sc_signal<sc_uint<5>> r1_address;
        sc_signal<sc_uint<5>> r2_address;
        sc_signal<sc_uint<1>> reg_write;
        sc_signal<sc_uint<5>> write_address;
        sc_signal<sc_uint<32>> write_data;
        sc_signal<sc_uint<32>> r1_value;
        sc_signal<sc_uint<32>> r2_value;
        
        REG_MEM rm("REG MEM");
        rm.r1_address(r1_address);
        rm.r2_address(r2_address);
        rm.reg_write(reg_write);
        rm.write_address(write_address);
        rm.write_data(write_data);
        rm.r1_value(r1_value);
        rm.r2_value(r2_value);
      
      
    }

    SC_CTOR(PO) {
        SC_METHOD(do_po);
        sensitive << A << B << OP;
    }
};
