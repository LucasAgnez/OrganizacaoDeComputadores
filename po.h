#include "systemc.h"
#include "ALU.h"
#include "ctr.h"
#include "reg_mem.h"
#include "inst_mem.h"
#include "data_mem.h"
#include "buffers.h"
#include "pc.h"

SC_MODULE(PO) {
  sc_in_clk clock;


  PC* pc;
  sc_signal<sc_uint<5>> inst_address;
  //sc_signal<sc_uint<1>> enable;
  sc_signal<sc_uint<5>> next_inst_address;

  INST_MEM* inst_mem;
  //sc_signal<sc_uint<5>> inst_mem_adress;
  sc_signal<sc_uint<24>> inst_mem_data;

  ALU* alu;
  sc_signal<sc_uint<5>> alu_x;
  sc_signal<sc_uint<5>> alu_y;
  //sc_signal<sc_uint<4>> alu_op;
  sc_signal<sc_uint<5>> alu_s;
  sc_signal<sc_uint<1>> alu_zero;

  CTR* ctr;
  sc_signal<sc_uint<1>> ctr_regWrite;
  sc_signal<sc_uint<1>> ctr_memToReg;
  sc_signal<sc_uint<1>> ctr_memWrite;
  sc_signal<sc_uint<1>> ctr_branch;
  sc_signal<sc_uint<1>> ctr_memRead;
  sc_signal<sc_uint<1>> ctr_aluSrc;
  sc_signal<sc_uint<1>> ctr_regDst;
  sc_signal<sc_uint<4>> ctr_ctrop;


  DATA_MEM* dm;
  sc_signal<sc_uint<5>> data_mem_data_address;
  sc_signal<sc_uint<1>> data_mem_mem_write;
  sc_signal<sc_uint<1>> data_mem_mem_read;
  sc_signal<sc_uint<5>> data_mem_write_data;
  sc_signal<sc_uint<5>> data_mem_data_value;

  REG_MEM* rm;
  sc_signal<sc_uint<5>> reg_mem_r1_address;
  sc_signal<sc_uint<5>> reg_mem_r2_address;
  sc_signal<sc_uint<1>> reg_mem_reg_write;
  sc_signal<sc_uint<5>> reg_mem_write_address;
  sc_signal<sc_uint<5>> reg_mem_write_data;
  sc_signal<sc_uint<5>> reg_mem_r1_value;
  sc_signal<sc_uint<5>> reg_mem_r2_value;

  sc_uint<1> pcSrc;

  void pc_ini() {
    pc->inst_address(inst_address);
    //pc->enable(enable);
    pc->next_inst_address(next_inst_address);
    pc->clock(clock);
  }

  void int_mem_ini() {
    inst_mem->inst_address(next_inst_address);
    inst_mem->inst_data(inst_mem_data);
    inst_mem->clock(clock);
    inst_mem_adress.write(0);
  }

  void alu_ini() {
    alu->OP(bff2_opcode_out);
    alu->A(alu_x);
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
    ctr->branch(ctr_branch);
    ctr->memRead(ctr_memRead);
    ctr->aluSrc(ctr_aluSrc);
    ctr->regDst(ctr_regDst);
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

  BufferIfId* bff1;

  BufferIdEx* bff2;
  sc_signal<sc_uint<4>> bff2_opcode;
  sc_signal<sc_uint<5>> bff2_rt;
  sc_signal<sc_uint<5>> bff2_rd_desloc;

  sc_signal<sc_uint<5>> bff2_next_inst_addres_out;
  sc_signal<sc_uint<5>> bff2_rt_out;
  sc_signal<sc_uint<5>> bff2_desloc_rd_out;
  sc_signal<sc_uint<4>> bff2_opCode_out;
  sc_signal<sc_uint<5>> bff2_reg_mem_r2_v_out;
  sc_signal<sc_uint<4>> bff2_opcode_out;
  sc_signal<sc_uint<1>> bff2_ctr_regWrite;
  sc_signal<sc_uint<1>> bff2_ctr_branch;
  sc_signal<sc_uint<1>> bff2_ctr_memToReg;
  sc_signal<sc_uint<1>> bff2_ctr_memWrite;
  sc_signal<sc_uint<1>> bff2_ctr_memRead;
  sc_signal<sc_uint<1>> bff2_ctr_aluSrc;
  sc_signal<sc_uint<1>> bff2_ctr_regDst;


  BufferExMem* bff3;
  sc_signal<sc_uint<5>> bff3_reg_mem_write_address_in;
  sc_signal<sc_uint<5>> bff3_branch_inst_addres_in;

  BufferMemWb* bff4;

  void bff1_ini() {
  	bff1->instruction_in(inst_mem_data);
    bff1->next_inst_addres_in(next_inst_address);
    bff1->instruction_out(instruction_out);
    bff1->next_inst_addres_out(next_inst_addres_out);
    bff1->clock(clock);
  }

  void bff2_ini() {
  	bff2->next_inst_addres_in(next_inst_addres_out);
    bff2->rt_in(bff2_rt);
    bff2->desloc_rd_in(bff2_rd_desloc);
    bff2->opCode_in(bff2_opcode);
    bff2->reg_mem_r1_v_in(reg_mem_r1_value);
    bff2->reg_mem_r2_v_in(reg_mem_r2_value);
    bff2->ctr_regWrite_in(ctr_regWrite);
    bff2->ctr_memToReg_in(ctr_memToReg);
    bff2->ctr_memWrite_in(ctr_memWrite);
    bff2->ctr_branch_in(ctr_branch);
    bff2->ctr_memRead_in(ctr_memRead);
    bff2->ctr_aluSrc_in(ctr_aluSrc);
    bff2->ctr_regDst_in(ctr_regDst);

    bff2->next_inst_addres_out(bff2_next_inst_addres_out);
    bff2->rt_out(bff2_rt_out);
    bff2->desloc_rd_out(bff2_desloc_rd_out);
    bff2->opCode_out(bff2_opcode_out);
    bff2->reg_mem_r1_v_out(alu_x);
    bff2->reg_mem_r2_v_out(bff2_reg_mem_r2_v_out);
    bff2->ctr_regWrite_out(bff2_ctr_regWrite);
    bff2->ctr_branch_out(bff2_ctr_branch);
    bff2->ctr_memToReg_out(bff2_ctr_memToReg);
    bff2->ctr_memWrite_out(bff2_ctr_memWrite);
    bff2->ctr_memRead_out(bff2_ctr_memRead);
    bff2->ctr_aluSrc_out(bff2_ctr_aluSrc);
    bff2->ctr_regDst_out(bff2_ctr_regDst);
  }

  void bff3_ini(){
    bff3->ctr_regWrite_in(bff2_ctr_regWrite);
    bff3->ctr_branch_in(bff2_ctr_branch);
    bff3->ctr_memRead_in(bff2_ctr_memRead);
    bff3->ctr_memWrite_in(bff2_ctr_memWrite);
    bff3->ctr_memToReg_in(bff2_ctr_memToReg);
    bff3->branch_inst_addres_in(bff3_branch_inst_addres_in);
    bff3->alu_zero_in(alu_zero);
    bff3->alu_s_in(alu_s);
    bff3->reg_mem_r2_v_in(bff2_reg_mem_r2_v_out);
    bff3->reg_mem_write_address_in(bff3_reg_mem_write_address_in);

    bff3->ctr_regWrite_out(data_mem_mem_write);
    bff3->ctr_branch_out();
    bff3->ctr_memRead_out(data_mem_mem_read);
    bff3->ctr_memWrite_out();
    bff3->ctr_memToReg_out();
    bff3->branch_inst_addres_out();
    bff3->alu_zero_out();
    bff3->alu_s_out(data_mem_data_address);
    bff3->reg_mem_r2_v_out(data_mem_write_data);
    bff3->reg_mem_write_address_out();
  }
  
  void bff4_ini() {
    bff4->ctr_regWrite_in();
    bff4->reg_mem_write_address_in(); 
    bff4->alu_s_in();
    bff4->dm_data_value_in();
    bff4->ctr_regWrite_out();
    bff4->reg_mem_write_address_out(); 
    bff4->alu_s_out();
    bff4->dm_data_value_out();
  }



  inst_mem_adress;


  void decode_instruction(sc_uint<24> instruction, sc_uint<4>* opcode, sc_uint<5>* rt, sc_uint<5>* rs, sc_uint<5>* desloc_rd) {

    //Bits [23-20] (opcode)
    *opcode = instruction >> 20;
    //Bits [19-15]
    *rt = inst_mem_data.read() >> 15;
    //Bits [14-10]
    *rs = inst_mem_data.read() >> 10;
    //Bits [9-5]
    *desloc_rd = inst_mem_data.read() >> 5;
  }










    void do_po() {
      //INSTRUCTION FETCH


      //INSTRUCTION DECODE

      //Divide bits da instrução
      sc_uint<4> opcode;
      sc_uint<5> rg_r1_address;
      sc_uint<5> rg_r2_address;
      sc_uint<5> desloc_rd;
      decode_instruction(instruction_out.read(), &opcode, &rg_r1_address, &rg_r2_address,
                         &desloc_rd);
      cout << "opcode: " << opcode << endl;
      cout << "clock: " << clock << endl;


      //Control
      ctr_ctrop.write(opcode);


      //Registers bank
      // Seta entradas de controle do banco de registradores
      reg_mem_reg_write.write(bff4.ctr_regWrite);

      reg_mem_write_address.write(bff4.reg_mem_write_address);
      //reg_mem_write_data.write(data_mem_data_value.read());

      reg_mem_r1_address.write(rg_r1_address);
      reg_mem_r2_address.write(rg_r2_address);



      //BUFFER ID/EX
      bff2_opcode.write(opcode);

      bff2_rt.write(rg_r1_address);
      bff2_rd_desloc.write(desloc_rd);



      //EXECUTION

      //ALU
      //alu_op.write(bff2.opCode);
      cout << "bff2 opCode: " << bff2_opcode.read() << endl;
      cout << "bff2 register mem value 1: " << reg_mem_r1_value.read() << endl;

      //alu_x.write(bff2.reg_mem_r1_v);

      /*MUX para decidir segunda entrada da ULA (ou um endereço da memória de dados,
      ou a segunda saída do banco de registradores)*/
      if(bff2_ctr_aluSrc.read() == 1) {
        alu_y.write(bff2_desloc_rd_out.read());
      }
      else {
      	alu_y.write(bff2_reg_mem_r2_v_out.read());
      }


      /*MUX para decidir se o endereço de escrita no banco de registradores (na etapa WB)
      vem do "rt" ou do "desloc_rd"*/
      if(bff2_ctr_regDst.read() == 1) {
        bff3_reg_mem_write_address_in.write(bff2_desloc_rd_out.read());
      }
      else {
      	bff3_reg_mem_write_address_in.write(bff2_rt_out.read());
      }



      //BUFFER EX/MEM
      bff3_branch_inst_addres_in.write(bff2_next_inst_addres_out.read() + bff2_desloc_rd_out.read());

      //bff3.alu_zero = alu_zero.read();
      //bff3.alu_s = alu_s.read();
      //bff3.reg_mem_r2_v = bff2.reg_mem_r2_v;



      //MEMORY



      //Data Memory
      // Seta entradas de controle do banco de dados
      data_mem_mem_read.write(bff3.ctr_memRead);
      data_mem_mem_write.write(bff3.ctr_memWrite);

      //cout << "ctr_memRead: " << ctr_memRead.read() << endl;
      cout << "ctr_memRead: " << ctr_memRead.read() << endl;

      //data_mem_data_address.write(bff3.alu_s);
      //data_mem_write_data.write(bff3.reg_mem_r2_v);


      pcSrc = bff3.ctr_branch & bff3.alu_zero;



      //BUFFER MEM/WB
      bff4.ctr_regWrite = bff3.ctr_regWrite;
      bff4.reg_mem_write_address = bff3.reg_mem_write_address;
      bff4.alu_s = bff3.alu_s;
      bff4.dm_data_value = data_mem_data_value.read();



      //WRITE BACK
      if(ctr_memToReg.read() == 1) {
      	 reg_mem_write_data.write(bff4.alu_s);
      }
      else {
      	reg_mem_write_data.write(bff4.dm_data_value);
      }

      reg_mem_reg_write.write(bff4.ctr_regWrite);
      reg_mem_write_address.write(bff4.reg_mem_write_address);

      if(pcSrc == 1) {
        inst_address.write(bff3.branch_inst_addres);
        //inst_mem_adress.write(bff3.branch_inst_addres);
      }
      else {
        inst_address.write(inst_mem_adress.read() + 1);
      	//inst_mem_adress.write(inst_mem_adress.read() + 1);
      }


    }

    SC_CTOR(PO) {
      pc = new PC("PC");
      inst_mem = new INST_MEM("INST_MEM");
      alu = new ALU("ALU");
      ctr = new CTR("CTR");
      dm = new DATA_MEM("DATA_MEM");
      rm = new REG_MEM("REG_MEM");
      bff1 = new BufferIfId("BufferIfId");
      pc_ini();
      bff1_ini();
      alu_ini();
      ctr_ini();
      data_mem_ini();
      int_mem_ini();
      reg_mem_ini();
      pcSrc = 0;

      SC_METHOD(do_po);
        sensitive << clock.pos();
    }

};
