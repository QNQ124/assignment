#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Image_Class.h"
#include "ImageProcessor.h"
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
    int intensity_levels = 10;

    int height = image.height;
    int width = image.width;
    // Initialize arrays to store intensity count and average color values
    int intensityCount[10] = {0};
    int averageR[10] = {0};
    int averageG[10] = {0};
    int averageB[10] = {0};

    // Apply the oil painting effect to the image
    for (int i = radius; i < width - radius; i++) {
        for (int j = radius; j < height - radius; j++) {
            // Reset the arrays for each pixel
            memset(intensityCount, 0, sizeof(intensityCount));
            memset(averageR, 0, sizeof(averageR));
            memset(averageG, 0, sizeof(averageG));
            memset(averageB, 0, sizeof(averageB));

            // Compute intensity levels and update counts and averages
            for (int k = -radius; k <= radius; ++k) {
                for (int l = -radius; l <= radius; ++l) {
                    int r =  image.gp(i + k,j + l,0);
                    int g =  image.gp(i + k,j + l,1);
                    int b =  image.gp(i + k,j + l,2);
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
            image(i ,j ,0) = averageR[max_index];
            image(i ,j ,1) = averageG[max_index];
            image(i ,j ,2) = averageB[max_index];

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

// Flip image function
int Flip_Image(const string &filename, const int &choice){

    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    Image image(filename1); // Load the image

    while (true)
    {
        // Perform the selected flip operation
        if (choice == 1) // Flip horizontally
        {
            for (int i = 0; i < image.width / 2; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    uint pixel1;
                    uint pixel2;
                    int width = image.width;
                    for (int k = 0; k < 3; ++k) {
                        // Swap pixels horizontally
                        pixel1 = image.gp(i,j,k);
                        pixel2 = image.gp(width - i -1,j,k);
                        image.setPixel(i,j,k,pixel2);
                        image.setPixel(width - i - 1,j,k,pixel1);
                    }
                }
            }
            break; // Exit the loop
        }
        else // Flip vertically
        {
            for (int i = 0; i < image.width ; ++i) {
                for (int j = 0; j < image.height / 2; ++j) {
                    uint pixel1;
                    uint pixel2;
                    int height = image.height;
                    for (int k = 0; k < 3; ++k) {
                        // Swap pixels vertically
                        pixel1 = image.gp(i,j,k);
                        pixel2 = image.gp(i, height - j - 1,k);
                        image.setPixel(i,j,k,pixel2);
                        image.setPixel(i,height - j - 1,k,pixel1);
                    }
                }
            }
            break; // Exit the loop
        }

    }

    cout << filename1 << endl;

    // sv the image
    image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// Skewing Filter function
int Skewing_Filter(const string &filename, const int &angle){

     // Initial variables and load image
    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    Image pic(filename1);

    int width = pic.width;
    int height = pic.height;
    double added_width = sin((angle) * (3.14159/180)) * (double)height;
    const double SKEWING_CONST =  ((double)added_width/height);
    int new_width = added_width + width;
    Image image(new_width,height);

    for (int i = 0; i < new_width; ++i) {
        for (int j = 0; j < height; ++j) {
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;
        }
    }
    // Skew the image
    for (int i = 0; i < width ; ++i)
    {
        added_width = sin((angle) * (3.14159/180)) * (double)height;
        for (int j = 0; j < height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i + added_width,j,k) = pic(i,j,k);
            }
            added_width -=  SKEWING_CONST;
        }
    }

    cout << filename1 << endl;

    // save the image
    image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// Rotate image function
int Rotate_Image(const string &filename, const int &degree_rotation){

    // Initial variables and load image
    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    Image image(filename1);


    // Create new Image objects for different rotations
    Image new_photo_180(image.width,image.height);
    Image new_photo_270(image.height,image.width);
    Image new_photo_90(image.height,image.width);

    // Perform the rotation based on user input
    if(degree_rotation == 180)
    {
        for(int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++) // Assuming 3 color channels (RGB)
                {
                    new_photo_180(image.width-i-1,image.height-j-1,k)=image(i,j,k); // Rotate 180 degrees
                }
            }
        }
    }
    else if (degree_rotation == 270)
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    new_photo_270(j, image.width - i - 1, k) = image(i, j, k); // Rotate 270 degrees
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    new_photo_90(image.height - j - 1, i, k) = image(i, j, k); // Rotate 90 degrees
                }
            }
        }
    }

    if(degree_rotation == 180)
        new_photo_180.sv("temporary_file.jpg"); // save the current Filter in temporary file
    else if(degree_rotation == 270)
        new_photo_270.sv("temporary_file.jpg"); // save the current Filter in temporary file
    else
        new_photo_90.sv("temporary_file.jpg"); // save the current Filter in temporary file

    return 0; // Return value as needed
}

