
#include <systemc.h>
#include "rgb565.h"

int sc_main(int argc, char *argv[]){


	sc_clock clk("clk", 40, SC_NS);
	sc_signal<bool> rst;
	sc_signal<bool> vsync;
	sc_signal<bool> href;
	sc_signal<sc_uint<8> > data;

	rgb565 rgb565("rgb565");
	rgb565.clk(clk);
	rgb565.vsync(vsync);
	rgb565.href(href);
	rgb565.data(data);

	sc_trace_file *t_file;
	t_file = sc_create_vcd_trace_file("ov7670");
	sc_trace(t_file, rgb565.clk, "rgb565.clk");
	sc_trace(t_file, rgb565.vsync, "rgb565.vsync");
	sc_trace(t_file, rgb565.href, "rgb565.href");
	sc_trace(t_file, rgb565.data, "rgb565.data");

	sc_trace(t_file, rgb565.hcnt, "rgb565.hcnt");
	sc_trace(t_file, rgb565.vcnt, "rgb565.vcnt");

	sc_start(640*2*510*100,SC_NS);

	sc_close_vcd_trace_file(t_file);

	return 0;
}
