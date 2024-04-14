#include <string>
#include <iostream>
#include "Image_Class.h"
#include "ImageProcessor.h"
#include <fstream>        // Input/output stream class to operate on files.
#include <windows.h>    // For Windows-specific functions like SetCurrentDirectory
#include <filesystem>     // For filesystem operations
#include <stdio.h>        // using for delete temporary_file if user chosen Applying a Filter
#define sv saveImage      // Define a shorthand for saveImage method
#define uint unsigned int // Define uint as an alias for unsigned int
#define gp getPixel       // Define a shorthand for getPixel method
using namespace std;

int GrayScale_Filter(const string &filename) {
    // Load the image
    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    Image image(filename1);

    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            uint average = 0;

            // Calculate the average of RGB values
            for (int k = 0; k < 3; ++k) {
                average += image(i, j, k);
            }
            average /= 3;

            // Set each RGB value to the average
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = average;
            }
        }
    }
    cout << filename1 << endl;
        // sv the grayscale image
    image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// Function to convert an image to black and white
int BlackAndWhite_Filter(const string &filename)
{

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    // Load the image
    Image image(filename1);

    // Convert each pixel to black or white based on its intensity
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            uint average = 0;

            // Calculate the average of RGB values
            for (int k = 0; k < 3; ++k) {
                average += image(i, j, k);
            }
            average /= 3;

            // Set the pixel to black or white based on the average
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (average >= 127) ? 255 : 0;
            }
        }
    }
    cout << filename1 << endl;
        // sv the grayscale image
    image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

int Purple_Filter(const string &filename){

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    // Load the input image
    Image photo(filename1);

    // Apply the purple tint effect to the image
    for (int i = 0; i < photo.width; i++)
    {
        for (int j = 0; j < photo.height; j++)
        {
            // Get the current pixel's RGB values
            int red = photo.getPixel(i, j, 0);  // Get red channel value
            int green = photo.getPixel(i, j, 1); // Get green channel value
            int blue = photo.getPixel(i, j, 2);  // Get blue channel value

            // Increase red and blue, decrease green to create a purple tint
            red += 60; // increase red value
            green -= 30; // decrease green value
            blue += 60; // increase blue value

            // Ensure that values are within the valid range [0, 255]
            red = min(255, max(0, red));
            green = min(255, max(0, green));
            blue = min(255, max(0, blue));

            // Set the new RGB values to the pixel
            photo.setPixel(i, j, 0, red); // Red channel
            photo.setPixel(i, j, 1, green); // Green channel
            photo.setPixel(i, j, 2, blue); // Blue channel
        }
    }
    cout << filename1 << endl;
        // sv the grayscale image
    photo.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// invert image function
int Invert_Filter(const string &filename){

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    // Load the image
    Image image(filename1);

    // Iterate over each pixel in the image
    for(int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            // Iterate over each color channel (RGB)
            for (int k = 0; k < 3; k++)
            {
                // Get the current pixel color
                uint pixel_color = image.gp(i, j, k);
                // Invert the pixel color
                uint pixel_inverted_color = 255 - pixel_color;
                // Set the inverted color to the pixel
                image.setPixel(i, j, k, pixel_inverted_color);
            }
        }
    }
    cout << filename1 << endl;
        // sv the grayscale image
    image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// Infrared Filter function
int Infrared_Filter(const string &filename){

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;
    // load image
    Image image(filename1);

    for(int i = 0; i < image.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < image.height; j++) // Using .height to get image height
        {
            image(i,j,0)=0;
        }
    }
    for(int i = 0; i < image.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < image.height; j++) // Using .height to get image height
        {
            for (int k = 0; k < 3; k++) // Assuming 3 color channels (RGB)
            {
                unsigned int pixel_color = image.getPixel(i, j, k); // Assuming getPixel method exists
                unsigned int pixel_inverted_color = 255 - pixel_color; // Inverting color
                image.setPixel(i, j, k, pixel_inverted_color); // Assuming setPixel method exists
            }
        }
    }
    cout << filename1 << endl;
        // sv the grayscale image
    image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// Noise filter function
