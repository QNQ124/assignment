#include <bits/stdc++.h>
#include "Image_class.h"
#include <windows.h>
#include <cmath>
using namespace std;


int main()
{
    Image pic("night3.jpg");


    int radius = 1;
    int height = pic.height;
    int width = pic.width;
    int intensity_levels = 10;

    for (int i = radius; i < width - radius; i++) {
        for (int j = radius; j < height - radius; j++) {
            vector<int> intensityCount(intensity_levels, 0);
            vector<int> averageR(intensity_levels, 0);
            vector<int> averageG(intensity_levels, 0);
            vector<int> averageB(intensity_levels, 0);

            for (int k = -radius; k <= radius; ++k) {
                for (int l = -radius; l <= radius; ++l) {
                    int r =  pic.getPixel(i + k,j + l,0);
                    int g =  pic.getPixel(i + k,j + l,1);
                    int b =  pic.getPixel(i + k,j + l,2);
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
            int current_max = 0;
            int maxindex = 0;
            for( int nI = 0; nI < intensity_levels; nI++ )
            {
                if( intensityCount[nI] > current_max )
                {
                    current_max = intensityCount[nI];
                    maxindex = nI;
                }
            }

                    pic(i ,j ,0) = averageR[maxindex] / current_max;
                    pic(i ,j ,1) = averageG[maxindex] / current_max;
                    pic(i ,j ,2) = averageB[maxindex] / current_max;

        }
    }
    pic.saveImage("oilpainting.jpg");
    cout << "done" ;

}