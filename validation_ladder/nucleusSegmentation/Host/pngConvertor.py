import numpy as np
from PIL import Image

# Load the PNG image
image_path = 'color_image.png'  # Replace 'color_image.png' with the path to your PNG image
image = Image.open(image_path)

# Convert the image to a NumPy array
image_array = np.array(image)

# Flatten the image array to a 1D array
flattened_array = image_array.flatten()

# Define the path to save the text file
output_text_file = 'image_matrix.txt'

# Save the flattened NumPy array to a text file
np.savetxt(output_text_file, flattened_array, fmt='%d')

print("Color image matrix saved to:", output_text_file)
