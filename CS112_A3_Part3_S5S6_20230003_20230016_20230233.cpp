// ==================================================================================== //
// FCAI – Structured Programming – 2024 - Assignment                                    //
//                                                                                      //
// File:    CS112_A3_Part3_S5S6_20230003_20230016_20230233.cpp                          //
//                                                                                      //
// Purpose: This program allows users to Applying filters to images It                  //
//          provides a user-friendly menu for selecting filters and                     //
//          saving the modified images.                                                 //
//                                                                                      //
// Author:  Ibrahim Mohamed Saad Mohamed_S6_20230003 => Filter 1, 4, 7, 10, 13, 15      //
//          Ahmed Hussein Mohamed Ahmed_S5_20230016  => Filter 2, 5, 8, 11, 14, 18      //
//          Ezz eldin Omar Abd El-latif_S6_20230233  => Filter 3, 6, 9, 12, 16, 17      //
//                                                                                      //
// Emails:  hes93314@gmail.com                                                          //
//          hzrdu3500@gmail.com                                                         //
//          ezzeldinomar7@gmail.com                                                     //
//                                                                                      //
// TA name: Rana Abdelkader                                                             //
// Date:    4/7/2024                                                                    //
// Version: 1.0                                                                         //
// ==================================================================================== //

// Include necessary libraries
#include <iostream>
#include <cmath>
#include <vector>
#include "Image_Class.h"  // Header to work with images
#include <fstream>        // Input/output stream class to operate on files.
#include <windows.h>      // For Windows-specific functions like SetCurrentDirectory
#include <filesystem>     // For filesystem operations
#include <stdio.h>        // using for delete temporary_file if user chosen Applying a Filter
#define sv saveImage      // Define a shorthand for saveImage method
#define uint unsigned int // Define uint as an alias for unsigned int
#define gp getPixel       // Define a shorthand for getPixel method

using namespace std;
namespace fs = filesystem; // Use the filesystem namespace for filesystem operations

// Function to check if a file exists and can be opened
bool isValid(string filename){
    ifstream file;
    file.open(filename);
    if(file)
        return true;  // File exists and can be opened
    else
        return false; // File does not exist or cannot be opened
}

// convert each character to uppercase in file name to exit choice
string to_upper(string input){
    for (auto &i : input) {
        if(isalpha(i) && islower(i)) i = toupper(i);
        else continue;

    }
    return input;
}

// Validate Crop function inputs
int getIntegerInput_Crop_Filter() {
    int input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n---- Invalid input ----\n"
             << "Please enter a number: ";
    }
    return input;
}

// Function to handle saving options
void saving_options()
{
    string path_choice;
    cout << "|-- Choose one of them to save --|\n"
         << "1) Save in the same path         |\n"
         << "2) Save in a new path            |\n"
         << "|--------------------------------|\n"
         << "Please enter your choice: ";

    getline(cin, path_choice);
    cout << endl;
    while ( path_choice != "1" && path_choice != "2")
    {
        cout << "------- invalid input -------\n"
             << "please your choice in (1,2): ";
        getline(cin, path_choice);
        cout << endl;
    }

    if ( path_choice == "2")
    {
        string new_filepath;
        cout << "Please enter the new directory path: ";
        getline(cin, new_filepath);
        cout << endl;
        while (!SetCurrentDirectory(new_filepath.c_str()))
        {
            cout << "------ Directory doesn't exist ------\n";
            cout << "Please enter the new Directory path: ";
            getline(cin, new_filepath);
            cout << endl;
        }
    }
}

// Function to display the main menu and get user's choice
int Display_Menu2(){

    string choice;

    cout << "\n|--- What do you want to do ? ---|\n"
         << "1) Load a new image              |\n"
         << "2) Applying a Filter             |\n"
         << "3) Save in a new image           |\n"
         << "4) Exit                          |\n"
         << "|--------------------------------|\n"
         << "Please choose from the menu [1, 2, 3, 4]: ";

    getline(cin, choice);

    while (true) {
        if (choice == "1" || choice == "2" || choice == "3" || choice == "4")
            break;
        else {
            cout << "Please choose from the menu [1, 2, 3, 4]: ";
            getline(cin, choice);
        }
    }

    if (choice == "4") {
        cout << "\n---------------------------------\n"
             << " Thank you for using our Program\n"
             << "---------------------------------\n";
    }
    return stoi(choice);
}

