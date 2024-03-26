// ===================================================================================== //
// FCAI – Structured Programming – 2024 - Assignment
// File:    CS112_A3_Part1_S5S6_20230003_20230016_20230233.cpp
// Purpose:
// Author:  Ibrahim Mohamed Saad Mohamed_S6_20230003 => Filter 1
//          Ahmed Hussein Mohamed Ahmed_S5_20230016  => Filter 2, 5
//          Ezz eldin Omar Abdellatif_S6_20230233    => Filter 3, 6
// Emails:  hes93314@gmail.com
//          hzrdu3500@gmail.com
//          ezzeldinomar@gmail.com
// TA name: Rana Abdelkader
// Date:    3/15/2024
// Version: 3.0
// ===================================================================================== //

#include "Image_Class.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#define sv saveImage
#define uint unsigned int
#define gp getPixel

using namespace std;

bool isValid(string filename){
    ifstream file;
    file.open(filename);
    if(file)
        return true;
    else
        return false;
}

void saving_options()
{
    string path_choice;
    cout << "|Select whether to save the file-|" << endl;
    cout << "in the same path or a new one: --|" << endl;
    cout << "1) Save in the same path---------|" << endl;
    cout << "2) Save in a new path------------|" << endl;
    cout << "|--------------------------------|" << endl;
    cout << "enter your choice: " ;
    getline(cin,path_choice);
    cout << endl;
    while ( stoi (path_choice) != 1 && stoi (path_choice) != 2)
    {
        cout << "invalid input, please your choice (1,2) : ";
        cin >> path_choice;
        cout << endl;
    }
    if ( stoi (path_choice) == 2)
    {
        string new_filepath;
        cout << "Please enter the new directory path: ";
        getline(cin,new_filepath);
        cout << endl;
        while (!SetCurrentDirectory(new_filepath.c_str()))
        {
            cout << "\n---- Directory does not exist ----\n";
            cout << "Please enter the new Directory path: ";
            getline(cin, new_filepath);
            cout << endl;
        }
    }

}

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


int GrayScale_Image(string filename)
{
    Image image(filename);

    for (int i = 0; i < image.width; ++i){
        for (int j = 0; j < image.height; ++j){
            uint average = 0;

            for (int k = 0; k < 3; ++k){
                average += image(i,j,k);
            }
            average /= 3;

            for (int k = 0; k < 3; ++k) {
                image(i,j,k) = average;
            }
        }
    }
    int choice = Display_Menu2();
    if(choice == 1) {
        cout << endl;
        return 0;
    }
    else if(choice == 2){
        image.sv(filename);
    }
    else if(choice == 3){
        string new_filename;
        cout << "Please enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        saving_options();
        while(true){
           if(!isValid(new_filename)) {
               image.sv(new_filename);
               break;
           }
           else {
               cout << "\n---- File does already exist ----\n";
               cout << "Please enter name of new file: ";
               getline(cin, new_filename);
           }
        }
        SetCurrentDirectory(old_dir.c_str());
    }
    return choice;
}


int Black_White_Image(string filename)
{
    Image image(filename);

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
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (image(i, j, 0) >= 127) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            } else
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }

        }
    }

    int choice = Display_Menu2();
    if(choice == 1) {
        cout << endl;
        return 0;
    }
    else if(choice == 2){
        image.sv(filename);
    }
    else if(choice == 3){
        string new_filename;
        cout << "Please enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        saving_options();

        while(true){
            if(!isValid(new_filename)) {
                image.sv(new_filename);
                break;
            }
            else {
                cout << "\n---- File is already exist ----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
            }
        }
        SetCurrentDirectory(old_dir.c_str());
    }
    return choice;
}


int Invert_Image(string filename)
{
    Image image(filename); // Assuming Image class constructor takes a filename

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
    int choice = Display_Menu2();
    if(choice == 1) {
        cout << endl;
        return 0;
    }
    else if(choice == 2){
        image.sv(filename);
    }
    else if(choice == 3){
        string new_filename;
        cout << "Please enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        saving_options();
        while(true){
            if(!isValid(new_filename)) {
                image.sv(new_filename);
                break;
            }
            else {
                cout << "\n---- File is already exist ----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
            }
        }
        SetCurrentDirectory(old_dir.c_str());
    }
    return choice;
}


