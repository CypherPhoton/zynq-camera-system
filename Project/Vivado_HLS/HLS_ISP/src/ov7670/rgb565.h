#pragma once
#include <systemc.h>

SC_MODULE(rgb565)
{
	sc_in <bool> clk;
	sc_out <bool> vsync;
	sc_out <bool> href;
	sc_out <sc_uint<8> > data;

	sc_uint<16> vcnt;
	sc_uint<16> hcnt;


	void timing_gen();
	void img_out();


	SC_CTOR(rgb565)
	{
		SC_CTHREAD(timing_gen,clk.pos());
		SC_CTHREAD(img_out,clk.pos());
	}

};
