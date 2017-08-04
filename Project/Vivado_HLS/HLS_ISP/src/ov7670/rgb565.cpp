
#include <systemc.h>
#include "rgb565.h"

void rgb565::timing_gen()
{
	//initialize
	vcnt=0;
	hcnt=0;
	vsync.write(0);
	href.write(0);
	wait();

	while(1)
	{
		for(vcnt=0;vcnt<510;vcnt++)
		{
			for(hcnt=0;hcnt<784*2;hcnt++)
			{
				//vsync generate
				if(vcnt<3)
				{
					vsync.write(1);
				}
				else
				{
					vsync.write(0);
				}

				//href generate
				if(20<=vcnt && vcnt<500)
				{
					if(1<=hcnt && hcnt<1281)
					{
						href.write(1);
					}
					else
					{
						href.write(0);
					}
				}
				wait();
			}
		}
	}
}


void rgb565::img_out()
{
	//initialize
	sc_uint<8> img_data;

	data.write(0);
	wait();

	//loop
	while(1)
	{
		if(20<=vcnt && vcnt<500)
		{
			if(0<=hcnt && hcnt<640*2)
			{
				if(hcnt%2)
					data.write(0x34);
				else
					data.write(0x12);
			}
			else
			{
				data.write(0x00);
			}
		}
		wait();
	}

}
