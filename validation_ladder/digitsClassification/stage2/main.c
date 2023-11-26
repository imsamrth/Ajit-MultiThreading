/* Factored discrete Fourier transform, or FFT, and its inverse iFFT */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <cortos.h>
#include <core_portme.h>
#include <thread_channel.h>
#include <ajit_access_routines.h>
#include "include/matrix.h"
#include "include/ops.h"
#include "include/img.h"
#include "include/activations.h"
#include "include/nn.h"
#include "include/net.h"
//volatile ThreadChannel volatile tc;
//
// void setup()
// {
// 	__ajit_serial_configure__(1,0,0);
// 	__ajit_serial_set_baudrate__ (115200, 80000000);
// 	__ajit_serial_set_uart_reset__ (0);
//
// 	PRINTF("Init channel.\n");
// 	// initialize scoreboard.
// 	initChannel(&tc, 1);
//
// 	CORTOS_DEBUG("initChannel %d: status=%d.\n", tc.id, tc.status);
// }

int main()
{
	uint32_t k;
	cortos_printf("Hello pratham : %f %f %f\n",
			(double) (0),
			(double) (0),
			(double)(HIDDEN));
	uint32_t number_imgs = 2 ;
	cortos_printf("SDF &%d \n", HIDDEN);
	Matrix* m = matrix_create(28,28);
	cortos_printf("Hello prtham matrix created :))\n");
	Img** imgs = csv_to_imgs_from_C(number_imgs);
	cortos_printf(":// IMAGE LOADED \n");
	NeuralNetwork* net = network_load_from_C();
	//cortos_printf("Network loaded \n");
	double score = network_predict_imgs(net, imgs, number_imgs);
	//cortos_printf("PREDICTION DONE, ABB KY \n");
	//cortos_printf("Prediction from Network: %1.5f \n", score);
	imgs_free(imgs, number_imgs);
	network_free(net);
	cortos_printf("Network free BTP Done\n");
	return(1);
}
//
//int main_01 ()
//{
//	void (*__fn) (void*);
//	void *__arg;
//
//	CORTOS_DEBUG("Entered main_01\n");
//
//	while(1) 
//	{
//		while(getChannelJob(&tc, (void**) &__fn, (void**) &__arg))
//		{
//		}
//
//		if(__fn != NULL)
//		{
//			(*__fn)(__arg);
//			setChannelResponse(&tc, __arg);
//		}
//		else
//			break;
//	}
//
//	return(1);
//
//}
