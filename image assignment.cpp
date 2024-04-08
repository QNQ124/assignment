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

    cout << "Please enter the file name: " << endl;
    getline(cin,file_name);
    cout << "Please enter the NEW file name: " << endl;
    getline(cin,Newfile_name);


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

    int blur_level;
    cout << "Please enter the blur level (1, 2 , 3 ): ";
    cin >> blur_level;
    blur_level++;
    
    Image photo("building.jpg");

    // Calculate resized dimensions
    int resized_width = max(1, photo.width / blur_level);
    int resized_height = max(1, photo.height / blur_level);

    Image resized_photo(resized_width, resized_height);


    Image new_image(resized_width,resized_height);
    const float SCALING_CONST_W = (float)photo.width/(float)resized_width ;
    const float SCALING_CONST_H = (float)photo.height/(float)resized_height;

    for (int i = 0; i < resized_width; ++i)
    {
        for (int j = 0; j < resized_height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                int new_pixel_W = i * SCALING_CONST_W;
                int new_pixel_H = j * SCALING_CONST_H;
                new_image(i,j,k) = photo(new_pixel_W,new_pixel_H,k);
            }
        }
    }
    
    // Blur parameters
    int kernel_size = 5 + (blur_level + 1) * 2; // Increase kernel size for higher blur levels

    double sigma = 30 + (blur_level + 1) * 10;  // Increase sigma value for higher blur levels

    // Apply blur operation
    for (int i = 0; i < resized_width; i++)
    {
        for (int j = 0; j < resized_height; j++)
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
                    if (neighbor_x >= 0 && neighbor_x < resized_width && neighbor_y >= 0 && neighbor_y < resized_height)
                    {
                        double weight = exp(-(x * x + y * y) / (2 * sigma * sigma)) / (2 * M_PI * sigma * sigma);
                        // Get pixel value for each channel
                        for (int c = 0; c < 3; c++)
                        {
                            weighted_sum[c] += weight * new_image(neighbor_x, neighbor_y, c);
                        }
                        sum_of_weights += weight;
                    }
                }
            }
            // Assign the blurred pixel values back to the image
            for (int c = 0; c < 3; c++)
            {
                resized_photo(i, j, c) = weighted_sum[c] / sum_of_weights;
            }
        }
    }
    
    // Resize the image back to its original size
    Image new_image1(photo.width,photo.height);

    const float SCALING_CONST_W2 = (float)resized_width/(float)photo.width ;
    const float SCALING_CONST_H2 = (float)resized_height/(float)photo.height;

    for (int i = 0; i < photo.width; ++i) {
        for (int j = 0; j < photo.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int new_pixel_W = i * SCALING_CONST_W2;
                int new_pixel_H = j * SCALING_CONST_H2;
                new_image1(i,j,k) = resized_photo(new_pixel_W,new_pixel_H,k);
            }
        }
    }

    // Save the blurred image
    new_image1.saveImage("blur.jpg");
}

