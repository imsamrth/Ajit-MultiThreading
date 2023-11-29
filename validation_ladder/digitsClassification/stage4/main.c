/* Digits CLassification using CNN*/
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
#include "include/data_structs.h"

volatile ThreadChannel volatile tc;
volatile predictArgs volatile pargs;

void predictImg_top(int noi){
	volatile ThreadChannel* volatile tc_ptr = &tc;

	Img** imgs = csv_to_imgs_from_C(noi);
	cortos_printf("Images Loaded\n");
	NeuralNetwork* net = network_load_from_C();
	cortos_printf("Network loaded \n");

	uint64_t t0 =__ajit_get_clock_time();
	predictImg(imgs, noi, net);
	uint64_t t1 =__ajit_get_clock_time();
	cortos_printf("Single thread Times: %f\n",
	 		(double) ( t1 - t0));

	Img** img0 = cortos_bget((noi/2) * sizeof(Img*));
	Img** img1 = cortos_bget((noi - (noi/2) )*sizeof(Img*)) ;
	
	int k = 0, m = noi/2 ;
	for(k = 0; k <= m ;k++ ){
		if(k < m) img0[k] = imgs[k];
		if(k+m < noi) img1[k] = imgs[m+k];
	}
	imgs_free(imgs, noi);


	t0 =__ajit_get_clock_time();
	// cortos_printf("Img set has been divided\n");
	setxPredictArgs(&pargs, img0, m , net);
	while(scheduleChannelJob(tc_ptr, (void*) predictThread, &pargs))
	{
		//cortos_printf("Img0 scheduling job\n");
	};
	// //cortos_printf("Img0 prediction called\n");

	predictImg(img1, noi - m, net);
	//cortos_printf("Img1 prediction completed\n");
	void* vptr = NULL;
	while(getChannelResponse(tc_ptr, &vptr))
	{
	}
	t1 =__ajit_get_clock_time();
	PRINTF("Double thread Times: %f\n",
			(double) (t1 - t0));
	network_free(net);
	cortos_printf("Network free\n");
	 return ;
}

void predictImg(Img** imgs, int noi, NeuralNetwork* net ){
	//cortos_printf("Prediction called for %d IMages", noi);
	double score = network_predict_imgs(net, imgs, noi);
	cortos_printf("Prediction from Network: %1.5f \n", score);
	return ;
}

void setup()
{
	__ajit_serial_configure__(1,0,0);
	__ajit_serial_set_baudrate__ (115200, 80000000);
	__ajit_serial_set_uart_reset__ (0);

	cortos_printf("Init channel.\n");
	// initialize scoreboard.
	initChannel(&tc, 1);
	cortos_printf("initChannel %d: status=%d.\n", tc.id, tc.status);
}

int main () {}

int main_00()
{
	//while(t--) {CORTOS_DEBUG("main started....\n");}
	predictImg_top(4);
	cortos_printf("main completed, returning....\n");
	scheduleChannelJob(&tc, NULL, NULL);
	return(1);
}

int main_01 ()
{

	//int t = 5 ;
	//while(t--) {cortos_printf("main started 2....\n");}
	 void (*__fn) (void*);
	 void *__arg;

	cortos_printf("Entered main_01\n");

	while(1) 
	{
		//cortos_printf("Entered while main01\n");
		while(getChannelJob(&tc, (void**) &__fn, (void**) &__arg))
		{
			//cortos_printf(" line 107 while \n");
		}
		//cortos_printf(" TC STATUS : %d \n", tc.status);
		if(__fn != NULL)
		{
			//cortos_printf("thread 1 line 112\n");
			(*__fn)(__arg);
			setChannelResponse(&tc, __arg);
			//cortos_printf("Entered main_setchannel\n");
		}
		else
			break;
	}

	cortos_printf("THeead 1 ended\n");

	return(1);

}


// BuildArgs: " -D USE_CORTOS -F lm  -D USE_VMAP -C ./ -I $AJIT_HOME/application_development/thread_channel/include -C $AJIT_HOME/application_development/thread_channel/src -I $AJIT_HOME/validation_ladder/digitsClassification/stage3/include -C $AJIT_HOME/validation_ladder/digitsClassification/stage3/src -F funroll-loops "
