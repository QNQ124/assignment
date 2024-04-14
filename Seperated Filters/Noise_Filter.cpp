#include <bits/stdc++.h>
#include "Image_class.h"
#include <windows.h>
#include <cmath>
using namespace std;


int main(){

    string file_name, Newfile_name;
    Image photo("luffy.jpg");

    // brightness image after applying
    for (int i = 0; i < photo.width; i++) {
        for (int j = 0; j < photo.height; j++) {
            for (int k = 0; k < photo.channels; k++) {

                double factor = 1.11 + (-1 * (rand() % 121) / 255.0);
                int new_value = photo(i, j, k) * factor;
                photo(i, j, k) = int(max(0, min(255, new_value))); // Check range of RGB and Modify it

            }
        }
    }

    photo.saveImage("night.jpg");

}