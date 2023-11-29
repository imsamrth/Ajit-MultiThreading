#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef USE_CORTOS
#include <cortos.h>
#endif
#include "../include/data_structs.h"

void setxPredictArgs (predictArgs* args, Img**  imgs,  int noi, NeuralNetwork* net)
{
	args->noi = noi;
	args->imgs = imgs;
    args->net = net;
}
		
void predictThread (void* vargs)
{
    int noi =           ((predictArgs*)vargs)->noi;
    Img** imgs =      ((predictArgs*)vargs)->imgs;
    NeuralNetwork* net = ((predictArgs*)vargs)->net;
    //cortos_printf("calling predict thread linec22 %d\n", noi);
    predictImg(imgs, noi, net);
}
