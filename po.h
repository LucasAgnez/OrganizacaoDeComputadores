#include "systemc.h"
#include "ALU.h"
#include "ctr.h"
#include "reg_mem.h"
#include "inst_mem.h"
#include "data_mem.h"

SC_MODULE(PO) {
  sc_in_clk clock; 
  

  INST_MEM* inst_mem;
  sc_signal<sc_uint<5>> inst_mem_adress;
  sc_signal<sc_uint<24>> inst_mem_data;
  
  ALU* alu;
  sc_signal<sc_uint<32>> alu_x;
  sc_signal<sc_uint<32>> alu_y;
  sc_signal<sc_uint<4>> alu_op;
  sc_signal<sc_uint<32>> alu_s;
  sc_signal<sc_uint<1>> alu_zero;
  
  CTR* ctr;
  sc_signal<sc_uint<1>> ctr_regWrite;
  sc_signal<sc_uint<1>> ctr_memToReg;
  sc_signal<sc_uint<1>> ctr_memWrite;
  sc_signal<sc_uint<1>> ctr_memRead;
  sc_signal<sc_uint<1>> ctr_aluSrc;
  sc_signal<sc_uint<4>> ctr_ctrop;
  
  DATA_MEM* dm;
  sc_signal<sc_uint<5>> data_mem_data_address;
  sc_signal<sc_uint<1>> data_mem_mem_write;
  sc_signal<sc_uint<1>> data_mem_mem_read;
  sc_signal<sc_uint<32>> data_mem_write_data;
  sc_signal<sc_uint<32>> data_mem_data_value;

  REG_MEM* rm;
  sc_signal<sc_uint<5>> reg_mem_r1_address;
  sc_signal<sc_uint<5>> reg_mem_r2_address;
  sc_signal<sc_uint<1>> reg_mem_reg_write;
  sc_signal<sc_uint<5>> reg_mem_write_address;
  sc_signal<sc_uint<32>> reg_mem_write_data;
  sc_signal<sc_uint<32>> reg_mem_r1_value;
  sc_signal<sc_uint<32>> reg_mem_r2_value;

  void int_mem_ini() {
    inst_mem->inst_address(inst_mem_adress);
    inst_mem->inst_data(inst_mem_data);
    inst_mem->clock(clock);
  }
  
  void alu_ini() {
    alu->A(alu_x);
    alu->OP(alu_op);
    alu->B(alu_y);
    alu->S(alu_s);
    alu->zero(alu_zero);
    alu->clock(clock);
  }
  
  void ctr_ini() {
  	ctr->OP(ctr_ctrop);
    ctr->regWrite(ctr_regWrite);
    ctr->memToReg(ctr_memToReg);
    ctr->memWrite(ctr_memWrite);
    ctr->memRead(ctr_memRead);
    ctr->aluSrc(ctr_aluSrc);
    ctr->clock(clock);
  }

  void data_mem_ini() {
    dm->data_address(data_mem_data_address);
    dm->mem_write(data_mem_mem_write);
    dm->mem_read(data_mem_mem_read);
    dm->write_data(data_mem_write_data);
    dm->data_value(data_mem_data_value);
    dm->clock(clock);
  }

  void reg_mem_ini() {
    rm->r1_address(reg_mem_r1_address);
    rm->r2_address(reg_mem_r2_address);
    rm->reg_write(reg_mem_reg_write);
    rm->write_address(reg_mem_write_address);
    rm->write_data(reg_mem_write_data);
    rm->r1_value(reg_mem_r1_value);
    rm->r2_value(reg_mem_r2_value);
    rm->clock(clock);
  }
  
  
  
    void do_po() {
      //Pega os primeiros 4 bits de instrução (opcode) e manda para o Controle
      sc_uint<4> opcode = inst_mem_data.read() >> 20;
      ctr_ctrop.write(opcode);
      
      cout << opcode << endl;
     
      
      //-------DATA MEMORY
      //data_address.
      
      
      //PC: Aumenta endereço da próxima instrução em uma unidade(4 bytes)
      inst_mem_adress.write(inst_mem_adress.read() + 1);
    }

    SC_CTOR(PO) {
      inst_mem = new INST_MEM("INST_MEM");
      alu = new ALU("ALU");
      ctr = new CTR("CTR");
      dm = new DATA_MEM("DATA_MEM");
      rm = new REG_MEM("REG_MEM");
      alu_ini();
      ctr_ini();
      data_mem_ini();
      int_mem_ini();
      reg_mem_ini();
      
      
      
      SC_METHOD(do_po);
        sensitive << clock.pos();
    }
};
