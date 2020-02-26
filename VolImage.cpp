#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ios>

#include "VolImage.h"

using namespace std;

SLDALE003::VolImage::VolImage(){
    width=0;
    height=0;
}

SLDALE003::VolImage::~VolImage(){
    for(int slice = 0; slice < slices.size(); slice++){
        for(int i = 0; i < height; i ++){
            delete [] slices[slice][i];
        }
        delete [] slices[slice];
    }
}

bool SLDALE003::VolImage::readImages(string baseName){
    ifstream file("./" + baseName + ".data");
    vector<int> headerValues;
    int instance = 0;
    while(!file.eof()){
        file >> instance >> ws;
        headerValues.push_back(instance);
    }

    width = headerValues[0];
    height = headerValues[1];
    int numImages = headerValues[2];
    cout << "Width: " << to_string(width) << "\nHeight: " << to_string(height) << "\nNumImages: " << to_string(numImages) << endl;

    

    return true;
}

// void SLDALE003::VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix){
//     cout << "Successfully called diffmap";
// }

// void SLDALE003::VolImage::extract(int sliceId, string output_prefix){
//     cout << "Successfully called extract";
// }

int SLDALE003::VolImage::volImageSize(void){
    return 0;
}

