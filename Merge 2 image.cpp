#include <bits/stdc++.h>
#include "Image_class.h"
using namespace std;

int main() {
    cout << "Hello" << endl;

    Image f1("mario.bmp");
    Image f2("gamma_adjusted_image.jpg");

    if ((min(f1.height, f2.height) == f1.height && min(f1.width, f2.width) == f1.width) || (min(f1.height, f2.height) == f1.height && min(f1.width, f2.width) == f1.width)) {

        cout << "HELLO, WORLD!" << endl;

        Image new_image(f1.width, f1.height);

        const float SCALING_CONST_W = (float) f2.width / (float) f1.width;
        const float SCALING_CONST_H = (float) f2.height / (float) f1.height;

        for (int i = 0; i < f1.width; ++i) {
            for (int j = 0; j < f1.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int new_pixel_W = i * SCALING_CONST_W;
                    int new_pixel_H = j * SCALING_CONST_H;
                    new_image(i, j, k) = f2(new_pixel_W, new_pixel_H, k);
                }
            }
        }

        Image f3(f1.width, f1.height);
        cout << "Done." << endl;
        for (int i = 0; i < f1.width; ++i) {
            for (int j = 0; j < f1.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    f3(i, j, k) = (f1(i, j, k) + new_image(i, j, k)) / 2;
                }
            }
        }

        f3.saveImage("new.jpg");
        cout << "Wo0oW" << endl;

    } else {

        cout << "HELLO, WORLD!" << endl;

        Image new_image(f2.width, f2.height);

        const float SCALING_CONST_W = (float) f1.width / (float) f2.width;
        const float SCALING_CONST_H = (float) f1.height / (float) f2.height;

        for (int i = 0; i < f2.width; ++i) {
            for (int j = 0; j < f2.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int new_pixel_W = i * SCALING_CONST_W;
                    int new_pixel_H = j * SCALING_CONST_H;
                    new_image(i, j, k) = f1(new_pixel_W, new_pixel_H, k);
                }
            }
        }

        Image f3(f2.width, f2.height);
        cout << "Done." << endl;
        for (int i = 0; i < f2.width; ++i) {
            for (int j = 0; j < f2.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    f3(i, j, k) = (f2(i, j, k) + new_image(i, j, k)) / 2;
                }
            }
        }

        f3.saveImage("new.jpg");
        cout << "Wo0oW" << endl;
    }
}}