int Noise_Filter(string filename){

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;
    // load image
    Image photo(filename1);

    // Add random noise to each pixel in the image
    for (int i = 0; i < photo.width; i++) {
        for (int j = 0; j < photo.height; j++) {
            for (int k = 0; k < photo.channels; k++) {

                // Generate a random factor to multiply the pixel value by
                double factor = 1.11 + (-1 * (rand() % 121) / 255.0);
                int new_value = photo(i, j, k) * factor;
                photo(i, j, k) = int(max(0, min(255, new_value))); // Check range of RGB and Modify it

            }
        }
    }
    cout << filename1 << endl;
        // sv the grayscale image
    photo.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// NightVision filter function
int NightVision_Filter(const string &filename){

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;
    // load image
    Image photo(filename1);

    // Set the red and blue channels to 0, effectively removing them
    for(int i = 0; i < photo.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < photo.height; j++) // Using .height to get image height
        {
            photo(i,j,0) = 0; // Set red channel to 0
            photo(i,j,2) = 0; // Set blue channel to 0
        }
    }

    // Increase the brightness of the image
    double factor = 1.11 + (-45.0 / 255.0);
    for (int i = 0; i < photo.width; i++) {
        for (int j = 0; j < photo.height; j++) {
            for (int k = 0; k < photo.channels; k++) {
                int new_value = photo(i, j, k) * factor;
                photo(i, j, k) = int(max(0, min(255, new_value))); // Check range of RGB and Modify it
            }
        }
    }
    cout << filename1 << endl;
        // sv the grayscale image
    photo.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// Detect image edges function
int Detect_Image_Edges(const string &filename){

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    // load image
    Image image(filename1);

    // Convert the image to grayscale
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            unsigned int average = 0;

            for (int k = 0; k < 3; ++k) {
                average += image(i, j, k);
            }

            average /= 3;

            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = average;
            }
        }
    }

    // Apply edge detection algorithm with Laplacian operator
    for (int i = 1; i < image.width - 1; ++i) {
        for (int j = 1; j < image.height - 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                int laplacian = abs(image(i,j,k) - image(i + 1,j + 1, k)) + abs(image(i, j + 1, k) - image(i + 1, j, k));
                image(i, j, k) = (laplacian > 255) ? 255 : (laplacian < 0) ? 0 : laplacian;
            }
        }
    }

    // Invert the colors of the gray_image image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    cout << filename1 << endl;

        // sv the grayscale image
    image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// OilPainting Filter function
int OilPainting_Filter(const string &filename){

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    // load image
    Image image(filename1);

    // Set the radius of the painting effect
    int radius = 1;
    int width = image.width;
    int height = image.height;
    int intensity_levels = 10;

    // Apply the oil painting effect to the image
    for (int i = radius; i < width - radius; i++) {
        for (int j = radius; j < height - radius; j++) {
            // Initialize vectors to store intensity count and average color values
            vector<int> intensityCount(intensity_levels, 0);
            vector<int> averageR(intensity_levels, 0);
            vector<int> averageG(intensity_levels, 0);
            vector<int> averageB(intensity_levels, 0);

            // Compute intensity levels and update counts and averages
            for (int k = -radius; k <= radius; ++k) {
                for (int l = -radius; l <= radius; ++l) {
                    int r =  image.getPixel(i + k,j + l,0);
                    int g =  image.getPixel(i + k,j + l,1);
                    int b =  image.getPixel(i + k,j + l,2);
                    int intensity = (((r+g+b)/3)* intensity_levels )/ 255;
                    if( intensity > 255 )
                        intensity = 255;
                    int bin = intensity;
                    intensityCount[bin]++;
                    averageR[bin] += r;
                    averageG[bin] += g;
                    averageB[bin] += b;
                }
            }

            // Find the most frequent intensity level
            int current_max = 0;
            int max_index = 0;
            for( int nI = 0; nI < intensity_levels; nI++ )
            {
                if( intensityCount[nI] > current_max )
                {
                    current_max = intensityCount[nI];
                    max_index = nI;
                }
            }

            // Set the pixel to the average color of the most frequent intensity level
            image(i ,j ,0) = averageR[max_index] / current_max;
            image(i ,j ,1) = averageG[max_index] / current_max;
            image(i ,j ,2) = averageB[max_index] / current_max;

        }
    }
    cout << filename1 << endl;

    // sv the grayscale image
    image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// Sunlight filter function
int Sunlight_Filter(const string &filename){

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    // load image
    Image f1(filename1);

    // Create an output image with the same dimensions as the input
    Image image(f1.width, f1.height);

    // Generate a yellow to black gradient
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i, j, 0) = 50;   // Red component
            image(i, j ,1) = 55;    // Green component
            image(i, j, 2) = 0;     // Blue component
        }
    }

    // Blend the input image with the gradient
    for (int i = 0; i < f1.width; ++i) {
        for (int j = 0; j < f1.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (f1(i, j, k) + image(i, j, k)) / 2; // Average the RGB values
            }
        }
    }

    // Increase the brightness of the image
    double factor = 1.11 + (150 / 255.0); // Factor for brightness adjustment
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                int new_value = image(i, j, k) * factor; // Multiply pixel value by the factor
                image(i, j, k) = int(max(0, min(255, new_value))); // Ensure the value is within [0, 255] range
            }
        }
    }
    cout << filename1 << endl;

    // sv the image
    image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// OLd TV Filter function
