#include <bits/stdc++.h>
#include "Image_class.h"
using namespace std;

int main() {
    cout << "Hello" << endl;

    string choice1;
    Image f2("toy2.jpg");
    Image f1("toy1.jpg");
    int smaller_width = 0, smaller_height = 0, bigger_width = 0, bigger_height = 0;
    cout << "|- What you want to do? -|\n";
    cout << "1) Resize both images    |\n";
    cout << "2) Merge the common area |\n";
    cout << "Choose from the menu [1, 2]: ";
    getline(cin, choice1);

    while (true) {
        if (choice1 == "1" || choice1 == "2")
            break;
        else {
            cout << "Choose from the menu [1, 2]: ";
            getline(cin, choice1);
        }
    }

    if (min(f1.width, f2.width) == f1.width) {
        smaller_width = f1.width;
        smaller_height = f1.height;
        bigger_width = f2.width;
        bigger_height = f2.height;
    } else {
        smaller_width = f2.width;
        smaller_height = f2.height;
        bigger_width = f1.width;
        bigger_height = f1.height;
    }


    if(choice1 == "1") {
        if(min(f1.width, f2.width) == f1.width) {
            Image new_image(bigger_width, bigger_height);
            const float SCALING_CONST_W = (float) smaller_width / (float) bigger_width;
            const float SCALING_CONST_H = (float) smaller_height / (float) bigger_height;

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        int new_pixel_W = i * SCALING_CONST_W;
                        int new_pixel_H = j * SCALING_CONST_H;
                        new_image(i, j, k) = f1(new_pixel_W, new_pixel_H, k);
                    }
                }
            }

            new_image.saveImage("wow.jpg");
            Image f3(bigger_width, bigger_height);

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (f2(i, j, k) + new_image(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("sss.jpg");
        }
        else{
            Image new_image(bigger_width, bigger_height);
            const float SCALING_CONST_W = (float) smaller_width / (float) bigger_width;
            const float SCALING_CONST_H = (float) smaller_height / (float) bigger_height;

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        int new_pixel_W = i * SCALING_CONST_W;
                        int new_pixel_H = j * SCALING_CONST_H;
                        new_image(i, j, k) = f2(new_pixel_W, new_pixel_H, k);
                    }
                }
            }

            new_image.saveImage("wow.jpg");
            Image f3(bigger_width, bigger_height);

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (f1(i, j, k) + new_image(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("sss.jpg");
        }
    }
    else{
        if(max(f1.width, f2.width) == f2.width && max(f1.height, f2.height) == f1.height) {
            Image f3(smaller_width, bigger_height);
            for (int i = 0; i < smaller_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (f1(i, j, k) + f2(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("sss.jpg");
        }

        else{
            Image f3(smaller_width, smaller_height);
            for (int i = 0; i < smaller_width; ++i) {
                for (int j = 0; j < smaller_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (f1(i, j, k) + f2(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("sss.jpg");
        }
    }
}