// Function to convert an image to grayscale
int GrayScale_Filter(string filename) {
    // Load the image
    Image image(filename);

    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            uint average = 0;

            // Calculate the average of RGB values
            for (int k = 0; k < 3; ++k) {
                average += image(i, j, k);
            }
            average /= 3;

            // Set each RGB value to the average
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = average;
            }
        }
    }

    // Display the menu and return the user's choice
    int choice = Display_Menu2();
    if (choice == 1) {
        cout << endl;
        return 0;
    }
    else if (choice == 2) {
        image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if (choice == 3) {
        // Save the image with a new filename
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        saving_options();
        int size = new_filename.size();
        // Ensure the filename has a valid extension
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if (!isValid(new_filename)) {
                image.sv(new_filename); // Save the image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }

        // Restore the current directory
        SetCurrentDirectory(old_dir.c_str());
    }
    return choice;
}

// Function to convert an image to black and white
int BlackAndWhite_Filter(string filename)
{
    // Load the image
    Image image(filename);

    // Convert each pixel to black or white based on its intensity
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            uint average = 0;

            // Calculate the average of RGB values
            for (int k = 0; k < 3; ++k) {
                average += image(i, j, k);
            }
            average /= 3;

            // Set the pixel to black or white based on the average
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (average >= 127) ? 255 : 0;
            }
        }
    }

    // Display the menu and return the user's choice
    int choice = Display_Menu2();
    if (choice == 1) {
        cout << endl;
        return 0;
    }
    else if (choice == 2) {
        image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if (choice == 3) {
        // Save the image with a new filename
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        saving_options();
        int size = new_filename.size();
        // Ensure the filename has a valid extension
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if (!isValid(new_filename)) {
                image.sv(new_filename); // Save the image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }

        // Restore the current directory
        SetCurrentDirectory(old_dir.c_str());
    }
    return choice;
}

// invert image function
int Invert_Filter(string filename)
{
    // Load the image
    Image image(filename);

    // Iterate over each pixel in the image
    for(int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            // Iterate over each color channel (RGB)
            for (int k = 0; k < 3; k++)
            {
                // Get the current pixel color
                uint pixel_color = image.gp(i, j, k);
                // Invert the pixel color
                uint pixel_inverted_color = 255 - pixel_color;
                // Set the inverted color to the pixel
                image.setPixel(i, j, k, pixel_inverted_color);
            }
        }
    }

    // Display the menu and return the user's choice
    int choice = Display_Menu2();
    if(choice == 1) {
        cout << endl;
        return 0;
    }
    else if(choice == 2){
        image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        // Save the image with a new filename
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        saving_options();
        int size = new_filename.size();
        // Ensure the filename has a valid extension
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) {
                image.sv(new_filename); // Save the inverted image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        // Restore the current directory
        SetCurrentDirectory(old_dir.c_str());
    }
    return choice;
}

// Merge 2 images function_2
int Merge_2_Images(string filename1){

    // Initial variables and load the first image
    string choice1, filename2;
    Image image1(filename1);

    cout << "\nPlease enter the second file path: ";
    getline(cin, filename2); // Get the second image file path from the user

    // Validate the file path
    while (true) {
        if (isValid(filename2)) {
            break; // Exit the loop if the file exists
        } else {
            cout << "\n------- File doesn't exist --------\n";
            cout << "Please enter the second file path: ";
            getline(cin, filename2);
        }
    }

    Image image2(filename2); // Load the second image
    int smaller_width = 0, smaller_height = 0, bigger_width = 0, bigger_height = 0;

    cout << "\n|-- What you want to do? --|\n";
    cout << "1) Resize both images      |\n";
    cout << "2) Merge the common area   |\n";
    cout << "|--------------------------|\n";
    cout << "Choose from the menu [1, 2]: ";
    getline(cin, choice1); // Get the user's choice from the menu

    // Validate the user's choice
    while (true) {
        if (choice1 == "1" || choice1 == "2")
            break;
        else {
            cout << "Choose from the menu [1, 2]: ";
            getline(cin, choice1);
        }
    }

    // Determine the dimensions of the smaller and bigger images
    if (min(image1.width, image2.width) == image1.width) {
        smaller_width = image1.width;
        smaller_height = image1.height;
        bigger_width = image2.width;
        bigger_height = image2.height;
    } else {
        smaller_width = image2.width;
        smaller_height = image2.height;
        bigger_width = image1.width;
        bigger_height = image1.height;
    }

    if(choice1 == "1") {
        if(min(image1.width, image2.width) == image1.width) {
            // Resize smaller image to the bigger image dimensions and merge them
            Image new_image(bigger_width, bigger_height);
            const float SCALING_CONST_W = (float) smaller_width / (float) bigger_width;
            const float SCALING_CONST_H = (float) smaller_height / (float) bigger_height;

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        int new_pixel_W = i * SCALING_CONST_W;
                        int new_pixel_H = j * SCALING_CONST_H;
                        new_image(i, j, k) = image1(new_pixel_W, new_pixel_H, k);
                    }
                }
            }

            Image f3(bigger_width, bigger_height);

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (image2(i, j, k) + new_image(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("temporary_file.jpg");
        }
        else{
            // Resize smaller image to the bigger image dimensions and merge them
            Image new_image(bigger_width, bigger_height);
            const float SCALING_CONST_W = (float) smaller_width / (float) bigger_width;
            const float SCALING_CONST_H = (float) smaller_height / (float) bigger_height;

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        int new_pixel_W = i * SCALING_CONST_W;
                        int new_pixel_H = j * SCALING_CONST_H;
                        new_image(i, j, k) = image2(new_pixel_W, new_pixel_H, k);
                    }
                }
            }

            Image f3(bigger_width, bigger_height);

            for (int i = 0; i < bigger_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (image1(i, j, k) + new_image(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("temporary_file.jpg");
        }
    }
    else{
        // Merge the common area of the two images
        if((max(image1.width, image2.width) == image2.width && max(image1.height, image2.height) == image1.height) || (max(image1.width, image2.width) == image1.width && max(image1.height, image2.height) == image2.height)) {
            Image f3(smaller_width, bigger_height);
            for (int i = 0; i < smaller_width; ++i) {
                for (int j = 0; j < bigger_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (image1(i, j, k) + image2(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("temporary_file.jpg");
        }
        else{
            Image f3(smaller_width, smaller_height);
            for (int i = 0; i < smaller_width; ++i) {
                for (int j = 0; j < smaller_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        f3(i, j, k) = (image1(i, j, k) + image2(i, j, k)) / 2;
                    }
                }
            }
            f3.saveImage("temporary_file.jpg");
        }
    }
    Image image("temporary_file.jpg");

    int choice = Display_Menu2(); // Display a menu for further actions
    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        image.sv("temporary_file.jpg"); // Save the current image
    }
    else if(choice == 3){
        // Save the image with a new filename
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from the user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                image.sv(new_filename); // Save the image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// Flip image function
int Flip_Image(string filename)
{
    Image image(filename); // Load the image

    while (true)
    {
        // Display the menu for flipping options
        cout << "\n|-----------------------|\n"
             << "1) Flip horizontally    |\n"
             << "2) Flip vertically      |\n"
             << "|-----------------------|\n"
             << "Please enter your choice: ";
        string choice;
        getline(cin, choice); // Get the user's choice

        // Validate the user's choice
        while (choice != "1" && choice != "2")
        {
            cout << "\n--------- invalid input --------\n";
            cout << "Please enter your choice (1 or 2): ";
            getline(cin, choice);
        }

        // Perform the selected flip operation
        if (choice == "1") // Flip horizontally
        {
            for (int i = 0; i < image.width / 2; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    uint pixel1;
                    uint pixel2;
                    int width = image.width;
                    for (int k = 0; k < 3; ++k) {
                        // Swap pixels horizontally
                        pixel1 = image.gp(i,j,k);
                        pixel2 = image.gp(width - i -1,j,k);
                        image.setPixel(i,j,k,pixel2);
                        image.setPixel(width - i - 1,j,k,pixel1);
                    }
                }
            }
            break; // Exit the loop
        }
        else // Flip vertically
        {
            for (int i = 0; i < image.width ; ++i) {
                for (int j = 0; j < image.height / 2; ++j) {
                    uint pixel1;
                    uint pixel2;
                    int height = image.height;
                    for (int k = 0; k < 3; ++k) {
                        // Swap pixels vertically
                        pixel1 = image.gp(i,j,k);
                        pixel2 = image.gp(i, height - j - 1,k);
                        image.setPixel(i,j,k,pixel2);
                        image.setPixel(i,height - j - 1,k,pixel1);
                    }
                }
            }
            break; // Exit the loop
        }

    }

    int choice = Display_Menu2(); // Display a menu for further actions
    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                image.sv(new_filename); // Save the flipped image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// Rotate image function
int Rotate_Image(string filename)
{
    // take a degree_rotation from user
    string degree_rotation;
    cout << "\nPlease enter the degree_rotation (90 or 270 or 180): ";
    cin >> degree_rotation;

    // load the image
    Image image(filename);

    // Validate user input for degree_rotation
    while(degree_rotation != "90" && degree_rotation != "180" && degree_rotation != "270")
    {
        cout << "\n------------------- Invalid input -------------------\n";
        cout << "Please enter the degree_rotation (90 or 270 or 180): ";
        cin >> degree_rotation;
    }

    // Create new Image objects for different rotations
    Image new_photo_180(image.width,image.height);
    Image new_photo_270(image.height,image.width);
    Image new_photo_90(image.height,image.width);

    // Perform the rotation based on user input
    if(degree_rotation == "180")
    {
        for(int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++) // Assuming 3 color channels (RGB)
                {
                    new_photo_180(image.width-i-1,image.height-j-1,k)=image(i,j,k); // Rotate 180 degrees
                }
            }
        }
    }
    else if (degree_rotation == "270")
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    new_photo_270(j, image.width - i - 1, k) = image(i, j, k); // Rotate 270 degrees
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    new_photo_90(image.height - j - 1, i, k) = image(i, j, k); // Rotate 90 degrees
                }
            }
        }
    }

    cin.ignore(); // Clear input buffer
    int choice = Display_Menu2(); // Display a menu for further actions
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        if(degree_rotation == "180")
            new_photo_180.sv("temporary_file.jpg"); // save the current Filter in temporary file
        else if(degree_rotation == "270")
            new_photo_270.sv("temporary_file.jpg"); // save the current Filter in temporary file
        else
            new_photo_90.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                if(degree_rotation == "180")
                    new_photo_180.sv(new_filename); // Save the rotated image with the new filename
                else if(degree_rotation == "270")
                    new_photo_270.sv(new_filename);
                else
                    new_photo_90.sv(new_filename);

                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }
    return choice; // Return the user's choice from the menu
}