void rotate_image()
{
    string file_name , Newfile_name;
    string degree_rotation;

    cout << "Please enter the file name: " << endl;
    getline(cin,file_name);
    cout << "Please enter the NEW file name: " << endl;
    getline(cin,Newfile_name);

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


void frame_to_image()
{
    string file_name, Newfile_name;
    string color;

    cout << "Please enter the file name: " << endl;
    getline(cin,file_name);

    cout << "Please enter the NEW file name: " << endl;
    getline(cin,Newfile_name);

    cout << "Please enter the color of the frame (Black, White, Blue, Red, Green): " << endl;
    cin >> color;
    color= upper_case(color);

    while (color!="BLACK" && color!="RED" && color!="BLUE" && color!="GREEN" && color!="WHITE")
    {
        cout << "Please enter the color of the frame (Black, White, Blue, Red, Green): " << endl;
        cin >> color;
        color= upper_case(color);
    }

    string choice;
    cout<<"Do you want it fancy? (yes or no)"<<endl;
    cin>>choice;
    choice= upper_case(choice);

    while ( choice!="YES" && choice!="NO") {
        cout << "Do you want it fancy? (yes or no)" << endl;
        cin >> choice;
        choice = upper_case(choice);
    }

    // Load the image
    Image photo(file_name);

    if(choice=="NO")
    {
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
                if (i < frame_size || j < frame_size || i >= frame_width - frame_size || j >= frame_height - frame_size)
                {
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
    else {
        // Calculate frame size as a fraction of the smaller dimension of the image
        int frame_size = min(photo.width, photo.height) / 25; // Adjust divisor for desired thickness
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

        // Copy original image onto the frame
        for (int i = 0; i < photo.width; i++) {
            for (int j = 0; j < photo.height; j++) {
                for (int k = 0; k < 3; k++) {
                    framed_photo(i + frame_size, j + frame_size, k) = photo(i, j, k);
                }
            }
        }

        // Add horizontal stripes with space in between
        int space_between_stripes = 10; // Adjust as needed
        for (int i = frame_size; i < frame_width - frame_size; i++)
        {
            // make sure that the stripes be in the specified range
            // used to determine whether to add a gray stripe or a space.
            if (i % (2 * space_between_stripes) < space_between_stripes)
            {
                for (int j = 0; j < frame_size; j++)
                {
                    // made the gray is a fixed color for fancy frame
                    framed_photo(i, j, 0) = 128; // Red component   (top)
                    framed_photo(i, j, 1) = 128; // Green component (top)
                    framed_photo(i, j, 2) = 128; // Blue component  (top)
                    framed_photo(i, frame_height - frame_size + j, 0) = 128; // Red component   (bottom)
                    framed_photo(i, frame_height - frame_size + j, 1) = 128; // Green component (bottom)
                    framed_photo(i, frame_height - frame_size + j, 2) = 128; // Blue component  (bottom)
                }
            }
        }

        // Add vertical stripes with space in between
        for (int j = frame_size; j < frame_height - frame_size; j++)
        {
            // make sure that the stripes be in the specified range
            // used to determine whether to add a gray stripe or a space.
            if (j % (2 * space_between_stripes) < space_between_stripes)
            {
                for (int i = 0; i < frame_size; i++)
                {
                    // made the gray is a fixed color for fancy frame
                    framed_photo(i, j, 0) = 128; // Red component
                    framed_photo(i, j, 1) = 128; // Green component
                    framed_photo(i, j, 2) = 128; // Blue component
                    framed_photo(frame_width - frame_size + i, j, 0) = 128; // Red component (right)
                    framed_photo(frame_width - frame_size + i, j, 1) = 128; // Green component (right)
                    framed_photo(frame_width - frame_size + i, j, 2) = 128; // Blue component (right)
                }
            }
        }

        framed_photo.saveImage(Newfile_name);
    }

}

void infrared_image()
{
    string file_name, Newfile_name;
    string color;

    cout << "Please enter the file name: " << endl;
    getline(cin,file_name);

    cout << "Please enter the NEW file name: " << endl;
    getline(cin,Newfile_name);

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
    getline(cin,file_name);

    cout << "Please enter the NEW file name: " << endl;
    getline(cin,Newfile_name);

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


void Night_Vision()
{
    string file_name, Newfile_name;

    Image photo("gamma_adjusted_image.jpg");

    for(int i = 0; i < photo.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < photo.height; j++) // Using .height to get image height
        {
            photo(i,j,0) = 0;
            photo(i,j,2) = 0;
        }
    }

    double factor = 1.11 + (48 / 255.0);

    // brightness image after applying
    for (int i = 0; i < photo.width; i++) {
        for (int j = 0; j < photo.height; j++) {
            for (int k = 0; k < photo.channels; k++) {
                int new_value = photo(i, j, k) * factor;
                photo(i, j, k) = int(max(0, min(255, new_value))); // Check range of RGB and Modify it
            }
        }
}

photo.saveImage("night.jpg");

}

int main()
{
    Blur_image();
}
