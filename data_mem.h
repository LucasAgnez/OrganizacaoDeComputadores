#include "systemc.h"

SC_MODULE(DATA_MEM) {
  	sc_in_clk clock;
  
	sc_in<sc_uint<5>> data_address;
  
	sc_in<sc_uint<1>> mem_write;
	sc_in<sc_uint<1>> mem_read;
  
  	sc_in<sc_uint<5>> write_data;
  
	sc_out<sc_uint<5>> data_value;

	sc_uint<5> data[128];


    void do_read() {
      cout << "teste_data_mem_read: " << mem_read.read() << endl;
      cout << "teste_data_address: " << data_address.read() << endl;
      cout << "teste_data_value: " << data[data_address.read()] << endl;
      if(mem_read.read() == 1) {
      	data_value.write(data[data_address.read()]);
      }
    }
  
  	void do_write() {
      if(mem_write.read() == 1) {
      	data[data_address.read()] = write_data.read();
      }
    }
     
  	void do_cache_miss() {
		data[0] = 10;
      	data[1] = 1;
      	data[2] = 2;
      	data[3] = 3;
      	data[4] = 4;
      	data[5] = 5;
    }

    SC_CTOR(DATA_MEM) {
      do_cache_miss();
      SC_METHOD(do_read);
        sensitive << clock.pos();
      SC_METHOD(do_write);
        sensitive << clock.pos();
    }

};
  
