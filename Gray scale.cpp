#include <bits/stdc++.h>
#include "Image_class.h"  
using namespace std;


int main(){
    cout << "HELLO, WORLD!" << endl;
    Image f("luffy.jpg");


    for (int i = 0; i < f.width; ++i){
        for (int j = 0; j < f.height; ++j){ 

            unsigned int average = 0;

            for (int k = 0; k < 3; ++k){

            average += f(i,j,k);

            }

            average /= 3;

            for (int k = 0; k < 3; ++k) {
                f(i,j,k) = average;
            }
        }
    }

    f.saveImage("gray_scale.jpg");

    cout << "HELLO, WORLD!" << endl;

}
