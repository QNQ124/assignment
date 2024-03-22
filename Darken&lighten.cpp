#include "Image_Class.h"
#include <iostream>

using namespace std;

int main() {
    int brightness = 0;
    string choice, filename;
    cout << "Please enter filename: ";
    getline(cin, filename);

    // Load an image
    Image image(filename);
    cout << "1) Darken\n"
         << "2) Lighten\n"
         << "Choose from the menu [1, 2]: ";
    getline(cin, choice);

    while (true) {
        if (choice == "1" || choice == "2") {
            break;
        } else {
            cout << "Choose from the menu [1, 2]: ";
            getline(cin, choice);
        }
    }

    cout << "Please enter brightness value: ";
    cin >> brightness;

    // Adjust the brightness based on the user's choice
    if (choice == "1") {
        brightness = -1 * brightness;
    } else {
        // Lighten the image
        brightness = min(255, brightness);
    }

    // Adjust the brightness
    double factor = 1.0 + (brightness / 255.0);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int new_value = image(i, j, k) * factor;
                image(i, j, k) = int(max(0, min(255, new_value)));
            }
        }
    }
    // Save the modified image
    image.saveImage("brightened_image.jpg");
}