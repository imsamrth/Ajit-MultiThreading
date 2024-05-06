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


int main()
{
        __ajit_write_serial_control_register__(TX_ENABLE | RX_ENABLE);

        // -------------------------------------------
        // -- 1 Allocate buffers and initialise queues
        // -------------------------------------------
        uint32_t msgSizeInBytes, length, msgs_written;
        msgSizeInBytes = 4;
        length = 64;

        uint32_t size_of_kernel = 9;

        NicQueue nicQueue;
        generateNicQueue(&nicQueue, msgSizeInBytes, length);
        cortos_printf("Queues initialised\n");
        uint32_t kernel_size_array[9] = {
                16 * size_of_kernel + 32, 128 * size_of_kernel + 32, 256 * size_of_kernel + 32, 512 * size_of_kernel + 32, 1024 * size_of_kernel + 32,
                512 * size_of_kernel + 32, 256 * size_of_kernel + 32, 128 * size_of_kernel + 32, 16 * size_of_kernel + 32 };

        uint32_t tensor_size_array = 196608;
        uint32_t packet_size_array[1] = {1600};

        uint32_t *kernel_start_addr[9], *tensor_start_addr[4][5], *packet_start_addr[length];
        uint32_t *new_kernel[9], *new_tensor[4][5];
        uint32_t kernel[9], tensor[4][5];
        if (initialiseSpace(kernel_start_addr, kernel_size_array, 9, 1) != 9)
                cortos_printf("Kernel init error\n");
        if (initialiseSpace(tensor_start_addr[0], tensor_size_array, 1, 1) != 1)
                cortos_printf("Tensor 1 init error\n");
        if (initialiseSpace(packet_start_addr, packet_size_array, length, 0) != length)
                cortos_printf("Packet init error\n");
        cortos_printf("Memory spaces initialised\n");

        payloadAddressFromNetworkAddress(new_kernel, kernel_start_addr, 6, 9);
        byteToDoubleWord(new_kernel, kernel, 9);
        payloadAddressFromNetworkAddress(new_tensor[0], tensor_start_addr[0], 6, 5);
        byteToDoubleWord(new_tensor[0], tensor[0], 5);


        int i;

        // push free queue
        uint32_t msg_written = cortos_writeMessages(nicQueue.free_queue, packet_start_addr, 63);
        if (msg_written != 63)
                CORTOS_ERROR("Free queue push failed\n");
        cortos_printf("Free queues initialised\n");

        // ----------------------------
        // -- 2 configure NIC registers
        // ----------------------------
        nicRegConfig(&nicQueue);
        cortos_printf("NIC started\n");

        getFilesThroughEthernet(&nicQueue, kernel_start_addr, 18);

        // while(1)
        {

                // ------------------------
                // -- 5 Read Image from NIC
                // ------------------------
                getFilesThroughEthernet(&nicQueue, tensor_start_addr[0], 5);


                // ------------------------------
                // -- 6 send co-ordinates to accl
                // -- 7 wait till interrupt
                // ------------------------
                // cortos_printf("Reached pre-compute here\n");

                writeNicReg(0, 0); // NIC_REG[0] = 1;
                uint64_t start = cortos_get_clock_time();

                // Stages are 1 to 18
                // Engines are 0 to 3
                process_image( kernel, tensor[0], &nicQueue, 1);

                uint64_t end = cortos_get_clock_time();
                uint64_t time = (end - start);

                uint32_t time_low = time & 0xFFFFFFFF;
                uint32_t time_high = time >> 32;
                cortos_printf("Time taken = %u %u\n", time_high, time_low);

                // -----------------------------
                // -- 8 Send processed image out
                // -----------------------------
                uint32_t op_array[1] = {224 * 224 * 3 + 24};

                writeNicReg(0, 1); // NIC_REG[0] = 1;
                sendFilesThroughEthernet(&nicQueue, tensor_start_addr[0], op_array, 1);

        }


        while (1)
                ;
        return (0);
}