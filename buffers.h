#include "systemc.h"

SC_MODULE(BufferIfId) {
    sc_in_clk clock; 
  
    sc_in<sc_uint<24>> instruction_in;
    sc_in<sc_uint<5>> next_inst_addres_in;
  
    sc_out<sc_uint<24>> instruction_out;
    sc_out<sc_uint<5>> next_inst_addres_out;
    
    void do_write() {
      instruction_out.write(instruction_in.read());
      next_inst_addres_out.write(next_inst_addres_in.read()+1);
    }

    SC_CTOR(BufferIfId) {
      SC_METHOD(do_write);
        sensitive << clock.neg();
    }
};

SC_MODULE(BufferIdEx) {
  sc_in_clk clock; 

  sc_in<sc_uint<5>> next_inst_addres_in;
  sc_in<sc_uint<5>> rt_in;
  sc_in<sc_uint<5>> desloc_rd_in;
  sc_in<sc_uint<5>> opCode_in;
  sc_in<sc_uint<5>> reg_mem_r1_v_in;
  sc_in<sc_uint<5>> reg_mem_r2_v_in;
  sc_in<sc_uint<1>> ctr_regWrite_in;
  sc_in<sc_uint<1>> ctr_branch_in;
  sc_in<sc_uint<1>> ctr_memToReg_in;
  sc_in<sc_uint<1>> ctr_memWrite_in;
  sc_in<sc_uint<1>> ctr_memRead_in;
  sc_in<sc_uint<1>> ctr_aluSrc_in;
  sc_in<sc_uint<1>> ctr_regDst_in;

  sc_out<sc_uint<5>> next_inst_addres_out;
  sc_out<sc_uint<5>> rt_out;
  sc_out<sc_uint<5>> desloc_rd_out;
  sc_out<sc_uint<5>> opCode_out;
  sc_out<sc_uint<5>> reg_mem_r1_v_out;
  sc_out<sc_uint<5>> reg_mem_r2_v_out;
  sc_out<sc_uint<1>> ctr_regWrite_out;
  sc_out<sc_uint<1>> ctr_branch_out;
  sc_out<sc_uint<1>> ctr_memToReg_out;
  sc_out<sc_uint<1>> ctr_memWrite_out;
  sc_out<sc_uint<1>> ctr_memRead_out;
  sc_out<sc_uint<1>> ctr_aluSrc_out;
  sc_out<sc_uint<1>> ctr_regDst_out;
    
  void do_write() {
    next_inst_addres_out.write(next_inst_addres_in.read());
    rt_out.write(rt_in.read());
    desloc_rd_out.write(desloc_rd_in.read());
    opCode_out.write(opCode_in.read());
    reg_mem_r1_v_out.write(reg_mem_r1_v_in.read());
    reg_mem_r2_v_out.write(reg_mem_r2_v_in.read());
    ctr_regWrite_out.write(ctr_regWrite_in.read());
    ctr_branch_out.write(ctr_branch_in.read());
    ctr_memToReg_out.write(ctr_memToReg_in.read());
    ctr_memWrite_out.write(ctr_memWrite_in.read());
    ctr_memRead_out.write(ctr_memRead_in.read());
    ctr_aluSrc_out.write(ctr_aluSrc_in.read());
    ctr_regDst_out.write(ctr_regDst_in.read());
  }

  SC_CTOR(BufferIdEx) {
    SC_METHOD(do_write);
    sensitive << clock.neg();
  }
};
 
SC_MODULE(BufferExMem) {
  sc_in_clk clock;
  
  sc_in<sc_uint<1>> ctr_regWrite_in;
  sc_in<sc_uint<1>> ctr_branch_in;
  sc_in<sc_uint<1>> ctr_memRead_in;
  sc_in<sc_uint<1>> ctr_memWrite_in;
  sc_in<sc_uint<1>> ctr_memToReg_in;
  sc_in<sc_uint<5>> branch_inst_addres_in;
  sc_in<sc_uint<1>> alu_zero_in;
  sc_in<sc_uint<5>> alu_s_in;
  sc_in<sc_uint<5>> reg_mem_r2_v_in;
  sc_in<sc_uint<5>> reg_mem_write_address_in;
 
  sc_out<sc_uint<1>> ctr_regWrite_out;
  sc_out<sc_uint<1>> ctr_branch_out;
  sc_out<sc_uint<1>> ctr_memRead_out;
  sc_out<sc_uint<1>> ctr_memWrite_out;
  sc_out<sc_uint<1>> ctr_memToReg_out;
  sc_out<sc_uint<5>> branch_inst_addres_out;
  sc_out<sc_uint<1>> alu_zero_out;
  sc_out<sc_uint<5>> alu_s_out;
  sc_out<sc_uint<5>> reg_mem_r2_v_out;
  sc_out<sc_uint<5>> reg_mem_write_address_out;

  void do_write() {
    ctr_regWrite_out.write(ctr_regWrite_in.read());
    ctr_branch_out.write(ctr_branch_in.read());
    ctr_memRead_out.write(ctr_memRead_in.read());
    ctr_memWrite_out.write(ctr_memWrite_in.read());
    ctr_memToReg_out.write(ctr_memToReg_in.read());
    branch_inst_addres_out.write(branch_inst_addres_in.read());
    alu_zero_out.write(alu_zero_in.read());
    alu_s_out.write(alu_s_in.read());
    reg_mem_r2_v_out.write(reg_mem_r2_v_in.read());
    reg_mem_write_address_out.write(reg_mem_write_address_in.read());
  }
 

 SC_CTOR(BufferExMem) {
    SC_METHOD(do_write);
      sensitive << clock.neg();
  }
};

SC_MODULE(BufferMemWb) {
  sc_in_clk clock;
  
  sc_in<sc_uint<1>> ctr_regWrite_in;
  sc_in<sc_uint<5>> reg_mem_write_address_in; 
  sc_in<sc_uint<5>> alu_s_in;
  sc_in<sc_uint<5>> dm_data_value_in;
  
  sc_out<sc_uint<1>> ctr_regWrite_out;
  sc_out<sc_uint<5>> reg_mem_write_address_out; 
  sc_out<sc_uint<5>> alu_s_out;
  sc_out<sc_uint<5>> dm_data_value_out;
  
  void do_write() {
    ctr_regWrite_out.write(ctr_regWrite_in.read());
    reg_mem_write_address_out.write(reg_mem_write_address_in.read()); 
    alu_s_out.write(alu_s_in.read());
    dm_data_value_out.write(dm_data_value_in.read());  
  }
  
  SC_CTOR(BufferMemWb) {
    SC_METHOD(do_write);
      sensitive << clock.neg();
  }
};
  
