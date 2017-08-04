#include <systemc.h>
#include "conv8_16.h"

void conv8_16::process()
{
	//initialize
	sc_uint <16> hcnt;
	sc_uint <8> data_buf1;
	sc_uint <8> data_buf2;
	hcnt = 0;

	while(vsync_i.read()==false) wait();

	//loop
	while(1)
	{
		//wait line start
		while(href_i.read()==false) wait();
		for(hcnt=0;hcnt<640;hcnt++)
		{
			//get R5G3
			data_buf1 = data_i.read();
			en_o.write(true);
			wait();

			//get G3B5
			data_buf2 = data_i.read();
			en_o.write(false);
			data_o.write((data_buf1<<8)|data_buf2);
			wait();
		}
		en_o.write(false);
	}
}


void conv8_16::timing_gen()
{
	vsync_o.write(vsync_i.read());
	href_o.write(href_i.read());
}