// Blur image function
int Blur_Image(const string &filename, int blur_level){

    // Initial variables and load image
    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    Image photo(filename1);

    blur_level++;

    // Calculate resized dimensions while maintaining aspect ratio
    int resized_width, resized_height;
    if (photo.width > photo.height) {
        resized_width = 800;
        resized_height = photo.height * 800 / photo.width;
    } else {
        resized_height = 800;
        resized_width = photo.width * 800 / photo.height;
    }

    // Resize the image for blurring
    Image resized_photo(resized_width, resized_height);
    Image new_image(resized_width,resized_height);

    const float SCALING_CONST_W = (float) photo.width / (float) resized_width;
    const float SCALING_CONST_H = (float) photo.height / (float) resized_height;

    for (int i = 0; i < resized_width; ++i) {
        for (int j = 0; j < resized_height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int new_pixel_W = i * SCALING_CONST_W;
                int new_pixel_H = j * SCALING_CONST_H;
                resized_photo(i, j, k) = photo(new_pixel_W, new_pixel_H, k);
            }
        }
    }

    // Blur parameters
    int kernel_size = 5 + blur_level * 4; // Increase kernel size for higher blur levels
    double sigma = 30 + blur_level * 10;  // Increase sigma value for higher blur levels

    // Apply blur operation
    for (int i = 0; i < resized_width; i++)
    {
        for (int j = 0; j < resized_height; j++)
        {
            double weighted_sum[3] = {0.0}; // Initialize array for each channel
            double sum_of_weights = 0.0;

            // Iterate over each pixel in the neighborhood according to the kernel size
            for (int x = -kernel_size / 2; x <= kernel_size / 2; x++)
            {
                for (int y = -kernel_size / 2; y <= kernel_size / 2; y++)
                {
                    int neighbor_x = i + x;
                    int neighbor_y = j + y;

                    // Check boundary conditions
                    if (neighbor_x >= 0 && neighbor_x < resized_width && neighbor_y >= 0 && neighbor_y < resized_height)
                    {
                        double weight = exp(-(x * x + y * y) / (2 * sigma * sigma)) / (2 * M_PI * sigma * sigma);
                        // Get pixel value for each channel
                        for (int c = 0; c < 3; c++)
                        {
                            weighted_sum[c] += weight * resized_photo(neighbor_x, neighbor_y, c);
                        }
                        sum_of_weights += weight;
                    }
                }
            }
            // Assign the blurred pixel values back to the image
            for (int c = 0; c < 3; c++)
            {
                new_image(i, j, c) = weighted_sum[c] / sum_of_weights;
            }
        }
    }

    // Resize the image back to its original size
    Image new_image1(photo.width,photo.height);

    const float SCALING_CONST_W2 = (float)resized_width/(float)photo.width ;
    const float SCALING_CONST_H2 = (float)resized_height/(float)photo.height;

    for (int i = 0; i < photo.width; ++i) {
        for (int j = 0; j < photo.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int new_pixel_W = i * SCALING_CONST_W2;
                int new_pixel_H = j * SCALING_CONST_H2;
                new_image1(i,j,k) = new_image(new_pixel_W,new_pixel_H,k);
            }
        }
    }

    cout << filename1 << endl;

    // save the image
    new_image1.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

// Darken and Lighten function
int DarkenAndLighten_image(const string &filename, int num_brightness, int choice1){

    // Initial variables and load image
    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    double factor;
    Image image(filename1);

    // Adjust the brightness based on the user's choice
    if (choice1 == 1) {
        num_brightness = -1 * num_brightness;
        factor = 1.11 + (num_brightness / 255.0);
    } else {
        // Lighten the image
        num_brightness = min(255, num_brightness);
        factor = 1.11 + (num_brightness / 255.0);
    }

    // Apply the brightness adjustment to the image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int new_value = image(i, j, k) * factor;
                image(i, j, k) = int(max(0, min(255, new_value)));
            }
        }
    }

    cout << filename1 << endl;

    // save the image
    image.sv("temporary_file.jpg"); // Save the image with a new filename

    return 0; // Return value as needed
}

