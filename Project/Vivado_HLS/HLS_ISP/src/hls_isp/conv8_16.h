#pragma once
#include <systemc.h>

SC_MODULE(conv8_16)
{
	sc_in <bool> clk;
	sc_in <bool> vsync_i;
	sc_in <bool> href_i;
	sc_in <sc_uint<8> > data_i;

	sc_out <bool> vsync_o;
	sc_out <bool> href_o;
	sc_out <bool> en_o;
	sc_out <sc_uint<16> > data_o;

	void process();
	void timing_gen();

	SC_CTOR(conv8_16)
	{
		SC_CTHREAD(process,clk.pos());
		SC_METHOD(timing_gen);
		sensitive << href_i << vsync_i;
	}

};
