#ifdef USE_CORTOS
#define PRINTF cortos_printf
#else
#define PRINTF ee_printf
#endif
#include "./img.h"
#include "./nn.h"
typedef struct predictArgs__ {
	int noi;
      Img** imgs;
      NeuralNetwork * net;
} predictArgs;

void predictImg( Img** imgs, int noi, NeuralNetwork* net);
void setxPredictArgs (predictArgs * args, Img** img, int n, NeuralNetwork * net);
void predictThread(void* args);