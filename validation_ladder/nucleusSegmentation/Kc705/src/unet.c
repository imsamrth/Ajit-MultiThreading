#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "../include/matrix.h"
#include "../include/ops.h"
#include "../include/activations.h"
#include "../include/decl.h"
#include <stdint.h>

typedef struct
{
        Matrix *conv1;
        Matrix *pool1;
        Matrix *conv2;
        Matrix *pool2;
        Matrix *conv3;
        Matrix *upconv1;
        Matrix *concat1;
        Matrix *conv4;
        Matrix *upconv2;
        Matrix *concat2;
        Matrix *conv5;
} UNetModel;

UNetModel *unet_create(int input_rows, int input_cols, int num_channels, int num_classes)
{
        UNetModel *model = malloc(sizeof(UNetModel));

        // Define UNet layers using the provided matrix functions
        model->conv1 = matrix_create(input_rows, input_cols);
        model->pool1 = matrix_create(input_rows / 2, input_cols / 2);
        model->conv2 = matrix_create(input_rows / 2, input_cols / 2);
        model->pool2 = matrix_create(input_rows / 4, input_cols / 4);
        model->conv3 = matrix_create(input_rows / 4, input_cols / 4);
        model->upconv1 = matrix_create(input_rows / 2, input_cols / 2);
        model->concat1 = matrix_create(input_rows / 2, input_cols / 2 + input_cols / 2);
        model->conv4 = matrix_create(input_rows / 2, input_cols / 2);
        model->upconv2 = matrix_create(input_rows, input_cols);
        model->concat2 = matrix_create(input_rows, input_cols + input_cols);
        model->conv5 = matrix_create(input_rows, input_cols);

        return model;
}

void unet_free(UNetModel *model)
{
        if (model)
        {
                matrix_free(model->conv1);
                matrix_free(model->pool1);
                matrix_free(model->conv2);
                matrix_free(model->pool2);
                matrix_free(model->conv3);
                matrix_free(model->upconv1);
                matrix_free(model->concat1);
                matrix_free(model->conv4);
                matrix_free(model->upconv2);
                matrix_free(model->concat2);
                matrix_free(model->conv5);
                free(model);
        }
}

void unet_train(UNetModel *model, Matrix *input_images, Matrix *target_masks, int num_epochs, double learning_rate)
{
        int epoch, i;

        for (epoch = 0; epoch < num_epochs; epoch++)
        {
                // Forward pass
                Matrix *output_masks = unet_forward(model, input_images);

                // Calculate loss (simple mean squared error for illustration)
                Matrix *diff = subtract(output_masks, target_masks);
                Matrix *squared_diff = apply(square, diff);
                double loss = matrix_sum(squared_diff) / (input_images->rows * input_images->cols);

                // Print current epoch and loss
                printf("Epoch %d, Loss: %.4f\n", epoch + 1, loss);

                // Backward pass (gradient calculation)
                Matrix *grad = subtract(output_masks, target_masks);

                // Update model parameters using gradient descent
                // Example: model->conv1 = subtract(model->conv1, scale(learning_rate, grad));
                // Update other layers similarly

                matrix_free(output_masks);
                matrix_free(diff);
                matrix_free(squared_diff);
        }
}

Matrix* process_image(uint32_t ** k_addr, uint32_t ** t_addr, NicQueue *nQ, uint32_t stage)
{
        // Example usage
        int input_rows = 256;
        int input_cols = 256;
        int num_channels = 3; // RGB channels
        int num_classes = 1;  // Binary segmentation

        UNetModel *model = unet_create(input_rows, input_cols, num_channels, num_classes);

        // Example training data (random matrices for illustration)
        Matrix *input_images;
        input_images = matrix_create(input_rows, input_cols);
        matrix_randomize(input_images, 255); // Randomize pixel values
        Matrix *target_masks;
        target_masks = matrix_create(input_rows, input_cols);
        matrix_fill(target_masks, 1); // Example mask (binary)

        // Train the UNet model
        Matrix *output_masks;
        output_masks = unet_forward(model, input_images);

        // Free memory
        matrix_free(input_images);
        matrix_free(target_masks);
        unet_free(model);

        return output_masks;
}