#include "systemc.h"

SC_MODULE(DATA_MEM) {
	sc_in<sc_uint<5>> data_address;
  
	sc_in<sc_uint<1>> mem_write;
	sc_in<sc_uint<1>> mem_read;
  
  	sc_in<sc_uint<32>> write_data;
  
	sc_out<sc_uint<32>> data_value;

	sc_uint<32> data[128];


    void do_read() {
      if(mem_read.read() == 1) {
      	data_value.write(data[data_address.read()]);
      }
    }
  
  	void do_write() {
      if(mem_write.read() == 1) {
      	data[data_address.read()] = write_data.read();
      }
    }

    SC_CTOR(DATA_MEM) {
      SC_METHOD(do_read)
        sensitive << data_address << mem_read;
      SC_METHOD(do_write)
        sensitive << data_address << write_data << mem_write;
    }

};
  