// Darken and Lighten function
int DarkenAndLighten_image(string filename){

    // Initial variables
    double factor = 0;
    string choice1, brightness;

    // Load an image
    Image image(filename);

    cout << "\n|- What you want to do? -|\n";
    cout << "1) Darken Filter         |\n";
    cout << "2) Lighten Filter        |\n";
    cout << "|------------------------|\n";
    cout << "Choose from the menu [1, 2]: ";
    getline(cin, choice1); // Get the user's choice from the menu

    // Validate the user's choice
    while (true) {
        if (choice1 == "1" || choice1 == "2")
            break;
        else {
            cout << "Choose from the menu [1, 2]: ";
            getline(cin, choice1);
        }
    }

    cout << "\nPlease enter brightness value: ";
    getline(cin, brightness); // Get the brightness value from the user

    // Validate the brightness value
    while(true){

        for (int i = 0; i < brightness.size(); ++i) {
            if(!isdigit(brightness[i])){
                cout << "\n-------- Invalid input --------\n";
                cout << "Please enter brightness value: ";
                getline(cin, brightness);
                i = 0;
            }
        }
        if(stoi(brightness) > 255 || stoi(brightness) < 0){
            cout << "\n- Enter number from 0 to 255 -\n";
            cout << "Please enter brightness value: ";
            getline(cin, brightness);
        }
        else
            break;
    }

    int num_brightness = stoi(brightness);

    // Adjust the brightness based on the user's choice
    if (choice1 == "1") {
        num_brightness = -1 * num_brightness;
        factor = 1.11 + (num_brightness / 255.0);
    } else {
        // Lighten the image
        num_brightness = min(255, num_brightness);
        factor = 1.45 + (num_brightness / 255.0);
    }

    // Apply the brightness adjustment to the image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int new_value = image(i, j, k) * factor;
                image(i, j, k) = int(max(0, min(255, new_value)));
            }
        }
    }

    int choice = Display_Menu2(); // Display a menu for further actions
    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        // Save the image with a new filename
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from the user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                image.sv(new_filename); // Save the image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// Crop image function
int Crop_Image(string filename) {

    // Load the original image
    Image image(filename);

    // Variables to store the crop dimensions and starting points
    int crop_width;
    int crop_height;
    int crop_start_x;
    int crop_start_y;

    // Get the crop width from the user
    cout << "\nEnter the width for the cropped image: ";
    crop_width = getIntegerInput_Crop_Filter();

    // Validate the crop width
    while (crop_width > image.width)
    {
        cout << "\n------------ invalid input ------------\n"
             << "larger than the original image's width\n"
             << "Enter the width for the cropped image: ";
        crop_width = getIntegerInput_Crop_Filter();
    }

    // Get the crop height from the user
    cout << "\nEnter the height for the cropped image: ";
    crop_height = getIntegerInput_Crop_Filter();

    // Validate the crop height
    while (crop_height > image.height)
    {
        cout << "\n------------ invalid input ------------\n"
             << "larger than the original image's height\n"
             << "Enter the height for the cropped image: ";
        crop_height = getIntegerInput_Crop_Filter();
    }

    // Get the starting point for the crop width (on the x axis) from the user
    cout << "\nEnter the starting point for width (on x axis): ";
    crop_start_x = getIntegerInput_Crop_Filter();

    // Validate the starting point for the crop width
    while (crop_start_x + crop_width > image.width)
    {
        cout << "\n---------------- invalid input ----------------\n"
                "the width of the starting point is out of range\n"
             << "Enter the starting point for width (on x axis): ";
        crop_start_x = getIntegerInput_Crop_Filter();
    }

    // Get the starting point for the crop height (on the y axis) from the user
    cout << "\nEnter the starting point for height (on y axis): ";
    crop_start_y = getIntegerInput_Crop_Filter();

    // Validate the starting point for the crop height
    while (crop_start_y + crop_height > image.height)
    {
        cout << "\n---------------- invalid input ----------------\n"
                "the height of the starting point is out of range\n"
             << "Enter the starting point for height (on y axis): ";
        crop_start_y = getIntegerInput_Crop_Filter();
    }

    // Ignore any remaining input in the buffer
    cin.ignore();

    // Create a new image to store the cropped portion
    Image cropped_image(crop_width, crop_height);

    // Copy the pixels from the original image to the cropped image
    int x = 0;
    for (int i = crop_start_x; i < crop_width; ++i) {
        int y = 0;
        for (int j = crop_start_y; j < crop_height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                cropped_image(x, y, k) = image(i, j, k);
            }
            y++;
        }
        x++;
    }

    // Display a menu for further actions
    int choice = Display_Menu2();

    // Handle user's choice
    if (choice == 1) {
        cout << endl;
        return 0; // Exit the function
    } else if (choice == 2) {
        cropped_image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    } else if (choice == 3) {
        // Save the cropped image with a new filename
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            } else if (!isValid(new_filename)) { // Check if the new filename is valid
                cropped_image.sv(new_filename); // Save the cropped image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            } else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// Frame to image function
int Frame_to_Image(string filename){

    string color;

    // Get the frame color from the user
    cout << "\n|--- What color do you want? ---|\n"
         << "1) Black                        |\n"
         << "2) Red                          |\n"
         << "3) Green                        |\n"
         << "4) Blue                         |\n"
         << "5) White                        |\n"
         << "|-------------------------------|\n"
         << "Please choose from the menu [1, 2, 3, 4, 5]: ";
    getline(cin, color);

    // Validate the color choice
    while (color != "1" && color != "2" && color != "3" && color != "4" && color != "5")
    {
        cout << "\n--------------- Invalid input ---------------\n";
        cout << "Please choose from the menu [1, 2, 3, 4, 5]: ";
        getline(cin, color);
    }

    string choice1;
    // Ask the user for the type of frame
    cout << "\n|- What you want to do? -|\n"
         << "1) Simple Frame          |\n"
         << "2) Fancy Frame           |\n"
         << "|------------------------|\n"
         << "Choose from the menu [1, 2]: ";

    getline(cin, choice1);

    // Validate the frame choice
    while ( choice1 != "1" && choice1 != "2")
    {
        cout << "\n------- Invalid input -------\n";
        cout << "Choose from the menu [1, 2]: ";
        getline(cin, choice1);
    }

    // Load the image
    Image photo(filename);

    if(choice1 == "1")
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
                    // Set the color based on user's choice
                    if (color == "1") {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == "2") {
                        framed_photo(i, j, 0) = 255;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == "3") {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 255;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == "4") {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 255;
                    } else if (color == "5") {
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
        framed_photo.saveImage("temporary_file.jpg");
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
                    // Set the color based on user's choice
                    if (color == "1") {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == "2") {
                        framed_photo(i, j, 0) = 255;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == "3") {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 255;
                        framed_photo(i, j, 2) = 0;
                    } else if (color == "4") {
                        framed_photo(i, j, 0) = 0;
                        framed_photo(i, j, 1) = 0;
                        framed_photo(i, j, 2) = 255;
                    } else if (color == "5") {
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
            if (i % (2 * space_between_stripes) < space_between_stripes)
            {
                for (int j = 0; j < frame_size; j++)
                {
                    // Set the color to gray for the stripes
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
            if (j % (2 * space_between_stripes) < space_between_stripes)
            {
                for (int i = 0; i < frame_size; i++)
                {
                    // Set the color to gray for the stripes
                    framed_photo(i, j, 0) = 128; // Red component
                    framed_photo(i, j, 1) = 128; // Green component
                    framed_photo(i, j, 2) = 128; // Blue component
                    framed_photo(frame_width - frame_size + i, j, 0) = 128; // Red component (right)
                    framed_photo(frame_width - frame_size + i, j, 1) = 128; // Green component (right)
                    framed_photo(frame_width - frame_size + i, j, 2) = 128; // Blue component (right)
                }
            }
        }

        // Save the framed photo
        framed_photo.saveImage("temporary_file.jpg");
    }

    // Load the framed image
    Image image("temporary_file.jpg");

    // Display a menu for further actions
    int choice = Display_Menu2();

    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        // Save the framed image with a new filename
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                image.sv(new_filename); // Save the framed image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// Detect image edges function
int Detect_Image_Edges(string filename){

    // Load the image
    Image image(filename);

    // Convert the image to grayscale
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            uint average = 0;

            for (int k = 0; k < 3; ++k) {
                average += image(i, j, k);
            }

            average /= 3;

            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = average;
            }
        }
    }

    // Save the grayscale image
    image.saveImage("temporary_file.jpg");
    Image gray_image("temporary_file.jpg");

    // Apply edge detection algorithm with Laplacian operator
    for (int i = 1; i < gray_image.width - 1; ++i) {
        for (int j = 1; j < gray_image.height - 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                int laplacian = abs(gray_image(i,j,k) - gray_image(i + 1,j + 1, k)) + abs(gray_image(i, j + 1, k) - gray_image(i + 1, j, k));
                gray_image(i, j, k) = (laplacian > 255) ? 255 : (laplacian < 0) ? 0 : laplacian;
            }
        }
    }

    // Invert the colors of the gray_image image
    for (int i = 0; i < gray_image.width; ++i) {
        for (int j = 0; j < gray_image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                gray_image(i, j, k) = 255 - gray_image(i, j, k);
            }
        }
    }

    // Display a menu for further actions
    int choice = Display_Menu2();

    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        gray_image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        // Save the edged image with a new filename
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                gray_image.sv(new_filename); // Save the edged image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// Resize image function
int Resize_Image(string filename){

    // Load the image
    Image image(filename);
    int new_width;
    int new_height;

    // Get new width and height from user
    cout << "\nPlease enter image new width: ";
    cin >> new_width;
    cout << "\nPlease enter image new height: ";
    cin >> new_height;

    // Create a new image with the specified width and height
    Image new_image(new_width, new_height);
    const float SCALING_CONST_W = (float)image.width / (float)new_width;
    const float SCALING_CONST_H = (float)image.height / (float)new_height;

    // Resize the image using nearest-neighbor interpolation
    for (int i = 0; i < new_width; ++i) {
        for (int j = 0; j < new_height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Calculate the corresponding pixel in the original image
                int new_pixel_W = i * SCALING_CONST_W;
                int new_pixel_H = j * SCALING_CONST_H;
                // Copy the pixel value to the new image
                new_image(i, j, k) = image(new_pixel_W, new_pixel_H, k);
            }
        }
    }

    // Display a menu for further actions
    int choice = Display_Menu2();

    // Handle user's choice
    if (choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if (choice == 2) {
        new_image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if (choice == 3) {
        // Save the resized image with a new filename
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if (!isValid(new_filename)) { // Check if the new filename is valid
                new_image.sv(new_filename); // Save the resized image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// Blur image function
int Blur_Image(string filename){

    string blur_level1;
    Image photo(filename);
    cout << "Please enter the blur level (1, 2, 3): ";
    getline(cin, blur_level1);

    // Validate the blur level input
    while(blur_level1 != "1" && blur_level1 != "2" && blur_level1 != "3"){
        cout << "\n------------ Invalid input ------------\n";
        cout << "Please enter the blur level (1, 2, 3): ";
        getline(cin, blur_level1);
    }

    int blur_level = stoi(blur_level1) - 1;

    // Calculate resized dimensions while maintaining aspect ratio
    int resized_width, resized_height;
    if (photo.width > photo.height) {
        resized_width = 800;
        resized_height = photo.height * 800 / photo.width;
    } else {
        resized_height = 800;
        resized_width = photo.width * 800 / photo.height;
    }

    // Resize the image for blurring
    Image resized_photo(resized_width, resized_height);
    Image new_image(resized_width,resized_height);

    const float SCALING_CONST_W = (float) photo.width / (float) resized_width;
    const float SCALING_CONST_H = (float) photo.height / (float) resized_height;

    for (int i = 0; i < resized_width; ++i) {
        for (int j = 0; j < resized_height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int new_pixel_W = i * SCALING_CONST_W;
                int new_pixel_H = j * SCALING_CONST_H;
                resized_photo(i, j, k) = photo(new_pixel_W, new_pixel_H, k);
            }
        }
    }

    // Blur parameters
    int kernel_size = 5 + blur_level * 4; // Increase kernel size for higher blur levels
    double sigma = 30 + blur_level * 10;  // Increase sigma value for higher blur levels

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
                            weighted_sum[c] += weight * resized_photo(neighbor_x, neighbor_y, c);
                        }
                        sum_of_weights += weight;
                    }
                }
            }
            // Assign the blurred pixel values back to the image
            for (int c = 0; c < 3; c++)
            {
                new_image(i, j, c) = weighted_sum[c] / sum_of_weights;
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
                new_image1(i,j,k) = new_image(new_pixel_W,new_pixel_H,k);
            }
        }
    }

    // Display a menu for further actions
    int choice = Display_Menu2();

    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        new_image1.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                new_image1.sv(new_filename); // Save the blurred image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// Sunlight filter function
