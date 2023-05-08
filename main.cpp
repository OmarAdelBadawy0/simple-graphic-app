// FCI � Programming 1 � 2022 - Assignment 3
// Program Name: CS112-203-2nd-S3,S4-20210343-20210188-20210266-A3-Part1.cpp
// Last Modification Date: 07/04/2022
// Author1 and ID and Group: mohamed tarek - 20210343
// Author2 and ID and Group: salah eldin Hesham - 202188
// Author3 and ID and Group: Omar Adel - 20210266
// Teaching Assistant: Nesma
// Purpose: learning c++
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"`  

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
void loadImage ();
void saveImage ();
void blackandwhite ();
void invertimage();
void merge1();
void flip();
void darkenandlighten();
void Rotate1();
void Rotate();

int main() {
    loadImage();
    int choice;
    cout<<"1- Black & White Filter\n2- Invert Filter\n3- Merge Filter"<<endl;
cout<<"4- Flip Image\n5- Rotate Image  \n6- Darken and Lighten Image"<<endl;

    cout << "Please select a filter to apply or 0 to exit: ";
    cin >> choice;
    if (choice == 1) {
        blackandwhite();
        saveImage();
    } else if (choice == 2) {
        invertimage();
        saveImage();
    } else if (choice == 3) {
        merge1();
        saveImage();
    } else if (choice == 4) {
        flip();
        saveImage();
    } else if (choice == 5) {
        Rotate();
        saveImage();
    } else if (choice == 6) {
        darkenandlighten();
        saveImage();
    } else if (choice == 0){
        cout<<"BYE!!";
    }

    return 0;
}

void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout <<"Ahlan ya user ya habibi \nPlease Enter file name of the image to process:"<<endl;
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
void blackandwhite()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}
void invertimage()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
}
void merge1()
{
    char image2FileName[100];

    // Get gray scale image file name
    cout << "Enter image file name: ";
    cin >> image2FileName;

    // Add to it .bmp extension and load image
    strcat (image2FileName, ".bmp");
    readGSBMP(image2FileName, image2);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] =  (image[i][j] + image2[i][j])/2;
        }
    }
}
void flip()
{
    char choice2;
    cout << "Do you want (v)ertically or (h)orzintaliy: ";
    cin >> choice2;
    if (choice2=='v')
    {
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j < SIZE; j++) {
                swap(image[i][j] ,  image[SIZE-i][j]) ;
            }
        }
    }
    else if (choice2 == 'h')
    {
        for (int i = 0; i < SIZE; i += 1)
        {
            for (int j = 0; j < SIZE/2; j += 1)
            {
                swap(image[i][j], image[i][SIZE-j]);
            }
        }
    }
    else
        cout << "Invalid input ";

}

void darkenandlighten()
{   int num =0 ;
    char choice1;
    cout << "Do you want (d)arken or (l)ighten: ";
    cin>> choice1;
    if (choice1 == 'l')
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                num = image[i][j] + image[i][j] / 2;
                if (num > 255)
                    num = 255;
                image[i][j] = num;

            }
        }
    }
    else if (choice1 = 'd')
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i][j]/2;

            }
        }
    }
    else
        cout << "Invalid input ";

}

void Rotate1(){
   for (int i = 0; i < 256; i += 1) {
        for (int j = i+1; j < 256; j += 1) {
            swap(image[i][j], image[j][i]);//it will swap every row by columns
        }
    }
    for (int i = 0; i < 256; i += 1) {
        for (int j = 0; j < 128; j += 1) {
            swap(image[i][j], image[i][255-j]);
        }
    }

}

void Rotate(){
    int choice1 ;
    cout<<"Do you want to rotate the image \n1. 90 Degree"<<endl;
    cout<<"2. 180 Degree\n3. 270 Degree :";\
    cin>>choice1;

    if(choice1 == 1){
        Rotate1();
    }
    if(choice1 == 2){
        Rotate1();
        Rotate1();
    }
    if(choice1 == 3){
        Rotate1();
        Rotate1();
        Rotate1();
    }
}

