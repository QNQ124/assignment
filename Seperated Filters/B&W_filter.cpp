#include <bits/stdc++.h>
#include "Image_class.h"
using namespace std;


int main() {
    cout << "HELLO, WORLD!" << endl;
    Image f("building.jpg");


    for (int i = 0; i < f.width; ++i) {
        for (int j = 0; j < f.height; ++j) {

            unsigned int average = 0;

            for (int k = 0; k < 3; ++k) {

                average += f(i, j, k);

            }

            average /= 3;

            for (int k = 0; k < 3; ++k) {
                f(i, j, k) = average;
            }
        }
    }
    for (int i = 0; i < f.width; ++i) {
        for (int j = 0; j < f.height; ++j) {
            if (f(i, j, 0) >= 127) {
                f(i, j, 0) = 255;
                f(i, j, 1) = 255;
                f(i, j, 2) = 255;
            } else
            {
                f(i, j, 0) = 0;
                f(i, j, 1) = 0;
                f(i, j, 2) = 0;
            }

        }
    }
    f.saveImage("B&W_test.jpg");
    cout << "Done" ;
}