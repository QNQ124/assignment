#include <bits/stdc++.h>
#include "Image_class.h"
#include <windows.h>
#include <cmath>
using namespace std;


int main()
{

    Image pic("building.jpg");

    double angle;
    cout << "enter the angle : " ;
    cin >> angle ;
    int height = pic.height;
    int width = pic.width;
    double added_width = cos(angle * (3.14159/180)) * (double)height;
    int new_width = added_width + width ;
    const double SKEWING_CONST =  ((double)added_width/height);
    double x = (added_width/height);
    cout << x << endl ;
    Image sk_pic(new_width,height);
    for (int i = 0; i < height; ++i) {
        added_width -= SKEWING_CONST;
    }
    cout << added_width << endl;
    for (int i = 0; i < width ; ++i)
    {
        added_width = cos(angle * (3.14159/180)) * (double)height;
        for (int j = 0; j < height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                sk_pic(i + added_width,j,k) = pic(i,j,k);
            }
            added_width -=  SKEWING_CONST;
        }
    }

    sk_pic.saveImage("skewed.jpg");
    cout << "Done";

}