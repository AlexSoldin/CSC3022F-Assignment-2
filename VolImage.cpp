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
    for(int i = 0; i < slices.size(); i++){
        for(int j = 0; j < height; j ++){
            delete [] slices[i][j];
        }
        delete [] slices[i];
    }
}

bool SLDALE003::VolImage::readImages(string baseName){
    ifstream file("./" + baseName + ".data");
    vector<int> headerValues;
    int instance = 0;
    while(!file.eof()){
        file >> instance >> ws; //ignores whitespace and adds each value to int vector
        headerValues.push_back(instance);
    }

    width = headerValues[0];
    height = headerValues[1];
    int numImages = headerValues[2];
    cout << "Width: " << to_string(width) << "\nHeight: " << to_string(height) << "\nNumImages: " << to_string(numImages) << endl;

    for(int sliceNumber=0; sliceNumber<numImages; sliceNumber++){
        unsigned char ** slice = new unsigned char * [height];
        string sliceName = baseName+to_string(sliceNumber)+".raw";
        ifstream rawInput(sliceName, ios::binary);

        int rowCounter = 0;
        while(rowCounter<height){
            unsigned char * row = new unsigned char[width];
            rawInput.read((char*)row, width);
            slice[rowCounter] = row;
            rowCounter++;
        }
        slices.push_back(slice);
        rawInput.close();
    }

    /*  I used this to view the data to better my understanding 
        slices[imageNumber][Row][Column]
        e.g. slices[0][0][429] 
    */
//    for (int row = 0; row < height; row++){
//        std::bitset<8> x(slices[2][row][420]); //displays all data from a certain image number
//        cout << x;
//     }
   
    int numBytes = volImageSize();

    cout << "\nNumber of images: " << to_string(numImages);
    cout << "\nNumber of bytes required: " << to_string(numBytes);
    cout << "\n\n";

    return true;
}

void SLDALE003::VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix){
    cout << "Difference Map between slice " << to_string(sliceI) << " and slice " << to_string(sliceJ) << "." << endl;
    unsigned char ** slice1 = slices[sliceI];
    unsigned char ** slice2 = slices[sliceJ];
    unsigned char ** result = new unsigned char * [height];

    for (int i = 0; i < height; i++){
        result[i] = new unsigned char[width];
        for (int j = 0; j < width; j++){
            int value = ((float)slice1[i][j] - (float)slice2[i][j])/2;
            result[i][j] = (unsigned char)(abs(value));
        }
    }
}

void SLDALE003::VolImage::extract(int sliceId, string output_prefix){
    cout << "Successfully called extract";
}

int SLDALE003::VolImage::volImageSize(void){
    int numBytes = 0;

    for (int i = 0; i < slices.size(); i++){
        numBytes += sizeof(slices[i]); //size of pointer to 2D array

        for (int j = 0; j < height; j++){
            numBytes += sizeof(slices[i][j]); //size of the pointer to the row
            numBytes += width; //each row has width * many unsigned chars of size 1 byte
        }
    }
    return numBytes;
}

/* This method writes the output header file and the output file */
void SLDALE003::VolImage::writeOutputFile(unsigned char ** slice, std::string output_prefix){
    //write to header file
    ofstream headerFile;
    headerFile.open("./Output/"+output_prefix+".data");
    headerFile << width << " " << height << " " << 1;
    headerFile.close();

    //write to output file
    ofstream outputFile;
    outputFile.open("./Output/"+output_prefix+".raw");
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            outputFile << slices[i][j];
        }
    }
    outputFile.close();
}

int main(int argc, char *argv[]){
    SLDALE003::VolImage volImage;

    string imageBase = argv[1];
    volImage.readImages(imageBase);

    if(argc > 2){
        string currentArg = argv[2];
        string diffArg = "-d";
        string extractArg = "-x";
        string rowExtractArg = "-g";

        /* Check for difference map instruction */
        if(currentArg.compare(diffArg)==0){
            string sliceI = argv[3];
            string sliceJ = argv[4];
            string outfile_preifx = argv[5];
            int sliceI_i = stoi(sliceI);
            int sliceJ_i = stoi(sliceJ);
            volImage.diffmap(sliceI_i, sliceJ_i, outfile_preifx);
        }

         /* Check for extract instruction */
        else if(currentArg.compare(extractArg)==0){
            string slice = argv[3];
            int slice_i = stoi(slice);
            string outfile_prefix = argv[4];
            volImage.extract(slice_i, outfile_prefix);
        }

        else if(currentArg.compare(rowExtractArg)==0){
            cout << "Extra Credit" << endl;
        }
    }

    return 0;
}

