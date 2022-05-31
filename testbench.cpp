#include "systemc.h"
#include "processor.h"


int sc_main (int argc, char* argv[]) {
  	sc_signal<bool> clock;

    PROCESSOR a("PROCESSOR");
  	a.clock(clock);

  	sc_signal<sc_uint<5>> test_pc_out;
    sc_signal<sc_uint<24>> test_mem_inst_out;
    sc_signal<sc_uint<4>> test_opcode;
    sc_signal<sc_uint<5>> test_mem_reg_r1_in;
    sc_signal<sc_uint<5>> test_mem_reg_r2_in;
    sc_signal<sc_uint<5>> test_mem_reg_r1_out;
    sc_signal<sc_uint<5>> test_mem_reg_r2_out;
    sc_signal<sc_uint<4>> test_alu_opcode;
    sc_signal<sc_uint<5>> test_alu_x;
    sc_signal<sc_uint<5>> test_alu_y;
    sc_signal<sc_uint<5>> test_alu_s;
    sc_signal<sc_uint<1>> test_alu_zero;
    sc_signal<sc_uint<5>> test_data_mem_adress;
    sc_signal<sc_uint<5>> test_data_mem_data;
    sc_signal<sc_uint<5>> test_data_mem_value_out;

    a.test_pc_out(test_pc_out);
    a.test_mem_inst_out(test_mem_inst_out);
    a.test_opcode(test_opcode);
    a.test_mem_reg_r1_in(test_mem_reg_r1_in);
    a.test_mem_reg_r2_in(test_mem_reg_r2_in);
    a.test_mem_reg_r1_out(test_mem_reg_r1_out);
    a.test_mem_reg_r2_out(test_mem_reg_r2_out);
    a.test_alu_opcode(test_alu_opcode);
    a.test_alu_x(test_alu_x);
    a.test_alu_y(test_alu_y);
    a.test_alu_s(test_alu_s);
    a.test_alu_zero(test_alu_zero);
    a.test_data_mem_adress(test_data_mem_adress);
    a.test_data_mem_data(test_data_mem_data);
    a.test_data_mem_value_out(test_data_mem_value_out);


  	// Open VCD file
    sc_trace_file *wf = sc_create_vcd_trace_file("processor");
    // Dump the desired signals
    sc_trace(wf, clock, "clock");
    sc_trace(wf, test_pc_out.read(), "test_pc_out");
    sc_trace(wf, test_mem_inst_out.read(), "test_mem_inst_out");
    sc_trace(wf, test_opcode.read(), "test_opcode");
    sc_trace(wf, test_mem_reg_r1_in.read(), "test_mem_reg_r1_in");
    sc_trace(wf, test_mem_reg_r2_in.read(), "test_mem_reg_r2_in");
    sc_trace(wf, test_mem_reg_r1_out.read(), "test_mem_reg_r1_out");
    sc_trace(wf, test_mem_reg_r2_out.read(), "test_mem_reg_r2_out");
    sc_trace(wf, test_alu_opcode.read(), "test_alu_opcode");
    sc_trace(wf, test_alu_x.read(), "test_alu_x");
    sc_trace(wf, test_alu_y.read(), "test_alu_y");
    sc_trace(wf, test_alu_s.read(), "test_alu_s");
    sc_trace(wf, test_alu_zero.read(), "test_alu_zero");
    sc_trace(wf, test_data_mem_adress.read(), "test_data_mem_adress");
    sc_trace(wf, test_data_mem_data.read(), "test_data_mem_data");
    sc_trace(wf, test_data_mem_value_out.read(), "test_data_mem_value_out");




  	for(int i = 0; i<6; i++) {
      clock = 1;
      sc_start(100, SC_NS);
      clock = 0;
      sc_start(100, SC_NS);
      cout << "---------------------" << endl;
    }


    //sc_start(1, SC_SEC);



  return 0;
}