int Sunlight_Filter(string filename){

    // Load the input image
    Image f1(filename);

    // Create an output image with the same dimensions as the input
    Image image(f1.width, f1.height);

    // Generate a yellow to black gradient
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i, j, 0) = 50;   // Red component
            image(i, j, 1) = 55;    // Green component
            image(i, j, 2) = 0;     // Blue component
        }
    }

    // Blend the input image with the gradient
    for (int i = 0; i < f1.width; ++i) {
        for (int j = 0; j < f1.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (f1(i, j, k) + image(i, j, k)) / 2; // Average the RGB values
            }
        }
    }

    // Increase the brightness of the image
    double factor = 1.11 + (150 / 255.0); // Factor for brightness adjustment
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int new_value = image(i, j, k) * factor; // Multiply pixel value by the factor
                image(i, j, k) = int(max(0, min(255, new_value))); // Ensure the value is within [0, 255] range
            }
        }
    }

    // Display the menu and return the user's choice
    int choice = Display_Menu2(); // Display a menu for further actions
    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                image.sv(new_filename); // Save the image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// OilPainting Filter function
int OilPainting_Filter(string filename){

    // Load the input image
    Image image(filename);

    // Set the radius of the painting effect
    int radius = 1;
    int width = image.width;
    int height = image.height;
    int intensity_levels = 10;

    // Apply the oil painting effect to the image
    for (int i = radius; i < width - radius; i++) {
        for (int j = radius; j < height - radius; j++) {
            // Initialize vectors to store intensity count and average color values
            vector<int> intensityCount(intensity_levels, 0);
            vector<int> averageR(intensity_levels, 0);
            vector<int> averageG(intensity_levels, 0);
            vector<int> averageB(intensity_levels, 0);

            // Compute intensity levels and update counts and averages
            for (int k = -radius; k <= radius; ++k) {
                for (int l = -radius; l <= radius; ++l) {
                    int r =  image.gp(i + k,j + l,0);
                    int g =  image.gp(i + k,j + l,1);
                    int b =  image.gp(i + k,j + l,2);
                    int intensity = (((r+g+b)/3)* intensity_levels )/ 255;
                    if( intensity > 255 )
                        intensity = 255;
                    int bin = intensity;
                    intensityCount[bin]++;
                    averageR[bin] += r;
                    averageG[bin] += g;
                    averageB[bin] += b;
                }
            }

            // Find the most frequent intensity level
            int current_max = 0;
            int max_index = 0;
            for( int nI = 0; nI < intensity_levels; nI++ )
            {
                if( intensityCount[nI] > current_max )
                {
                    current_max = intensityCount[nI];
                    max_index = nI;
                }
            }

            // Set the pixel to the average color of the most frequent intensity level
            image(i ,j ,0) = averageR[max_index] / current_max;
            image(i ,j ,1) = averageG[max_index] / current_max;
            image(i ,j ,2) = averageB[max_index] / current_max;

        }
    }

    // Display the menu and return the user's choice
    int choice = Display_Menu2(); // Display a menu for further actions
    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        // Save the image with a new filename, Ensure the filename has a valid extension, Save the image and display the current directory
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                image.sv(new_filename); // Save the image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// OLd TV Filter function
int Old_TV_Filter(string filename){

    // load the image
    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {

                // Applying scanline
                if ((j % 2) == 0){
                    // lighten pixel to simulate scanline
                    image(i, j, k) = image(i, j, k);
                    image(i, j + 1, k) = image(i, j + 1, k);
                }
                else{
                    // Add random noise
                    int noise = rand() % 56 - 10;       // random noise in [-45, 45]
                    int Value = image(i, j, k) + noise;
                    Value = min(255, max(0, Value));
                    image(i, j, k) = Value;
                }
            }
        }
    }
    // Save the image
    image.sv("temporary_file.jpg"); // temporary file here
    Image final_image("temporary_file.jpg");

    // Decreasing darken degree, Then multiply factor for all Pixel like a ratio of Darken
    double factor = 1.11 + (-48 / 255.0);

    // Darken image after applying Scanline
    for (int i = 0; i < final_image.width; i++) {
        for (int j = 0; j < final_image.height; j++) {
            for (int k = 0; k < final_image.channels; k++) {
                int new_value = final_image(i, j, k) * factor;
                final_image(i, j, k) = int(max(0, min(255, new_value))); // Check range of RGB and Modify it
            }
        }
    }


    int choice = Display_Menu2(); // Display a menu for further actions
    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        final_image.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                final_image.sv(new_filename); // Save the Old tv image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// Purple filter function
