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
    // for(int slice = 0; slice < slices.size(); slice++){
    //     for(int i = 0; i < height; i ++){
    //         delete [] slices[slice][i];
    //     }
    //     delete [] slices[slice];
    // }
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

int main(int argc, char *argv[]){
    SLDALE003::VolImage volImage;

    string imageBase = argv[1];
    volImage.readImages(imageBase);

    if(argc > 2){
        string currentArg = argv[2];
        string diffArg = "-d";
        string extractArg = "-x";

        if(currentArg.compare(diffArg)==0){
            string sliceI = argv[3];
            string sliceJ = argv[4];
            string outfile_preifx = argv[5];
            int sliceI_i = stoi(sliceI);
            int sliceJ_i = stoi(sliceJ);
            //volImage.diffmap(sliceI_i, sliceJ_i, outfile_preifx);

            if (argc > 6){
                string slice = argv[7];
                int slice_i = stoi(slice);
                string outfile_prefix = argv[8];
                //volImage.extract(slice_i, outfile_prefix);
            }
        }

        else if(currentArg.compare(extractArg)==0){
            string slice = argv[3];
            int slice_i = stoi(slice);
            string outfile_prefix = argv[4];
            //volImage.extract(slice_i, outfile_prefix);

            if (argc > 5){
                string sliceI = argv[6];
                string sliceJ = argv[7];
                string outfile_preifx = argv[8];
                int sliceI_i = stoi(sliceI);
                int sliceJ_i = stoi(sliceJ);
                //volImage.diffmap(sliceI_i, sliceJ_i, outfile_preifx);
            }
        }
    }

    return 0;
}

