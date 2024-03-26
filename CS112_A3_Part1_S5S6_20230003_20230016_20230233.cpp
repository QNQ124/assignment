// ===================================================================================== //
// FCAI – Structured Programming – 2024 - Assignment
// File:    CS112_A3_Part1_S5S6_20230003_20230016_20230233.cpp
// Purpose: This program allows users to apply filters to images, including
//          grayscale conversion, black and white conversion, image inversion,
//          rotation, and flipping. It provides a user-friendly menu for selecting
//          filters and saving the modified images.
// Author:  Ibrahim Mohamed Saad Mohamed_S6_20230003 => Filter 1
//          Ahmed Hussein Mohamed Ahmed_S5_20230016  => Filter 2, 5
//          Ezz eldin Omar Abdellatif_S6_20230233    => Filter 3, 6
// Emails:  hes93314@gmail.com
//          hzrdu3500@gmail.com
//          ezzeldinomar7@gmail.com
// TA name: Rana Abdelkader
// Date:    3/26/2024
// Version: 5.0
// ===================================================================================== //

// Include necessary libraries
#include <iostream>
#include "Image_Class.h"  // Assuming this is a custom image class
#include <fstream>        // Input/output stream class to operate on files.
#include <windows.h>      // For Windows-specific functions like SetCurrentDirectory
#include <filesystem>     // For filesystem operations
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
            cout << "---- Directory does not exist ----\n";
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
         << "2) apply a filter                |\n"
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
        cout << "\n-------------------------------\n"
             << " Thank you for using our Program\n"
             << "-------------------------------\n";
    }
    return stoi(choice);
}

// Function to convert an image to grayscale
int GrayScale_Image(string filename)
{
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
        image.sv(filename);
    }
    else if (choice == 3) {
        // Save the image with a new filename, Ensure the filename has a valid extension, Save the image and display the current directory
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        string new_filename;
        cout << "Please enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 3, size) != "jpg" && new_filename.substr(size - 3, size) != "bmp" && new_filename.substr(size - 3, size) != "png")) && (size < 6 || (new_filename.substr(size - 4, size) != "jpeg"))) {
                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if (!isValid(new_filename)) {
                image.sv(new_filename);
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
int Black_White_Image(string filename)
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
        image.sv(filename);
    }
    else if (choice == 3) {
        // Save the image with a new filename, Ensure the filename has a valid extension, Save the image and display the current directory
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        string new_filename;
        cout << "Please enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 3, size) != "jpg" && new_filename.substr(size - 3, size) != "bmp" && new_filename.substr(size - 3, size) != "png")) && (size < 6 || (new_filename.substr(size - 4, size) != "jpeg"))) {                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if (!isValid(new_filename)) {
                image.sv(new_filename);
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
int Invert_Image(string filename)
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
        image.sv(filename);
    }
    else if(choice == 3){
        // Save the image with a new filename, Ensure the filename has a valid extension, Save the image and display the current directory
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        string new_filename;
        cout << "Please enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 3, size) != "jpg" && new_filename.substr(size - 3, size) != "bmp" && new_filename.substr(size - 3, size) != "png")) && (size < 6 || (new_filename.substr(size - 4, size) != "jpeg"))) {                cout << "--- Wrong in file extension ---\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
                size = new_filename.size();
                cout << endl;
            }
            else if(!isValid(new_filename)) {
                image.sv(new_filename);
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
            new_photo_180.sv(filename); // Save the rotated image
        else if(degree_rotation == "270")
            new_photo_270.sv(filename);
        else
            new_photo_90.sv(filename);
    }
    else if(choice == 3){
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "Please enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 3, size) != "jpg" && new_filename.substr(size - 3, size) != "bmp" && new_filename.substr(size - 3, size) != "png")) && (size < 6 || (new_filename.substr(size - 4, size) != "jpeg"))) {                cout << "--- Wrong in file extension ---\n";
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
        image.sv(filename); // Save the flipped image
    }
    else if(choice == 3){
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer); // Get the current directory
        string old_dir(buffer); // Store the current directory
        string new_filename;
        cout << "Please enter name of new file: ";
        getline(cin, new_filename); // Get the new filename from user
        cout << endl;
        saving_options();
        int size = new_filename.size();
        while (true) {
            if ((size < 5 || (new_filename.substr(size - 3, size) != "jpg" && new_filename.substr(size - 3, size) != "bmp" && new_filename.substr(size - 3, size) != "png")) && (size < 6 || (new_filename.substr(size - 4, size) != "jpeg"))) {                cout << "--- Wrong in file extension ---\n";
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

// Display Menu, which contains all Filters and take file path from user
void Display_Menu1(){

    // Display the welcome message
    cout << "|-------------- Ahlan ya User ya Habibi --------------|\n"
         << "|    In this application we can enhance or modify     |\n"
         << "|    the image via tools called filters. You can      |\n"
         << "|    enter your image, choose the filter you want,    |\n"
         << "|    and then the image is modified                   |\n"
         << "|-----------------------------------------------------|\n\n";

    int chance = 0;
    string filename, choice1;

    // Main loop for the menu
    while (true){

        // Prompt the user for the file path
        if(chance == 0 || chance == 1){
            cout << "Please enter your file path: ";
            getline(cin, filename);
        }
        else if(chance == 3){
            chance = 0;
            continue; // Continue to the next iteration of the loop
        }
        else if(chance == 4){
            break; // Exit the loop
        }

        // Validate the file path
        while (true) {
            if (isValid(filename)) {
                break; // Exit the loop if the file exists
            } else {
                cout << "\n---- File doesn't exist ----\n";
                cout << "Please enter your file path: ";
                getline(cin, filename);
            }
        }

        // Display the filter menu
        cout << "\n|------ What do you want to do ? -----|\n"
             << "1) Grayscale image                    |\n"
             << "2) Black & White image                |\n"
             << "3) Invert image                       |\n"
             << "4) Rotate image                       |\n"
             << "5) Flip image                         |\n"
             << "|-------------------------------------|\n"
             << "Please choose from the menu [1, 2, 3, 4, 5, 6]: ";

        getline(cin, choice1); // Get the user's choice

        // Validate the user's choice
        while (true) {
            if (choice1 == "1" || choice1 == "2" || choice1 == "3" || choice1 == "4" || choice1 == "5")
                break; // Exit the loop if the choice is valid
            else {
                cout << "Please choose from the menu [1, 2, 3, 4, 5, 6]: ";
                getline(cin, choice1);
            }
        }

        // Call the corresponding filter function based on the user's choice
        if (choice1 == "1")
            chance = GrayScale_Image(filename); // Apply grayscale filter
        else if (choice1 == "2")
            chance = Black_White_Image(filename); // Apply black and white filter
        else if (choice1 == "3")
            chance = Invert_Image(filename); // Apply invert filter
        else if (choice1 == "4")
            chance = Rotate_Image(filename); // Apply rotate filter
        else if (choice1 == "5")
            chance = Flip_Image(filename); // Apply flip filter
    }
}


int main() {
    Display_Menu1(); // Call the function to running the completing code
    return 0;
}