int Purple_Filter(string filename){

    // Load the input image
    Image photo(filename);

    // Apply the purple tint effect to the image
    for (int i = 0; i < photo.width; i++)
    {
        for (int j = 0; j < photo.height; j++)
        {
            // Get the current pixel's RGB values
            int red = photo.gp(i, j, 0);  // Get red channel value
            int green = photo.gp(i, j, 1); // Get green channel value
            int blue = photo.gp(i, j, 2);  // Get blue channel value

            // Increase red and blue, decrease green to create a purple tint
            red += 60; // increase red value
            green -= 30; // decrease green value
            blue += 60; // increase blue value

            // Ensure that values are within the valid range [0, 255]
            red = min(255, max(0, red));
            green = min(255, max(0, green));
            blue = min(255, max(0, blue));

            // Set the new RGB values to the pixel
            photo.setPixel(i, j, 0, red); // Red channel
            photo.setPixel(i, j, 1, green); // Green channel
            photo.setPixel(i, j, 2, blue); // Blue channel
        }
    }

    // Display the menu and return the user's choice
    int choice = Display_Menu2(); // Display a menu for further actions
    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        photo.sv("temporary_file.jpg"); // save the current Filter in temporary file
    }
    else if(choice == 3){
        // Save the image with a new filename, Ensure the filename has a valid extension, Save the image and display the current directory
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                photo.sv(new_filename); // Save the image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// Infrared Filter function
int Infrared_Filter(string filename)
{
    // initial variable and load image
    string color;
    Image image(filename);

    for(int i = 0; i < image.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < image.height; j++) // Using .height to get image height
        {
            image(i,j,0)=0;
        }
    }
    for(int i = 0; i < image.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < image.height; j++) // Using .height to get image height
        {
            for (int k = 0; k < 3; k++) // Assuming 3 color channels (RGB)
            {
                uint pixel_color = image.gp(i, j, k); // Assuming getPixel method exists
                uint pixel_inverted_color = 255 - pixel_color; // Inverting color
                image.setPixel(i, j, k, pixel_inverted_color); // Assuming setPixel method exists
            }
        }
    }

    int choice = Display_Menu2(); // Display a menu for further actions
    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        image.sv("temporary_file.jpg"); // save the current filter in temporary file
    }
    else if(choice == 3){
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                image.sv(new_filename); // Save the infrared image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }
    return choice; // Return the user's choice from the menu
}

