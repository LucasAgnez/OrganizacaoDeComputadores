
#include <systemc>
#include "Router.h"

int sc_main (int argc, char* argv[]) {
	sc_signal<bool> clock;

  Router router("Router");
  sc_signal<sc_uint<32>> router_north_data_in;
  sc_signal<sc_uint<32>> router_north_data_out;
  sc_signal<sc_uint<1>> router_north_ack_in;
  sc_signal<sc_uint<1>> router_north_ack_out;
  sc_signal<sc_uint<1>> router_north_val_in;
  sc_signal<sc_uint<1>> router_north_val_out;
  sc_signal<sc_uint<32>> router_south_data_in;
  sc_signal<sc_uint<32>> router_south_data_out;
  sc_signal<sc_uint<1>> router_south_ack_in;
  sc_signal<sc_uint<1>> router_south_ack_out;
  sc_signal<sc_uint<1>> router_south_val_in;
  sc_signal<sc_uint<1>> router_south_val_out;
  sc_signal<sc_uint<32>> router_east_data_in;
  sc_signal<sc_uint<32>> router_east_data_out;
  sc_signal<sc_uint<1>> router_east_ack_in;
  sc_signal<sc_uint<1>> router_east_ack_out;
  sc_signal<sc_uint<1>> router_east_val_in;
  sc_signal<sc_uint<1>> router_east_val_out;
  sc_signal<sc_uint<32>> router_west_data_in;
  sc_signal<sc_uint<32>> router_west_data_out;
  sc_signal<sc_uint<1>> router_west_ack_in;
  sc_signal<sc_uint<1>> router_west_ack_out;
  sc_signal<sc_uint<1>> router_west_val_in;
  sc_signal<sc_uint<1>> router_west_val_out;
  sc_signal<sc_uint<32>> router_local_data_in;
  sc_signal<sc_uint<32>> router_local_data_out;
  sc_signal<sc_uint<1>> router_local_ack_in;
  sc_signal<sc_uint<1>> router_local_ack_out;
  sc_signal<sc_uint<1>> router_local_val_in;
  sc_signal<sc_uint<1>> router_local_val_out;

  router.clock(clock);
  router.north_data_in(router_north_data_in);
  router.north_data_out(router_north_data_out);
  router.north_ack_in(router_north_ack_in);
  router.north_ack_out(router_north_ack_out);
  router.north_val_in(router_north_val_in);
  router.north_val_out(router_north_val_out);
  router.south_data_in(router_south_data_in);
  router.south_data_out(router_south_data_out);
  router.south_ack_in(router_south_ack_in);
  router.south_ack_out(router_south_ack_out);
  router.south_val_in(router_south_val_in);
  router.south_val_out(router_south_val_out);
  router.east_data_in(router_east_data_in);
  router.east_data_out(router_east_data_out);
  router.east_ack_in(router_east_ack_in);
  router.east_ack_out(router_east_ack_out);
  router.east_val_in(router_east_val_in);
  router.east_val_out(router_east_val_out);
  router.west_data_in(router_west_data_in);
  router.west_data_out(router_west_data_out);
  router.west_ack_in(router_west_ack_in);
  router.west_ack_out(router_west_ack_out);
  router.west_val_in(router_west_val_in);
  router.west_val_out(router_west_val_out);
  router.local_data_in(router_local_data_in);
  router.local_data_out(router_local_data_out);
  router.local_ack_in(router_local_ack_in);
  router.local_ack_out(router_local_ack_out);
  router.local_val_in(router_local_val_in);
  router.local_val_out(router_local_val_out);
  
    
  router_south_data_in.write(1811932159); //tem q ir pro oeste 1x e sul 1x e retorna 738190335
  router_north_data_in.write(201326591); // tem que ir pro sul 1x e retorna 67108863
  router_east_data_in.write(738190335); // sul 1x e retorna 603972607
  router_north_val_in.write(1);
  router_north_ack_out.write(1);
  router_south_val_in.write(1);
  router_south_ack_out.write(1);
  router_east_val_in.write(1);
  router_east_ack_out.write(1);
  router_west_val_in.write(1);
  router_west_ack_out.write(1);
  router_local_val_in.write(1);
  router_local_ack_out.write(1);

  for(int i = 0; i<14; i++) {
    clock = 1;
    sc_start(100, SC_NS);
    clock = 0;
    sc_start(100, SC_NS);
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "North data out: " << router_north_data_out.read() << std::endl;
    std::cout << "South data out: " << router_south_data_out.read() << std::endl;
    std::cout << "East data out: " << router_east_data_out.read() << std::endl;
    std::cout << "West data out: " << router_west_data_out.read() << std::endl;
    std::cout << "Local data out: " << router_local_data_out.read() << std::endl;
  }

  return 0;
}