int Rotate_Image(string filename)
{
    string file_name;
    string degree_rotation;
    cout << "\nPlease enter the degree_rotation (90 or 270 or 180): ";
    cin >> degree_rotation;
    Image image(filename);

    while(degree_rotation != "90" && degree_rotation != "180" && degree_rotation != "270")
    {
        cout << "\n------------------- Invalid input -------------------\n";
        cout << "Please enter the degree_rotation (90 or 270 or 180): ";
        cin >> degree_rotation;
    }

    Image new_photo_180(image.width,image.height);
    Image new_photo_270(image.height,image.width);
    Image new_photo_90(image.height,image.width);

    if(degree_rotation=="180")
    {
        for(int i = 0; i < image.width; i++) // Using .width  to get image width
        {
            for (int j = 0; j < image.height; j++) // Using .height to get image height
            {
                for (int k = 0; k < 3; k++) // Assuming 3 color channels (RGB)
                {
                    new_photo_180(image.width-i-1,image.height-j-1,k)=image(i,j,k);
                }
            }
        }
    }
    else if (degree_rotation=="270")
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    new_photo_270(j, image.width - i - 1, k) = image(i, j, k);
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
                    new_photo_90(image.height - j - 1, i, k) = image(i, j, k);
                }
            }
        }
    }

    cin.ignore();
    int choice = Display_Menu2();
    if(choice == 1) {
        cout << endl;
        return 0;
    }
    else if(choice == 2){
        if(degree_rotation=="180")
            new_photo_180.sv(filename);
        else if (degree_rotation=="270")
            new_photo_270.sv(filename);
        else
            new_photo_90.sv(filename);
    }
    else if(choice == 3){
        string new_filename;
        cout << "Please enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        saving_options();
        while(true){
            if(!isValid(new_filename)) {
                if(degree_rotation=="180")
                    new_photo_180.sv(filename);
                else if (degree_rotation=="270")
                    new_photo_270.sv(filename);
                else
                    new_photo_90.sv(filename);
                break;
            }
            else {
                cout << "\n---- File is already exist ----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
            }
        }SetCurrentDirectory(old_dir.c_str());
    }
    return choice;
}


int Flip_Image(string filename)
{
    Image image(filename);

    while (true)
    {
        cout << "\n|-----------------------|\n"
             << "1) Flip horizontally    |\n"
             << "2) Flip vertically      |\n"
             << "|-----------------------|\n"
             << "Please enter your choice: ";
        string choice;
        getline(cin, choice);
        while (choice != "1" && choice != "2")
        {
            cout << "\n--------- invalid input --------\n";
            cout << "Please enter your choice (A/B): ";
            getline(cin, choice);
        }
        if ( choice == "1")
        {
            for (int i = 0; i < image.width / 2; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    uint pixel1;
                    uint pixel2;
                    int width = image.width;
                    int height = image.height;
                    for (int k = 0; k < 3; ++k) {
                        pixel1 = image.gp(i,j,k);
                        pixel2 = image.gp(width - i -1,j,k);
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
                    uint pixel1;
                    uint pixel2;
                    int width = image.width;
                    int height = image.height;
                    for (int k = 0; k < 3; ++k) {
                        pixel1 = image.gp(i,j,k);
                        pixel2 = image.gp(i, height - j - 1,k);
                        image.setPixel(i,j,k,pixel2);
                        image.setPixel(i,height - j - 1,k,pixel1);
                    }
                }
            }
            break;
        }

    }
    int choice = Display_Menu2();
    if(choice == 1) {
        cout << endl;
        return 0;
    }
    else if(choice == 2){
        image.sv(filename);
    }
    else if(choice == 3){
        string new_filename;
        cout << "Please enter name of new file: ";
        getline(cin, new_filename);
        cout << endl;
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        string old_dir(buffer);
        saving_options();
        while(true){
            if(!isValid(new_filename)) {
                image.sv(new_filename);
                break;
            }
            else {
                cout << "\n---- File is already exist ----\n";
                cout << "Please enter name of new file: ";
                getline(cin, new_filename);
            }
        }
        SetCurrentDirectory(old_dir.c_str());
    }
    return choice;
}


void Display_Menu1(){

    cout << "|-------------- Ahlan ya User ya Habibi --------------|\n"
         << "|    In this application we can enhance or modify     |\n"
         << "|    the image via tools called filters. You can      |\n"
         << "|    enter your image, choose the filter you want,    |\n"
         << "|    and then the image is modified                   |\n"
         << "|-----------------------------------------------------|\n\n";

    int chance = 0;
    string filename, choice1;

    while (true){

        if(chance == 0 || chance == 1){
            cout << "Please enter your file path: ";
            getline(cin, filename);
        }
        else if(chance == 3){
            chance = 0;
            continue;
        }
        else if(chance == 4){
            break;
        }

        while (true) {
            if (isValid(filename)) {
                break;
            } else {
                cout << "\n----- File does not exist -----\n";
                cout << "Please enter your file path: ";
                getline(cin, filename);
            }
        }

        cout << "\n|------ What do you want to do ? -----|\n"
             << "1) Grayscale image                    |\n"
             << "2) Black & White image                |\n"
             << "3) Invert image                       |\n"
             << "4) Rotate image                       |\n"
             << "5) Flip image                         |\n"
             << "|-------------------------------------|\n"
             << "Please choose from the menu [1, 2, 3, 4, 5, 6]: ";

        getline(cin, choice1);

        while (true) {
            if (choice1 == "1" || choice1 == "2" || choice1 == "3" || choice1 == "4" || choice1 == "5")
                break;
            else {
                cout << "Please choose from the menu [1, 2, 3, 4, 5, 6]: ";
                getline(cin, choice1);
            }
        }

        if (choice1 == "1")
            chance = GrayScale_Image(filename);
        else if (choice1 == "2")
            chance = Black_White_Image(filename);
        else if (choice1 == "3")
            chance = Invert_Image(filename);
        else if (choice1 == "4")
            chance = Rotate_Image(filename);
        else if (choice1 == "5")
            chance = Flip_Image(filename);
    }
}


int main() {
    Display_Menu1();
}