// Skewing Filter function
int Skewing_Filter(string filename){

    // Initial variables and load image
    string angle;
    Image pic(filename);

    // Get user input for the skew angle
    while(true){
        try{
            // validate the angle value
            cout << "\nPlease enter the intensity of skewness from 0 to 90: ";
            getline(cin, angle);
            double a = stod(angle);
            if(a <= 90 && a >= 0)
                break;
            else
                cout << "\n------------------- invalid input ------------------";
        }
        catch(invalid_argument &a){
            cout << "\n------------------- invalid input ------------------";
        }
    }

    int width = pic.width;
    int height = pic.height;
    double new_angle = stod(angle);
    double added_width = cos((new_angle) * (3.14159/180)) * (double)height;
    const double SKEWING_CONST =  ((double)added_width/height);
    int new_width = added_width + width;
    Image image(new_width,height);

    for (int i = 0; i < new_width; ++i) {
        for (int j = 0; j < height; ++j) {
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;
        }
    }

    // Skew the image
    for (int i = 0; i < width ; ++i)
    {
        added_width = cos((new_angle) * (3.14159/180)) * (double)height;
        for (int j = 0; j < height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i + added_width,j,k) = pic(i,j,k);
            }
            added_width -=  SKEWING_CONST;
        }
    }

    // Display a menu for further actions
    int choice = Display_Menu2();

    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        image.sv("temporary_file.jpg"); // save the current filter in temporary file
    }
    else if(choice == 3){
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                image.sv(new_filename); // Save the skewing image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }

    return choice; // Return the user's choice from the menu
}

