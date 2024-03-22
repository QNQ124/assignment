#include <iostream>
#include <string>
#include <cmath>
#include "Image_Class.h" // Assuming this header contains the Image class declaration
using namespace std;

void Inverted_Image()
{
    string file_name , Newfile_name;
    cout<<"Please enter the file name: "<<endl;
    cin>>file_name;
    cout<<"Please enter the NEW file name: "<<endl;
    cin>>Newfile_name;


    Image photo(file_name); // Assuming Image class constructor takes a filename

    for(int i = 0; i < photo.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < photo.height; j++) // Using .height to get image height
        {
            for (int k = 0; k < 3; k++) // Assuming 3 color channels (RGB)
            {
                unsigned int pixel_color = photo.getPixel(i, j, k); // Assuming getPixel method exists
                unsigned int pixel_inverted_color = 255 - pixel_color; // Inverting color
                photo.setPixel(i, j, k, pixel_inverted_color); // Assuming setPixel method exists
            }
        }
    }
    photo.saveImage(Newfile_name); // Assuming saveImage method exists
}


double GaussianKernel(int x, int y, double sigma)
{
    return exp(-(x * x + y * y) / (2 * sigma * sigma)) / (2 * M_PI * sigma * sigma);
}


void Blur_image()
{
    string file_name , Newfile_name;

    cout<<"Please enter the file name: "<<endl;
    cin>>file_name;
    cout<<"Please enter the NEW file name: "<<endl;
    cin>>Newfile_name;

    Image photo(file_name);
    double sigma = 10; // Increased sigma value for more blurring
    int kernel_size = 5; // Increased kernel size
    int num_passes = 5; // Number of passes for blurring

    for (int pass = 0; pass < num_passes; pass++) {
        for (int i = 0; i < photo.width; i++) {
            for (int j = 0; j < photo.height; j++) {
                double weighted_sum[3] = {0.0}; // Initialize array for each channel
                double sum_of_weights = 0.0;

                // Iterate over each pixel in the neighborhood according to the kernel size
                for (int x = -kernel_size / 2; x <= kernel_size / 2; x++) {
                    for (int y = -kernel_size / 2; y <= kernel_size / 2; y++) {
                        int neighbor_x = i + x;
                        int neighbor_y = j + y;
                        // Check boundary conditions
                        if (neighbor_x >= 0 && neighbor_x < photo.width && neighbor_y >= 0 && neighbor_y < photo.height) {
                            // Calculate weight using Gaussian kernel
                            double weight = GaussianKernel(x, y, sigma);
                            // Get pixel value for each channel
                            for (int c = 0; c < 3; c++) {
                                weighted_sum[c] += weight * photo.getPixel(neighbor_x, neighbor_y, c);
                            }
                            sum_of_weights += weight;
                        }
                    }
                }
                // Assign the blurred pixel values back to the image
                for (int c = 0; c < 3; c++) {
                    photo.setPixel(i, j, c, weighted_sum[c] / sum_of_weights);
                }
            }
        }
    }
    // Save the blurred image
    photo.saveImage(Newfile_name);
}


int main()
{

    Blur_image();
}
