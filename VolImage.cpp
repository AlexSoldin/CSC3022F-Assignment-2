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

bool SLDALE003::VolImage::readImages(std::string baseName){
    string line;
    ifstream file("./brain_mri_raws/" + baseName + "/MRI.data");
    int width, height, numImages;
    if (file.is_open()) {
        getline(file, line);
        vector<string> values;
        string instance = 0;
        while (std::cin >> instance){
            values.push_back(instance);
        }
    
        cout << "Width: " << values[0] << " Height: " << values[1] << " imgs " << values[2] << endl;
        width = stoi(values[0]);
        height = stoi(values[1]);
        numImages = stoi(values[2]);
    }
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

