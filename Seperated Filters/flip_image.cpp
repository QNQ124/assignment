#include <bits/stdc++.h>
#include "Image_class.h"
using namespace std;

int main()
{

    cout << "HELLO, WORLD!" << endl;
    Image image("night3.jpg");

    while (true)
    {
        cout << "A) Flip horizontally " << endl;
        cout << "B) Flip vertically " << endl;
        cout << "enter your choice " << endl;
        char choice;
        cin >> choice;
        choice = (char) toupper(choice);
        while (choice != 'A' && choice != 'B')
        {
            cout << "invalid input" << endl;
            cout << "enter your choice (A/B)" << endl;
            cin >> choice;
            choice = (char) toupper(choice);
        }
        if ( choice == 'A')
        {
            for (int i = 0; i < image.width / 2; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    unsigned int pixel1;
                    unsigned int pixel2;
                    int width = image.width;
                    int height = image.height;
                    for (int k = 0; k < 3; ++k) {
                        pixel1 = image.getPixel(i,j,k);
                        pixel2 = image.getPixel(width - i -1,j,k);
                        image.setPixel(i,j,k,pixel2);
                        image.setPixel(width - i,j,k,pixel1);
                    }
                }
            }
            break;
        }
        else
        {
            for (int i = 0; i < image.width ; ++i) {
                for (int j = 0; j < image.height / 2; ++j) {
                    unsigned int pixel1;
                    unsigned int pixel2;
                    int width = image.width;
                    int height = image.height;
                    for (int k = 0; k < 3; ++k) {
                        pixel1 = image.getPixel(i,j,k);
                        pixel2 = image.getPixel(i, height - j - 1,k);
                        image.setPixel(i,j,k,pixel2);
                        image.setPixel(i,height - j - 1,k,pixel1);
                    }
                }
            }
            break;
        }

    }

    image.saveImage("flipped.jpg");
    cout << "Done." ;

}