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
    alu->OP(alu_op);
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
  
  void decode_instruction(sc_uint<24> instruction, sc_uint<4>* opcode, sc_uint<5>* rt, sc_uint<5>* rs, sc_uint<5>* desloc_rd) {
  	
    //Bits [23-20] (opcode) 
    *opcode = instruction >> 20;
    //Bits [19-15]
    *rt = inst_mem_data.read() >> 15;
    //Bits [14-10]
    *rs = inst_mem_data.read() >> 10;
    //Bits [9-5]
    *desloc_rd = inst_mem_data.read() >> 5;
    
    switch(*opcode) {
        case 7: {
          //Bits [19-15]
          *rt = inst_mem_data.read() >> 15;
          //Bits [14-10]
          *rs = inst_mem_data.read() >> 10;
          //Bits [9-5]
          *desloc_rd = inst_mem_data.read() >> 5;
          break;
        }
        case 8: {
          //Bits [19-15]
          *rt = inst_mem_data.read() >> 15;
          //Bits [14-10]
          *rs = inst_mem_data.read() >> 10;
          //Bits [9-5]
          *desloc_rd = inst_mem_data.read() >> 5;
          break;
        }
        case 9: {
          //Bits [9-5]
          *desloc_rd = inst_mem_data.read() >> 5;
          break;
        }
        case 10: {
          //Bits [9-5]
          *desloc_rd = inst_mem_data.read() >> 5;
          break;
        }
        case 11: {
          //Bits [9-5]
          *desloc_rd = inst_mem_data.read() >> 5;
          break;
        } 
        default: {
          //Bits [19-15]
          *rt = inst_mem_data.read() >> 15;
          //Bits [14-10]
          *rs = inst_mem_data.read() >> 10;
          //Bits [9-5]
          *desloc_rd = inst_mem_data.read() >> 5;
          break;
        }
      } 
  
  }
  
  
  typedef struct buffer1 {
  	sc_uint<24> instruction;
    sc_uint<5> next_inst_addres;
  } BufferIfId;
  
  typedef struct buffer2 {
  	sc_uint<5> next_inst_addres;
    sc_uint<5> rt;
    sc_uint<5> rd;
    sc_uint<5> opCode;
    sc_uint<5> desloc; 
    sc_uint<5> reg_mem_r1_v;
    sc_uint<5> reg_mem_r2_v;
    sc_uint<1> = ctr_regWrite;
    sc_uint<1> = ctr_memToReg;
    sc_uint<1> = ctr_memWrite;
    sc_uint<1> = ctr_memRead;
    sc_uint<1> = ctr_aluSrc;
    
  } BufferIdEx;
  
  typedef struct buffer3 {
  	sc_uint<24> instruction;
    sc_uint<5> branch_inst_addres;
  } BufferExMem;
  
  
    void do_po() {
      
      //INSTRUCTION FETCH
      BufferIfId bff1;
      
      
      
      //BUFFER IF/ID
      //Instruction Memory
      beff1.instruction = inst_mem_data.read();
      beff1.next_inst_addres = inst_mem_adress.read() + 1;
     
      
      
      
      //INSTRUCTION DECODE
      BufferIfId bff2;
     
      //Divide bits da instrução
      sc_uint<4> opcode;
      sc_uint<5> rg_r1_address;
      sc_uint<5> rg_r2_address;
      sc_uint<5> desloc;
      sc_uint<5> rd;
      decode_instruction(bff1.instruction, &opcode, &rg_r1_address, &rg_r2_address, 
                         &desloc, &rd);
      cout << "opcode: " << opcode << endl;
      cout << "clock: " << clock << endl;
      
      
      //CONTROL
      ctr_ctrop.write(opcode);
      
      
      //REGISTERS BANK
      // Seta entradas de controle do banco de registradores
      reg_mem_reg_write.write(bff4.ctr_regWrite);
      
      reg_mem_write_address.write(bff4.rt);
      reg_mem_write_data.write(data_mem_data_value.read());
      
      reg_mem_r1_address.write(rg_r1_address);
      reg_mem_r2_address.write(rg_r2_address);
      
      
      
      //Extende deslocamento de 10bits para 32bits
//       sc_uint<1> desloc_msb = desloc >> 9;
      
//       sc_uint<32> desloc_extended = 0;
//       sc_uint<32> se1 = 4294966272;

//       if (desloc_msb == 1){
//         desloc_extended = se1 + desloc;
//       } else {
//         desloc_extended = desloc;
//       }
      
      
      
      //BUFFER ID/EX
      bff2.opCode = opcode;
      
      bff2.ctr_regWrite = ctr_regWrite.read();
      bff2.ctr_memToReg = ctr_memToReg.read();
      bff2.ctr_memWrite = ctr_memWrite.read();
      bff2.ctr_memRead = ctr_memRead.read();
      bff2.ctr_aluSrc = ctr_aluSrc.read();
      
      bff2.next_inst_addres = bff1.next_inst_addres;
      
      bff2.reg_mem_r1_v = r1_value.read();
      bff2.reg_mem_r2_v = r2_value.read();
      
      bff2.desloc = desloc;
      
      bff2.rt = rt;
      bff2.rd = rd;
      
      
      
      //EXECUTION
      
      //ALU
      alu_op.write(bff2.opCode);
      
      alu_x.write(bff2.reg_mem_r1_v);
      
      if(ctr_aluSrc == 1) {
        alu_y.write(bff2.desloc);
      }
      else {
      	alu_y.write(bff2.reg_mem_r1_v);
      }
      
      
      //BUFFER EX/MEM
      bff3.branch_inst_addres =  bff2.next_inst_addres + bff2.desloc;
      

      
      
      
      
      
      
      
      
      //-------DATA MEMORY
      // Seta entradas de controle do banco de dados
      data_mem_mem_read.write(ctr_memRead.read());
      data_mem_mem_write.write(ctr_memWrite.read());
      
      cout << "ctr_memRead: " << ctr_memRead.read() << endl;
      
      data_mem_data_address.write(bff1.rs);
      cout << "inst_dm_address: " << inst_dm_address << endl;
      
      
    
        
      BufferExMem bff3;
      
      
      
      
      //TESTE
      reg_mem_r1_address.write(1);
      
      cout << "valor recuperado do banco: " + reg_mem_r1_value.read() << endl;
      
       
      
      
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
        sensitive << clock.neg();
    }
};
