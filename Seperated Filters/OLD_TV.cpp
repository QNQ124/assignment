// Include necessary libraries
#include <iostream>
#include "Image_Class.h"  // Assuming this is a custom image class
#include <fstream>        // Input/output stream class to operate on files.
#include <windows.h>      // For Windows-specific functions like SetCurrentDirectory
#include <filesystem>     // For filesystem operations
#include <stdio.h>        // using for delete temporary_file
#define sv saveImage      // Define a shorthand for sv method
#define uint unsigned int // Define uint as an alias for unsigned int
#define gp getPixel       // Define a shorthand for getPixel method


using namespace std;

int main() {

    // load the image
    Image image("Water 7.jpg");

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {

                // Applying scanline
                if ((j % 2) == 0){
                    // lighten pixel to simulate scanline
                    image(i, j, k) = image(i, j, k);
                    image(i, j + 1, k) = image(i, j + 1, k);
                }
                else{
                    // Add random noise
                    int noise = rand() % 56 - 10;       // random noise in [-45, 45]
                    int Value = image(i, j, k) + noise;
                    Value = min(255, max(0, Value));
                    image(i, j, k) = Value;
                }
            }
        }
    }
    // Save the image
    image.sv("new.jpg"); // temporary file here
    Image final_image("new.jpg");

    // Decreasing darken degree, Then multiply factor for all Pixel like a ratio of Darken
    double factor = 1.11 + (-48 / 255.0);

    // Darken image after applying Scanline
    for (int i = 0; i < final_image.width; i++) {
        for (int j = 0; j < final_image.height; j++) {
            for (int k = 0; k < final_image.channels; k++) {
                int new_value = final_image(i, j, k) * factor;
                final_image(i, j, k) = int(max(0, min(255, new_value))); // Check range of RGB and Modify it
            }
        }
    }
    // Save the modified image in temporary file here   //////////////// Remember
    final_image.sv("new.jpg");
}