// Frame to image function
int Frame_to_Image(const string &filename, int choice, int color){

    // Initial variables and load image
    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    Image photo(filename1);

    if(choice == 1)
    {
        // Calculate frame size as a fraction of the smaller dimension of the image
        int frame_size = min(photo.width, photo.height) / 20; // Adjust divisor (e.g., 20) for desired thickness

        // Calculate frame dimensions
        int frame_width = photo.width + 2 * frame_size;
        int frame_height = photo.height + 2 * frame_size;

        // Create framed photo with calculated frame dimensions
        Image framed_photo(frame_width, frame_height);

        // Set the frame color
        for (int i = 0; i < framed_photo.width; i++) {
            for (int j = 0; j < framed_photo.height; j++) {
                if (i < frame_size || j < frame_size || i >= frame_width - frame_size || j >= frame_height - frame_size)
                {
                    // Set the color based on user's choice
                    if (color == 1) {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == 2) {
                        framed_photo(i, j, 0) = 255;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == 3) {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 255;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == 4) {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 255;
                    } else if (color == 5) {
                        framed_photo(i, j, 0) = 255;
                        framed_photo(i, j, 1) = 255;
                        framed_photo(i, j, 2) = 255;
                    }
                }
            }
        }

        // Copy original image onto the frame
        for (int i = 0; i < photo.width; i++) {
            for (int j = 0; j < photo.height; j++) {
                for (int k = 0; k < 3; k++) {
                    framed_photo(i + frame_size, j + frame_size, k) = photo(i, j, k);
                }
            }
        }

        // Save the framed photo
        framed_photo.saveImage("temporary_file.jpg");
    }
    else {
        // Calculate frame size as a fraction of the smaller dimension of the image
        int frame_size = min(photo.width, photo.height) / 25; // Adjust divisor for desired thickness
        int frame_width = photo.width + 2 * frame_size;
        int frame_height = photo.height + 2 * frame_size;

        // Create framed photo with calculated frame dimensions
        Image framed_photo(frame_width, frame_height);

        // Set the frame color
        for (int i = 0; i < framed_photo.width; i++) {
            for (int j = 0; j < framed_photo.height; j++) {
                if (i < frame_size || j < frame_size || i >= frame_width - frame_size || j >= frame_height - frame_size) {
                    // Set the color based on user's choice
                    if (color == 1) {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == 2) {
                        framed_photo(i, j, 0) = 255;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == 3) {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 255;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == 4) {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 255;
                    } else if (color == 5) {
                        framed_photo(i, j, 0) = 255;
                        framed_photo(i, j, 1) = 255;
                        framed_photo(i, j, 2) = 255;
                    }
                }
            }
        }

        // Copy original image onto the frame
        for (int i = 0; i < photo.width; i++) {
            for (int j = 0; j < photo.height; j++) {
                for (int k = 0; k < 3; k++) {
                    framed_photo(i + frame_size, j + frame_size, k) = photo(i, j, k);
                }
            }
        }

        // Add horizontal stripes with space in between
        int space_between_stripes = 10; // Adjust as needed
        for (int i = frame_size; i < frame_width - frame_size; i++)
        {
            if (i % (2 * space_between_stripes) < space_between_stripes)
            {
                for (int j = 0; j < frame_size; j++)
                {
                    // Set the color to gray for the stripes
                    framed_photo(i, j, 0) = 128; // Red component   (top)
                    framed_photo(i, j, 1) = 128; // Green component (top)
                    framed_photo(i, j, 2) = 128; // Blue component  (top)
                    framed_photo(i, frame_height - frame_size + j, 0) = 128; // Red component   (bottom)
                    framed_photo(i, frame_height - frame_size + j, 1) = 128; // Green component (bottom)
                    framed_photo(i, frame_height - frame_size + j, 2) = 128; // Blue component  (bottom)
                }
            }
        }

        // Add vertical stripes with space in between
        for (int j = frame_size; j < frame_height - frame_size; j++)
        {
            if (j % (2 * space_between_stripes) < space_between_stripes)
            {
                for (int i = 0; i < frame_size; i++)
                {
                    // Set the color to gray for the stripes
                    framed_photo(i, j, 0) = 128; // Red component
                    framed_photo(i, j, 1) = 128; // Green component
                    framed_photo(i, j, 2) = 128; // Blue component
                    framed_photo(frame_width - frame_size + i, j, 0) = 128; // Red component (right)
                    framed_photo(frame_width - frame_size + i, j, 1) = 128; // Green component (right)
                    framed_photo(frame_width - frame_size + i, j, 2) = 128; // Blue component (right)
                }
            }
        }

        // Save the framed photo
        framed_photo.saveImage("temporary_file.jpg");
    }
    cout << filename1 << endl;
    return 0;
}

int checkWidth_ForCrop(const string &filename){

    // Initial variables and load image
    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    Image photo(filename1);

    return photo.width;
}

int checkHeight_ForCrop(const string &filename){

    // Initial variables and load image
    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    Image photo(filename1);

    return photo.height;
}

