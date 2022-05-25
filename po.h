#include "systemc.h"
#include "ALU.h"
#include "ctr.h"
#include "reg_mem.h"
#include "inst_mem.h"
#include "data_mem.h"

SC_MODULE(PO) {
  sc_in_clk clock; 
  
  INST_MEM inst_mem("INST_MEM");
  sc_signal<sc_uint<5>> inst_mem_adress;
  sc_signal<sc_uint<24>> inst_mem_data;
  
  ALU alu("ALU");
  sc_signal<sc_uint<32>> alu_x;
  sc_signal<sc_uint<32>> alu_y;
  sc_signal<sc_uint<4>> alu_op;
  sc_signal<sc_uint<32>> alu_s;
  sc_signal<sc_uint<1>> alu_zero;
  
  CTR ctr("CTR");
  sc_signal<sc_uint<1>> ctr_regWrite;
  sc_signal<sc_uint<1>> ctr_memToReg;
  sc_signal<sc_uint<1>> ctr_memWrite;
  sc_signal<sc_uint<1>> ctr_memRead;
  sc_signal<sc_uint<1>> ctr_aluSrc;
  sc_signal<sc_uint<4>> ctr_ctrop;
  
  DATA_MEM dm("DATA MEM");
  sc_signal<sc_uint<5>> data_mem_data_address;
  sc_signal<sc_uint<1>> data_mem_mem_write;
  sc_signal<sc_uint<1>> data_mem_mem_read;
  sc_signal<sc_uint<32>> data_mem_write_data;
  sc_signal<sc_uint<32>> data_mem_data_value;

  REG_MEM rm("REG MEM");
  sc_signal<sc_uint<5>> reg_mem_r1_address;
  sc_signal<sc_uint<5>> reg_mem_r2_address;
  sc_signal<sc_uint<1>> reg_mem_reg_write;
  sc_signal<sc_uint<5>> reg_mem_write_address;
  sc_signal<sc_uint<32>> reg_mem_write_data;
  sc_signal<sc_uint<32>> reg_mem_r1_value;
  sc_signal<sc_uint<32>> reg_mem_r2_value;

  void int_mem_ini() {
    inst_mem.inst_address(inst_mem_adress);
    inst_mem.inst_data(inst_mem_data);
    inst_mem.clock(clock);
  }
  
  void alu_ini() {
    alu.A(alu_x);
    alu.OP(alu_op);
    alu.B(alu_y);
    alu.S(alu_s);
    alu.zero(alu_zero);
  }
  
  void ctr_ini() {
  	ctr.OP(ctrop);
    ctr.regWrite(ctr_regWrite);
    ctr.memToReg(ctr_memToReg);
    ctr.memWrite(ctr_memWrite);
    ctr.memRead(ctr_memRead);
    ctr.aluSrc(ctr_aluSrc);
  }

  void data_mem_ini() {
    dm.data_address(data_mem_data_address);
    dm.mem_write(data_mem_mem_write);
    dm.mem_read(data_mem_mem_read);
    dm.write_data(data_mem_write_data);
    dm.data_value(data_mem_data_value);
  }

  void data_reg_ini() {
    rm.r1_address(reg_mem_r1_address);
    rm.r2_address(reg_mem_r2_address);
    rm.reg_write(reg_mem_reg_write);
    rm.write_address(reg_mem_write_address);
    rm.write_data(reg_mem_write_data);
    rm.r1_value(reg_mem_r1_value);
    rm.r2_value(reg_mem_r2_value);
  }
  
  
  
    void do_po() {
      //inst_address.write(0);
      // ctrop.write(inst_data.  
    }

    SC_CTOR(PO) {
      SC_METHOD(do_po);
        sensitive << clock.pos();
    }
};
