/* Factored discrete Fourier transform, or FFT, and its inverse iFFT */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#ifdef USE_CORTOS
#include <cortos.h>
#else
#include <core_portme.h>
#endif
#include <thread_channel.h>
#include <ajit_access_routines.h>
#include <ds.h>
#include "util/img.h"
#include "neural/activations.h"
#include "neural/nn.h"
#include "matrix/matrix.h"
#include "matrix/ops.h"
#include "net/net.h"

volatile ThreadChannel volatile tc;

void setup()
{
	__ajit_serial_configure__(1,0,0);
	__ajit_serial_set_baudrate__ (115200, 80000000);
	__ajit_serial_set_uart_reset__ (0);

	PRINTF("Init channel.\n");
	// initialize scoreboard.
	initChannel(&tc, 1);

	CORTOS_DEBUG("initChannel %d: status=%d.\n", tc.id, tc.status);
}


int main_00()
{
	int k;

	PRINTF("Times: %f %f %f\n",
			(double) (0),
			(double) (0),
			(double)(HIDDEN));

	// close the channel..
	int number_imgs = 1 ;
	PRINTF("SDF &%d", HIDDEN);
	Matrix* m = matrix_create(28,28);
	//Img** imgs = csv_to_imgs_from_C(1);

	return(1);
}

int main_01 ()
{
	void (*__fn) (void*);
	void *__arg;

	CORTOS_DEBUG("Entered main_01\n");

	while(1) 
	{
		while(getChannelJob(&tc, (void**) &__fn, (void**) &__arg))
		{
		}

		if(__fn != NULL)
		{
			(*__fn)(__arg);
			setChannelResponse(&tc, __arg);
		}
		else
			break;
	}

	return(1);

}