// NightVision filter function
int NightVision_Filter(string filename){

    // Load the input image
    Image photo(filename);

    // Set the red and blue channels to 0, effectively removing them
    for(int i = 0; i < photo.width; i++) // Using .width  to get image width
    {
        for (int j = 0; j < photo.height; j++) // Using .height to get image height
        {
            photo(i,j,0) = 0; // Set red channel to 0
            photo(i,j,2) = 0; // Set blue channel to 0
        }
    }

    // Increase the brightness of the image
    double factor = 1.11 + (-45.0 / 255.0);
    for (int i = 0; i < photo.width; i++) {
        for (int j = 0; j < photo.height; j++) {
            for (int k = 0; k < photo.channels; k++) {
                int new_value = photo(i, j, k) * factor;
                photo(i, j, k) = int(max(0, min(255, new_value))); // Check range of RGB and Modify it
            }
        }
    }

    // Display the menu and return the user's choice
    int choice = Display_Menu2(); // Display a menu for further actions
    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        photo.sv("temporary_file.jpg"); // save the current filter in temporary file
    }
    else if(choice == 3){
        // Save the image with a new filename, Ensure the filename has a valid extension, Save the image and display the current directory
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                photo.sv(new_filename); // Save the image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }
    return choice; // Return the user's choice from the menu
}

// Noise filter function
int Noise_Filter(string filename){

    // Load the input image
    Image photo(filename);

    // Add random noise to each pixel in the image
    for (int i = 0; i < photo.width; i++) {
        for (int j = 0; j < photo.height; j++) {
            for (int k = 0; k < photo.channels; k++) {

                // Generate a random factor to multiply the pixel value by
                double factor = 1.11 + (-1 * (rand() % 121) / 255.0);
                int new_value = photo(i, j, k) * factor;
                photo(i, j, k) = int(max(0, min(255, new_value))); // Check range of RGB and Modify it

            }
        }
    }

    // Display the menu and return the user's choice
    int choice = Display_Menu2(); // Display a menu for further actions
    // Handle user's choice
    if(choice == 1) {
        cout << endl;
        return 0; // Exit the function
    }
    else if(choice == 2){
        photo.sv("temporary_file.jpg"); // save the current filter in temporary file
    }
    else if(choice == 3){
        // Save the image with a new filename, Ensure the filename has a valid extension, Save the image and display the current directory
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "\nPlease enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 4, size) != ".jpg" && new_filename.substr(size - 4, size) != ".bmp" && new_filename.substr(size - 4, size) != ".png")) && (size < 6 || (new_filename.substr(size - 5, size) != ".jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) { // Check if the new filename is valid
                photo.sv(new_filename); // Save the flipped image with the new filename
                cout << "Your image is saved in: " << fs::current_path().string() << "\n\n"; // Print the image path
                break;
            }
            else {
                cout << "----- File already exists -----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
        }
        SetCurrentDirectory(old_dir.c_str()); // Restore the old directory
    }
    return choice; // Return the user's choice from the menu
}

