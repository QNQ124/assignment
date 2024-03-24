#include <iostream>
#include <string>
#include <cmath>
#include "Image_Class.h"
#include <vector>
#include <omp.h>
using namespace std;

void Inverted_Image()
{
    string file_name , Newfile_name;
    cout<<"Please enter the file name: "<<endl;
    cin>>file_name;
    cout<<"Please enter the NEW file name: "<<endl;
    cin>>Newfile_name;


    Image photo(file_name); // Assuming Image class constructor takes a filename

    for(int i = 0; i < photo.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < photo.height; j++) // Using .height to get image height
        {
            for (int k = 0; k < 3; k++) // Assuming 3 color channels (RGB)
            {
                unsigned int pixel_color = photo.getPixel(i, j, k); // Assuming getPixel method exists
                unsigned int pixel_inverted_color = 255 - pixel_color; // Inverting color
                photo.setPixel(i, j, k, pixel_inverted_color); // Assuming setPixel method exists
            }
        }
    }
    photo.saveImage(Newfile_name); // Assuming saveImage method exists
}

void Blur_image()
{
    string file_name, Newfile_name;

    cout << "Please enter the file name: " << endl;
    cin >> file_name;
    cout << "Please enter the NEW file name: " << endl;
    cin >> Newfile_name;

    Image photo(file_name);
    int width = photo.width;
    int height = photo.height;
    int num_passes = 5; // Number of passes for blurring
    double sigma = 30;  // Increased sigma value for more blurring
    int kernel_size = 5; // Increased kernel size
    vector<vector<double>> kernel_values(kernel_size, vector<double>(kernel_size, 0.0));

    // Precompute Gaussian kernel values
    for (int x = -kernel_size / 2; x <= kernel_size / 2; x++)
    {
        for (int y = -kernel_size / 2; y <= kernel_size / 2; y++)
        {
            kernel_values[x + kernel_size / 2][y + kernel_size / 2] = exp(-(x * x + y * y) / (2 * sigma * sigma)) / (2 * M_PI * sigma * sigma);
        }
    }

    // Blur image
    for (int pass = 0; pass < num_passes; pass++)
    {
#pragma omp parallel for collapse(2)
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                double weighted_sum[3] = {0.0}; // Initialize array for each channel
                double sum_of_weights = 0.0;

                // Iterate over each pixel in the neighborhood according to the kernel size
                for (int x = -kernel_size / 2; x <= kernel_size / 2; x++)
                {
                    for (int y = -kernel_size / 2; y <= kernel_size / 2; y++)
                    {
                        int neighbor_x = i + x;
                        int neighbor_y = j + y;

                        // Check boundary conditions
                        if (neighbor_x >= 0 && neighbor_x < width && neighbor_y >= 0 && neighbor_y < height)
                        {
                            double weight = kernel_values[x + kernel_size / 2][y + kernel_size / 2];
                            // Get pixel value for each channel
                            for (int c = 0; c < 3; c++)
                            {
                                weighted_sum[c] += weight * photo.getPixel(neighbor_x, neighbor_y, c);
                            }
                            sum_of_weights += weight;
                        }
                    }
                }
                // Assign the blurred pixel values back to the image
                for (int c = 0; c < 3; c++) {
                    photo.setPixel(i, j, c, weighted_sum[c] / sum_of_weights);
                }
            }
        }
    }

    // Save the blurred image
    photo.saveImage(Newfile_name);
}

void rotate_image()
{
    string file_name , Newfile_name;
    string degree_rotation;
    cout<<"Please enter the file name: "<<endl;
    cin>>file_name;
    cout<<"Please enter the NEW file name: "<<endl;
    cin>>Newfile_name;
    cout<<"Please enter the degree_rotation(90 or 270 or 180): "<<endl;
    cin>>degree_rotation;

    Image photo(file_name);

    while(degree_rotation != "90" && degree_rotation != "180" && degree_rotation != "270")

    {
        cout<<"invaild input,Please enter the degree_rotation(90 or 270 or 180): "<<endl;
        cin>>degree_rotation;
    }

    if(degree_rotation=="180")
    {
        Image new_photo_180(photo.width,photo.height);
        for(int i = 0; i < photo.width; i++) // Using .width  to get image width
        {
            for (int j = 0; j < photo.height; j++) // Using .height to get image height
            {
                for (int k = 0; k < 3; k++) // Assuming 3 color channels (RGB)
                {
                    new_photo_180(photo.width-i-1,photo.height-j-1,k)=photo(i,j,k);
                }
            }
        }
        new_photo_180.saveImage(Newfile_name);
    }
    else if (degree_rotation=="270")
    {
        Image new_photo_270(photo.height,photo.width);

        for (int i = 0; i < photo.width; i++)
        {
            for (int j = 0; j < photo.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    new_photo_270(j, photo.width - i - 1, k) = photo(i, j, k);
                }
            }
        }

        new_photo_270.saveImage(Newfile_name);
    }
    else
    {
        Image new_photo_90(photo.height,photo.width);

        for (int i = 0; i < photo.width; i++)
        {
            for (int j = 0; j < photo.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    new_photo_90(photo.height - j - 1, i, k) = photo(i, j, k);
                }
            }
        }

        new_photo_90.saveImage(Newfile_name);
    }
}

