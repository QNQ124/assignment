#include <bits/stdc++.h>
#include "Image_class.h"
using namespace std;

int main()
{

    Image image("building.jpg");
    int crop_width;
    int crop_height;
    int crop_start_x;
    int crop_start_y;
    cout << "enter the width for the cropped image : " ;
    cin >> crop_width;
    while ( crop_width > image.width)
    {
        cout << "invalid input, width is larger than the original image's width" << endl;
        cout << "enter the width for the cropped image : " ;
        cin >> crop_width;
    }
    cout << "enter the height for the cropped image : " ;
    cin >> crop_height;
    while ( crop_height > image.height)
    {
        cout << "invalid input, height is larger than the original image's height" << endl;
        cout << "enter the height for the cropped image : " ;
        cin >> crop_height;
    }
    cout << "enter the starting point for width ( on x axis ) : ";
    cin >> crop_start_x;
    while ( crop_start_x + crop_width > image.width)
    {
        cout << "invalid input, the width is out of range" << endl;
        cout << "enter the starting point for width ( on x axis ) : ";
        cin >> crop_start_x;
    }
    cout << "enter the starting point for height ( on y axis ) : ";
    cin >> crop_start_y;
    while ( crop_start_y + crop_height > image.height)
    {
        cout << "invalid input, the height is out of range" << endl;
        cout << "enter the starting point for height ( on y axis ) : ";
        cin >> crop_start_y;
    }

    Image cropped_image(crop_width,crop_height);

    int x = 0;
    for (int i = crop_start_x; i < crop_width; ++i) {
        int y = 0;
        for (int j = crop_start_y; j < crop_height; ++j) {

            for (int k = 0; k < 3; ++k) {
                cropped_image(x,y,k) = image(i,j,k);
            }
            y++;
        }

        x++;
    }

    cropped_image.saveImage("cropped_image.jpg");
    cout << "Done." << endl;



}