// Crop image function
int Crop_Image(const string &filename, int crop_width, int crop_height, int crop_start_x, int crop_start_y) {

    // Initial variables and load image
    string filename1 = filename.substr(8, filename.size() - 1);

    cout << filename << endl << filename1 << endl;

    Image image(filename1);
    // Create a new image to store the cropped portion
    Image cropped_image(crop_width, crop_height);

    // Copy the pixels from the original image to the cropped image
    int x = 0;
    for (int i = crop_start_x; i < crop_width; ++i) {
        int y = 0;
        for (int j = crop_start_y; j < crop_height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                cropped_image(x, y, k) = image(i, j, k);
            }
            y++;
        }
        x++;
    }

    cout << filename1 << endl;

    // save the image
    cropped_image.sv("temporary_file.jpg"); // Save the grayscale image with a new filename

    return 0; // Return value as needed
}

int SaveImage(const string &filename, const string &newfilename){

    string filename1 = filename.substr(8, filename.size() - 1);

    int count = filename1.size() - 1;

    for (int i = count; i >= 0; --i) {
        if(filename1[i] == '/')
            break;
        else{
            filename1[i] = '>';
        }
    }
    filename1.erase(remove(filename1.begin(), filename1.end(), '>'), filename1.end());

    string filename3 = filename1 + newfilename; // Copy filename1 to avoid resizing issues

    cout << filename3 << endl;

    ifstream file;
    file.open(filename3);

    int size = newfilename.size();
    if(file){
        return 1;
    }
    else if((size < 5 || (newfilename.substr(size - 4, size) != ".jpg" && newfilename.substr(size - 4, size) != ".bmp" && newfilename.substr(size - 4, size) != ".png")) && (size < 6 || (newfilename.substr(size - 5, size) != ".jpeg"))) {
        return 2;
    }
    else if(newfilename.find_first_of("/\\:*?<>|\"") != std::string::npos){
        return 3;
    }
    else{

    Image temp("temporary_file.jpg");

    cout << filename3 << endl;
    temp.sv("hello.jpg");
    temp.sv(filename3);
    }

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

int ImageProcessor12::savingImage(const QString &filename, const QString &newfilename) {
    return SaveImage(filename.toStdString(), newfilename.toStdString());
}

ImageProcessor13::ImageProcessor13(QObject *parent) : QObject(parent) {}

int ImageProcessor13::applyMerge(const QString &filename1, const QString &filename2, const int choice) {
    return Merge_2_Images(filename1.toStdString(), filename2.toStdString(), choice);
}

ImageProcessor14::ImageProcessor14(QObject *parent) : QObject(parent) {}

int ImageProcessor14::applyResize(const QString &filename, const int &new_width, const int &new_height) {
    return Resize_Image(filename.toStdString(), new_width, new_height);
}

ImageProcessor15::ImageProcessor15(QObject *parent) : QObject(parent) {}

int ImageProcessor15::applyFlip(const QString &filename, const int &choice) {
    return Flip_Image(filename.toStdString(), choice);
}

ImageProcessor16::ImageProcessor16(QObject *parent) : QObject(parent) {}

int ImageProcessor16::applySkewing(const QString &filename, const int &angle) {
    return Skewing_Filter(filename.toStdString(), angle);
}

ImageProcessor17::ImageProcessor17(QObject *parent) : QObject(parent) {}

int ImageProcessor17::applyRotate(const QString &filename, const int &degree_rotation) {
    return Rotate_Image(filename.toStdString(), degree_rotation);
}

ImageProcessor18::ImageProcessor18(QObject *parent) : QObject(parent) {}

int ImageProcessor18::applyBlur(const QString &filename, int blur_level) {
    return Blur_Image(filename.toStdString(), blur_level);
}

ImageProcessor19::ImageProcessor19(QObject *parent) : QObject(parent) {}

int ImageProcessor19::applyBrightness(const QString &filename, int num_brightness, int choice1) {
    return DarkenAndLighten_image(filename.toStdString(), num_brightness, choice1);
}

ImageProcessor20::ImageProcessor20(QObject *parent) : QObject(parent) {}

int ImageProcessor20::applyFrame(const QString &filename, int choice, int color) {
    return Frame_to_Image(filename.toStdString(), choice, color);
}

ImageProcessor21::ImageProcessor21(QObject *parent) : QObject(parent) {}

int ImageProcessor21::checkCropWidth(const QString &filename) {
    return checkWidth_ForCrop(filename.toStdString());
}

ImageProcessor22::ImageProcessor22(QObject *parent) : QObject(parent) {}

int ImageProcessor22::checkCropHeight(const QString &filename) {
    return checkHeight_ForCrop(filename.toStdString());
}

ImageProcessor23::ImageProcessor23(QObject *parent) : QObject(parent) {}

int ImageProcessor23::applyCrop(const QString &filename, int crop_width, int crop_height, int crop_start_x, int crop_start_y){
    return Crop_Image(filename.toStdString(), crop_width, crop_height, crop_start_x, crop_start_y);
}
