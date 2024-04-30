#include <bits/stdc++.h>
#include "Image_class.h"
#include <windows.h>
#include <cmath>

using namespace std;

int main(){

    Image image("Wano 2.jpg");


    // Set the radius of the painting effect
    int radius = 1;
    int height = image.height;
    int width = image.width;
    const int num_intensity_levels = 10;

    for (int i = radius; i < width - radius; i++) {
        for (int j = radius; j < height - radius; j++) {
            int intensityCount[num_intensity_levels] = {0};
            int averageR[num_intensity_levels] = {0};
            int averageG[num_intensity_levels] = {0};
            int averageB[num_intensity_levels] = {0};

            // Calculate the average intensity and color values for each pixel in the neighborhood
            for (int k = -radius; k <= radius; ++k) {
                for (int l = -radius; l <= radius; ++l) {
                    int r = image.getPixel(i + k, j + l, 0);
                    int g = image.getPixel(i + k, j + l, 1);
                    int b = image.getPixel(i + k, j + l, 2);
                    int intensity = (((r+g+b)/3)* num_intensity_levels )/ 255; // Use floating-point arithmetic for accuracy
                    int bin = intensity;
                    intensityCount[bin]++;
                    averageR[bin] += r;
                    averageG[bin] += g;
                    averageB[bin] += b;
                }
            }

            // Find the intensity level with the maximum count
            int current_max = 0;
            int max_index = 0;
            for (int nI = 0; nI < num_intensity_levels; nI++) {
                if (intensityCount[nI] > current_max) {
                    current_max = intensityCount[nI];
                    max_index = nI;
                }
            }

            // Set the pixel color to the average color of the most frequent intensity level
            image(i, j, 0) = averageR[max_index] / current_max;
            image(i, j, 1) = averageG[max_index] / current_max;
            image(i, j, 2) = averageB[max_index] / current_max;
        }
    }
    image.saveImage("oilpainting.jpg");
    cout << "done" ;

}