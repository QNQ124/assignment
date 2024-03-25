#include "Image_Class.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

//void menu(){
//    cout << "|-------------- Ahlan ya User ya Habibi --------------|\n"
//         << "|    In this application we can enhance or modify     |\n"
//         << "|    the image via tools called filters. You can      |\n"
//         << "|    enter your photo, choose the filter you want,    |\n"
//         << "|    and then the photo is modified                   |\n"
//         << "|-----------------------------------------------------|\n\n";
//
//    while (true){
//        string filename1, filename2, choice1, choice2;
//
//        cout << "|------ What do you want to do ? -----|\n"
//             << "1) Grayscale image                    |\n"
//             << "2) Black & White image                |\n"
//             << "3) Invert image                       |\n"
//             << "4) Rotate image                       |\n"
//             << "5) Flip image                         |\n"
//             << "6) Exit                               |\n"
//             << "|-------------------------------------|\n\n"
//             << "Please choose from the menu [1, 2, 3, 4, 5, 6]: ";
//
//        getline(cin, choice1);
//
//        while (true) {
//            if (choice1 == "1" || choice1 == "2" || choice1 == "3" || choice1 == "4" || choice1 == "5" || choice1 == "6")
//                break;
//            else {
//                cout << "Please choose from the menu [1, 2, 3, 4, 5, 6]: ";
//                getline(cin, choice1);
//            }
//        }
//
//        cout << "|--- What do you want to do ? ---|\n"
//             << "1) Load new image                |\n"
//             << "2) Choose from your computer     |\n"
//             << "3) Save image                    |\n"
//             << "4) Clear                         |\n"
//             << "|--------------------------------|\n\n"
//             << "Please choose from the menu [1, 2, 3, 4]: ";
//
//        getline(cin, choice2);
//        while (true) {
//            if (choice2 == "1" || choice2 == "2" || choice2 == "3" || choice2 == "4")
//                break;
//            else {
//                cout << "Please choose from the menu [1, 2, 3, 4]: ";
//                getline(cin, choice2);
//            }
//        }
//
//
//    }
//}


int main() {

    cout << "HELLO, WORLD!" << endl;
    Image f("photographer.bmp");

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

    f.saveImage("gray_scale.jpg");
    Image o("gray_scale.jpg");

    for (int i = 1; i < o.width - 1; ++i) {
        for (int j = 1; j < o.height - 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                int laplacian = abs(o(i,j,k) - o(i + 1,j + 1, k)) + abs(o(i, j + 1, k) - o(i + 1, j, k));
                o(i, j, k) = (laplacian > 255) ? 255 : (laplacian < 0) ? 0 : laplacian;
            }
        }
    }
    // Invert the colors of the o image
    for (int i = 0; i < o.width; ++i) {
        for (int j = 0; j < o.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                o(i, j, k) = 255 - o(i, j, k);
            }
        }
    }

    o.saveImage("edge.jpg");
    cout << "HELLO, WORLD!" << endl;
    return 0;
}