int Old_TV_Filter(const string &filename) {

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    // load image
    Image image(filename1);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {

                // Applying scanline
                if ((j % 2) == 0) {
                    // lighten pixel to simulate scanline
                    image(i, j, k) = image(i, j, k);
                    image(i, j + 1, k) = image(i, j + 1, k);
                } else {
                    // Add random noise
                    int noise = rand() % 56 - 10;       // random noise in [-45, 45]
                    int Value = image(i, j, k) + noise;
                    Value = min(255, max(0, Value));
                    image(i, j, k) = Value;
                }
            }
        }
    }

    // Decreasing darken degree, Then multiply factor for all Pixel like a ratio of Darken
    double factor = 1.11 + (-48 / 255.0);

    // Darken image after applying Scanline
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int new_value = image(i, j, k) * factor;
                image(i, j, k) = int(max(0, min(255, new_value))); // Check range of RGB and Modify it
            }
        }
    }

    cout << filename1 << endl;

    // sv the image
    image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}



// Merge 2 images function
int Merge_2_Images(const string &filename1, const string &filename2,const int &choice){

    // Initial variables and load the first image
    string filename1_1 =filename1.substr(8, filename1.size() - 1);

    Image image1(filename1_1);

    string filename2_2 =  filename2.substr(8, filename2.size() - 1);

    Image image2(filename2_2); // Load the second image
    int smaller_width = 0, smaller_height = 0, bigger_width = 0, bigger_height = 0;

    // Determine the dimensions of the smaller and bigger images
    if (min(image1.width, image2.width) == image1.width) {
        smaller_width = image1.width;
        smaller_height = image1.height;
        bigger_width = image2.width;
        bigger_height = image2.height;
    } else {
        smaller_width = image2.width;
        smaller_height = image2.height;
        bigger_width = image1.width;
        bigger_height = image1.height;
    }

    if(choice == 1) {
        if(min(image1.width, image2.width) == image1.width) {
            // Resize smaller image to the bigger image dimensions and merge them
            Image new_image(bigger_width, bigger_height);
            const float SCALING_CONST_W = (float) smaller_width / (float) bigger_width;
            const float SCALING_CONST_H = (float) smaller_height / (float) bigger_height;

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        int new_pixel_W = i * SCALING_CONST_W;
                        int new_pixel_H = j * SCALING_CONST_H;
                        new_image(i, j, k) = image1(new_pixel_W, new_pixel_H, k);
                    }
                }
            }

            Image f3(bigger_width, bigger_height);

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (image2(i, j, k) + new_image(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("temporary_file.jpg");
        }
        else{
            // Resize smaller image to the bigger image dimensions and merge them
            Image new_image(bigger_width, bigger_height);
            const float SCALING_CONST_W = (float) smaller_width / (float) bigger_width;
            const float SCALING_CONST_H = (float) smaller_height / (float) bigger_height;

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        int new_pixel_W = i * SCALING_CONST_W;
                        int new_pixel_H = j * SCALING_CONST_H;
                        new_image(i, j, k) = image2(new_pixel_W, new_pixel_H, k);
                    }
                }
            }

            Image f3(bigger_width, bigger_height);

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (image1(i, j, k) + new_image(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("temporary_file.jpg");
        }
    }
    else{
        // Merge the common area of the two images
        if((max(image1.width, image2.width) == image2.width && max(image1.height, image2.height) == image1.height) || (max(image1.width, image2.width) == image1.width && max(image1.height, image2.height) == image2.height)) {
            Image f3(smaller_width, bigger_height);
            for (int i = 0; i < smaller_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (image1(i, j, k) + image2(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("temporary_file.jpg");
        }
        else{
            Image f3(smaller_width, smaller_height);
            for (int i = 0; i < smaller_width; ++i) {
                for (int j = 0; j < smaller_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (image1(i, j, k) + image2(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("temporary_file.jpg");
        }
    }

    cout << filename1 << endl << filename2 << endl;
    return 0;
}

// Resize image function
int Resize_Image(const string &filename, const int &new_width, const int &new_height){

    // Initial variables and load the first image
    string filename1 =filename.substr(8, filename.size() - 1);

    // Load the image
    Image image(filename1);

    // Create a new image with the specified width and height
    Image new_image(new_width, new_height);

    const float SCALING_CONST_W = (float)image.width / (float)new_width;
    const float SCALING_CONST_H = (float)image.height / (float)new_height;

    // Resize the image using nearest-neighbor interpolation
    for (int i = 0; i < new_width; ++i) {
        for (int j = 0; j < new_height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Calculate the corresponding pixel in the original image
                int new_pixel_W = i * SCALING_CONST_W;
                int new_pixel_H = j * SCALING_CONST_H;
                // Copy the pixel value to the new image
                new_image(i, j, k) = image(new_pixel_W, new_pixel_H, k);
            }
        }
    }

    cout << filename1 << endl;

    // sv the image
    new_image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

int SaveImage(const string &filename){

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    Image temp("temporary_file.jpg");

    temp.sv(filename1);

    return 0;
}


ImageProcessor1::ImageProcessor1(QObject *parent) : QObject(parent) {}

int ImageProcessor1::applyGrayScale(const QString &filename) {
    return GrayScale_Filter(filename.toStdString());
}

ImageProcessor2::ImageProcessor2(QObject *parent) : QObject(parent) {}

int ImageProcessor2::applyBlackAndWhite(const QString &filename) {
    return BlackAndWhite_Filter(filename.toStdString());
}

ImageProcessor3::ImageProcessor3(QObject *parent) : QObject(parent) {}

int ImageProcessor3::applyPurple(const QString &filename) {
    return Purple_Filter(filename.toStdString());
}

ImageProcessor4::ImageProcessor4(QObject *parent) : QObject(parent) {}

int ImageProcessor4::applyInvert(const QString &filename) {
    return Invert_Filter(filename.toStdString());
}

ImageProcessor5::ImageProcessor5(QObject *parent) : QObject(parent) {}

int ImageProcessor5::applyInfrared(const QString &filename) {
    return Infrared_Filter(filename.toStdString());
}

ImageProcessor6::ImageProcessor6(QObject *parent) : QObject(parent) {}

int ImageProcessor6::applyNoise(const QString &filename) {
    return Noise_Filter(filename.toStdString());
}

ImageProcessor7::ImageProcessor7(QObject *parent) : QObject(parent) {}

int ImageProcessor7::applyNightVision(const QString &filename) {
    return NightVision_Filter(filename.toStdString());
}

ImageProcessor8::ImageProcessor8(QObject *parent) : QObject(parent) {}

int ImageProcessor8::applyDetectEdges(const QString &filename) {
    return Detect_Image_Edges(filename.toStdString());
}

ImageProcessor9::ImageProcessor9(QObject *parent) : QObject(parent) {}

int ImageProcessor9::applyOilPainting(const QString &filename) {
    return OilPainting_Filter(filename.toStdString());
}

ImageProcessor10::ImageProcessor10(QObject *parent) : QObject(parent) {}

int ImageProcessor10::applySunlight(const QString &filename) {
    return Sunlight_Filter(filename.toStdString());
}

ImageProcessor11::ImageProcessor11(QObject *parent) : QObject(parent) {}

int ImageProcessor11::applyOldTV(const QString &filename) {
    return Old_TV_Filter(filename.toStdString());
}

ImageProcessor12::ImageProcessor12(QObject *parent) : QObject(parent) {}

int ImageProcessor12::savingImage(const QString &filename) {
    return SaveImage(filename.toStdString());
}

ImageProcessor13::ImageProcessor13(QObject *parent) : QObject(parent) {}

int ImageProcessor13::applyMerge(const QString &filename1, const QString &filename2, const int choice) {
    return Merge_2_Images(filename1.toStdString(), filename2.toStdString(), choice);
}

ImageProcessor14::ImageProcessor14(QObject *parent) : QObject(parent) {}

int ImageProcessor14::applyResize(const QString &filename1, const int &new_width, const int &new_height) {
    return Resize_Image(filename1.toStdString(), new_width, new_height);
}