string upper_case(string m) // function that converts string to uperr case
{
    for(char& c : m)
    {
        c = toupper(c); // Convert each character to uppercase
    }
    return m;
}

//void addRoyalFrameCorners(Image& framed_photo, int frame_size) {
//    // Define the size of corner decorations
//    int corner_size = 40; // Adjust size as needed
//
//    // Iterate over each corner to draw the royal frame decoration
//    for (int i = 0; i < corner_size; ++i) {
//        for (int j = 0; j < corner_size; ++j) {
//            // Top-left corner
//            if (i < frame_size && j < frame_size) {
//                framed_photo(j, i, 0) = 0; // Red
//                framed_photo(j, i, 1) = 0; // Green
//                framed_photo(j, i, 2) = 0; // Blue
//            }
//
//            // Top-right corner
//            if (i < frame_size && j < frame_size) {
//                framed_photo(framed_photo.width - frame_size + j, i, 0) = 0; // Red
//                framed_photo(framed_photo.width - frame_size + j, i, 1) = 0; // Green
//                framed_photo(framed_photo.width - frame_size + j, i, 2) = 0; // Blue
//            }
//
//            // Bottom-left corner
//            if (i < frame_size && j < frame_size) {
//                framed_photo(j, framed_photo.height - frame_size + i, 0) = 0; // Red
//                framed_photo(j, framed_photo.height - frame_size + i, 1) = 0; // Green
//                framed_photo(j, framed_photo.height - frame_size + i, 2) = 0; // Blue
//            }
//
//            // Bottom-right corner
//            if (i < frame_size && j < frame_size) {
//                framed_photo(framed_photo.width - frame_size + j, framed_photo.height - frame_size + i, 0) = 0; // Red
//                framed_photo(framed_photo.width - frame_size + j, framed_photo.height - frame_size + i, 1) = 0; // Green
//                framed_photo(framed_photo.width - frame_size + j, framed_photo.height - frame_size + i, 2) = 0; // Blue
//            }
//        }
//    }
//
//    // Add more intricate designs to the corners (e.g., diagonal lines)
//    for (int i = 0; i < corner_size; ++i) {
//        // Top-left corner
//        if (i < frame_size) {
//            framed_photo(frame_size + i, frame_size - i, 0) = 0; // Red
//            framed_photo(frame_size + i, frame_size - i, 1) = 0; // Green
//            framed_photo(frame_size + i, frame_size - i, 2) = 0; // Blue
//        }
//
//        // Top-right corner
//        if (i < frame_size) {
//            framed_photo(framed_photo.width - frame_size + i, frame_size - i, 0) = 0; // Red
//            framed_photo(framed_photo.width - frame_size + i, frame_size - i, 1) = 0; // Green
//            framed_photo(framed_photo.width - frame_size + i, frame_size - i, 2) = 0; // Blue
//        }
//
//        // Bottom-left corner
//        if (i < frame_size) {
//            framed_photo(frame_size + i, framed_photo.height - frame_size + i, 0) = 0; // Red
//            framed_photo(frame_size + i, framed_photo.height - frame_size + i, 1) = 0; // Green
//            framed_photo(frame_size + i, framed_photo.height - frame_size + i, 2) = 0; // Blue
//        }
//
//        // Bottom-right corner
//        if (i < frame_size) {
//            framed_photo(framed_photo.width - frame_size + i, framed_photo.height - frame_size + i, 0) = 0; // Red
//            framed_photo(framed_photo.width - frame_size + i, framed_photo.height - frame_size + i, 1) = 0; // Green
//            framed_photo(framed_photo.width - frame_size + i, framed_photo.height - frame_size + i, 2) = 0; // Blue
//        }
//    }
//}

