#include <bits/stdc++.h>
#include "Image_class.h"
using namespace std;

int main()
{
    cout << "HELLO, WORLD!" << endl;
    Image image("building.jpg");

    int new_width;
    int new_height;

    int old_width = image.width , old_height = image.height;

    cout << "enter image new width" << endl;
    cin >> new_width ;
    cout << "enter image new height " << endl;
    cin >> new_height;

    Image new_image(new_width,new_height);

    

    const float SCALING_CONST_W = (float)image.width/(float)new_width ;
    const float SCALING_CONST_H = (float)image.height/(float)new_height;

    float remenant_W = ((float)image.width/(float)new_width) - SCALING_CONST_W;
    float remenant_H = ((float)image.height/(float)new_height) - SCALING_CONST_H;



    int scaling_value_W = SCALING_CONST_W;
    int scaling_value_H = SCALING_CONST_H ;


    for (int i = 0; i < new_width; ++i) {
        for (int j = 0; j < new_height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int new_pixel_W = i * SCALING_CONST_W;
                int new_pixel_H = j * SCALING_CONST_H;
                new_image(i,j,k) = image(new_pixel_W,new_pixel_H,k);
            }
        }
    }

    new_image.saveImage("resized image.jpg");
    cout << "Done.";

}

