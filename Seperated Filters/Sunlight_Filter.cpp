// Include necessary libraries
#include <iostream>
#include "Image_Class.h"  // Assuming this is a custom image class
#include <fstream>        // Input/output stream class to operate on files.
#include <windows.h>      // For Windows-specific functions like SetCurrentDirectory
#include <filesystem>     // For filesystem operations
#include <stdio.h>        // I am using for delete temporary_file if user chosen apply a filter
#define sv saveImage      // Define a shorthand for saveImage method
#define uint unsigned int // Define uint as an alias for unsigned int
#define gp getPixel       // Define a shorthand for getPixel method
using namespace std;

int main() {

    Image f1("Wano 2.jpg");

    // Image dimensions
    Image image(f1.width, f1.height);

    // Generate the gradient from yellow to black
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i, j, 0) = 50;
            image(i, j ,1) = 55;
            image(i, j, 2) = 0;
        }
    }

    image.sv("Hello.jpg");
    Image f2("Hello.jpg");

    for (int i = 0; i < f1.width; ++i) {
        for (int j = 0; j < f1.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                f2(i, j, k) = (f1(i, j, k) + f2(i, j, k)) / 2;
            }
        }
    }

    f2.saveImage("new.jpg");
    Image final_image("new.jpg");
    double factor = 1.11 + (150 / 255.0);

    for (int i = 0; i < final_image.width; i++) {
        for (int j = 0; j < final_image.height; j++) {
            for (int k = 0; k < final_image.channels; k++) {
                int new_value = final_image(i, j, k) * factor;
                final_image(i, j, k) = int(max(0, min(255, new_value)));
            }
        }
    }
    // Save the modified image
    final_image.sv("new.jpg");
}