void frame_to_image()
{
    string file_name, Newfile_name;
    string color;

    cout << "Please enter the file name: " << endl;
    cin >> file_name;

    cout << "Please enter the NEW file name: " << endl;
    cin >> Newfile_name;

    cout << "Please enter the color of the frame (Black, White, Blue, Red, Green): " << endl;
    cin >> color;
    color= upper_case(color);

    while (color!="BLACK" && color!="RED" && color!="BLUE" && color!="GREEN" && color!="WHITE")
    {
        cout << "Please enter the color of the frame (Black, White, Blue, Red, Green): " << endl;
        cin >> color;
        color= upper_case(color);
    }

    // Load the image
    Image photo(file_name);

    // Calculate frame size as a fraction of the smaller dimension of the image
    int frame_size = min(photo.width, photo.height) / 20; // Adjust divisor (e.g., 20) for desired thickness

    // Calculate frame dimensions
    int frame_width = photo.width + 2 * frame_size;
    int frame_height = photo.height + 2 * frame_size;

    // Create framed photo with calculated frame dimensions
    Image framed_photo(frame_width, frame_height);

    // Set the frame color
    for (int i = 0; i < framed_photo.width; i++) {
        for (int j = 0; j < framed_photo.height; j++) {
            if (i < frame_size || j < frame_size || i >= frame_width - frame_size || j >= frame_height - frame_size) {
                if (color == "BLACK") {
                    framed_photo(i, j, 0) = 0;
                    framed_photo(i, j, 1) = 0;
                    framed_photo(i, j, 2) = 0;
                } else if (color == "RED") {
                    framed_photo(i, j, 0) = 255;
                    framed_photo(i, j, 1) = 0;
                    framed_photo(i, j, 2) = 0;
                } else if (color == "GREEN") {
                    framed_photo(i, j, 0) = 0;
                    framed_photo(i, j, 1) = 255;
                    framed_photo(i, j, 2) = 0;
                } else if (color == "BLUE") {
                    framed_photo(i, j, 0) = 0;
                    framed_photo(i, j, 1) = 0;
                    framed_photo(i, j, 2) = 255;
                } else if (color == "WHITE") {
                    framed_photo(i, j, 0) = 255;
                    framed_photo(i, j, 1) = 255;
                    framed_photo(i, j, 2) = 255;
                }
            }
        }
    }
    string choice;
    cout<<"Do you want it fancy? (yes or no)"<<endl;
    cin>>choice;
    choice= upper_case(choice);
//    if(choice=="YES")
//    {
//        addRoyalFrameCorners(framed_photo,frame_size);
//    }
    // Copy original image onto the frame
    for (int i = 0; i < photo.width; i++) {
        for (int j = 0; j < photo.height; j++) {
            for (int k = 0; k < 3; k++) {
                framed_photo(i + frame_size, j + frame_size, k) = photo(i, j, k);
            }
        }
    }

    // Save the framed photo
    framed_photo.saveImage(Newfile_name);
}

void infrared_image()
{
    string file_name, Newfile_name;
    string color;

    cout << "Please enter the file name: " << endl;
    cin >> file_name;

    cout << "Please enter the NEW file name: " << endl;
    cin >> Newfile_name;

    Image photo(file_name);

    for(int i = 0; i < photo.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < photo.height; j++) // Using .height to get image height
        {
            photo(i,j,0)=0;
        }
    }
    for(int i = 0; i < photo.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < photo.height; j++) // Using .height to get image height
        {
            for (int k = 0; k < 3; k++) // Assuming 3 color channels (RGB)
            {
                unsigned int pixel_color = photo.getPixel(i, j, k); // Assuming getPixel method exists
                unsigned int pixel_inverted_color = 255 - pixel_color; // Inverting color
                photo.setPixel(i, j, k, pixel_inverted_color); // Assuming setPixel method exists
            }
        }
    }

    photo.saveImage(Newfile_name);

}
void purple_filter()
{
    string file_name, Newfile_name;
    string color;

    cout << "Please enter the file name: " << endl;
    cin >> file_name;

    cout << "Please enter the NEW file name: " << endl;
    cin >> Newfile_name;

    Image photo(file_name);

    for (int i = 0; i < photo.width; i++)
    {

        for (int j = 0; j < photo.height; j++)
        {

            int red = photo.getPixel(i, j, 0);  // Get red channel value
            int green = photo.getPixel(i, j, 1); // Get green channel value
            int blue = photo.getPixel(i, j, 2);  // Get blue channel value

            // Increase red and blue, decrease green to create a purple tint

            red += 60; // increase average value wich is (10+120)/2 = 60

            green -= 30;

            blue += 60;// increase average value wich is (10+120)/2 = 60

            // Ensure that values are within the valid range [0, 255]
            red = min(255, max(0, red));
            green = min(255, max(0, green));
            blue = min(255, max(0, blue));

            photo.setPixel(i, j, 0, red); // Red channel
            photo.setPixel(i, j, 1, green); // Green channel
            photo.setPixel(i, j, 2, blue); // Blue channel
        }
    }
    photo.saveImage(Newfile_name);
}

int main()
{
    purple_filter();

}