// Display Menu, which contains all Filters and take file path from user
void Display_Menu1(){

    // Display the welcome message
    cout << "|-------------- Ahlan ya User ya Habibi --------------|\n"
         << "|    In this application we can enhance or modify     |\n"
         << "|    the image via tools called filters. You can      |\n"
         << "|    enter your image, choose the Filter you want,    |\n"
         << "|    and then the image is modified                   |\n"
         << "|-----------------------------------------------------|\n\n";

    int chance = 0;
    string filename, choice1;
    bool flag = false;
    // Main loop for the menu
    while (true){

        // Prompt the user for the file path
        if(chance == 0 || chance == 1){
            remove("temporary_file.jpg"); // Remove temporary file from the project path
            cout << "Please enter your file path or exit (by enter exit): ";
            getline(cin, filename);
        }

        // if user enter 4, then he wants to save the final image and continue
        else if(chance == 3){
            chance = 0;
            remove("temporary_file.jpg"); // Remove temporary file from the project path
            continue; // Continue to the next iteration of the loop
        }

        // if user enter 4, then he wants to exit the program
        else if(chance == 4){
            remove("temporary_file.jpg"); // Remove temporary file from the project path
            break; // Exit the loop
        }

        // if user enter 2, then apply the current filter and continue with the same image
        else {
            filename = "temporary_file.jpg";
        }

        if (to_upper(filename) == "EXIT") {
            cout << "\n---------------------------------\n"
                 << " Thank you for using our Program\n"
                 << "---------------------------------\n";
            break;
        }

        // Validate the file path
        while (true) {
            if (isValid(filename)) {
                break; // Exit the loop if the file exists
            } else {
                cout << "\n---------------- File doesn't exist ----------------\n";
                cout << "Please enter your file path or exit (by enter exit): ";
                getline(cin, filename);

                if (to_upper(filename) == "EXIT") {
                    cout << "\n---------------------------------\n"
                         << " Thank you for using our Program\n"
                         << "---------------------------------\n";
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            break;

        // Display the Filter menu
        cout << "\n|------ What do you want to do ? -----|\n"
             << "1)  Grayscale Filter                  |\n"
             << "2)  Black & White Filter              |\n"
             << "3)  Invert Filter                     |\n"
             << "4)  Merge Images                      |\n"
             << "5)  Flip Image                        |\n"
             << "6)  Rotate Image                      |\n"
             << "7)  Darken & Lighten Images           |\n"
             << "8)  Crop Image                        |\n"
             << "9)  Adding a frame to the Image       |\n"
             << "10) Detect Image Edges                |\n"
             << "11) Resizing Image                    |\n"
             << "12) Blur Image                        |\n"
             << "13) Sunlight Filter                   |\n"
             << "14) Oil Painting Filter               |\n"
             << "15) Old TV Filter                     |\n"
             << "16) Purple Filter                     |\n"
             << "17) Infrared Filter                   |\n"
             << "18) Skewing Filter                    |\n"
             << "19) Night Vision Filter               |\n"
             << "20) Noise Filter                      |\n"
             << "|-------------------------------------|\n"
             << "Please enter your choice from the menu: ";

        getline(cin, choice1); // Get the user's choice

        // Validate the user's choice
        while (true) {
            if (choice1 == "1" || choice1 == "2" || choice1 == "3" || choice1 == "4" || choice1 == "5" || choice1 == "6" || choice1 == "7" || choice1 == "8" || choice1 == "9" || choice1 == "10" || choice1 == "11" || choice1 == "12" || choice1 == "13" || choice1 == "14" || choice1 == "15" || choice1 == "16" || choice1 == "17" || choice1 == "18" || choice1 == "19" || choice1 == "20")
                break; // Exit the loop if the choice is valid
            else {
                cout << "Please enter your choice from the menu: ";
                getline(cin, choice1);
            }
        }

        // Call the corresponding Filter function based on the user's choice
        if (choice1 == "1")
            chance = GrayScale_Filter(filename); // Applying grayscale Filter
        else if (choice1 == "2")
            chance = BlackAndWhite_Filter(filename); // Applying black & white Filter
        else if (choice1 == "3")
            chance = Invert_Filter(filename); // Applying invert Filter
        else if (choice1 == "4")
            chance = Merge_2_Images(filename); // Applying Merge 2 Images Filter
        else if (choice1 == "5")
            chance = Flip_Image(filename); // Applying flip Filter
        else if (choice1 == "6")
            chance = Rotate_Image(filename); // Applying Rotating tool
        else if (choice1 == "7")
            chance = DarkenAndLighten_image(filename); // Applying Darken & Lighten Filter
        else if (choice1 == "8")
            chance = Crop_Image(filename); // Applying Cropping tool
        else if (choice1 == "9")
            chance = Frame_to_Image(filename); // Applying Frame Filter
        else if (choice1 == "10")
            chance = Detect_Image_Edges(filename); // Applying ( Detect Image Edges ) Filter
        else if (choice1 == "11")
            chance = Resize_Image(filename); // Applying Resizing tool
        else if (choice1 == "12")
            chance = Blur_Image(filename); // Applying Blur Image Filter
        else if (choice1 == "13")
            chance = Sunlight_Filter(filename); // Applying Old_TV Filter
        else if (choice1 == "14")
            chance = OilPainting_Filter(filename); // Applying flip Filter
        else if (choice1 == "15")
            chance = Old_TV_Filter(filename); // Applying flip Filter
        else if (choice1 == "16")
            chance = Purple_Filter(filename); // Applying flip Filter
        else if (choice1 == "17")
            chance = Infrared_Filter(filename); // Applying flip Filter
        else if (choice1 == "18")
            chance = Skewing_Filter(filename); // Applying flip Filter
        else if (choice1 == "19")
            chance = NightVision_Filter(filename); // Applying flip Filter
        else if (choice1 == "20")
            chance = Noise_Filter(filename); // Applying flip Filter
    }
}


int main() {

    Display_Menu1(); // Call the function to running the completing code
    return 0;
}