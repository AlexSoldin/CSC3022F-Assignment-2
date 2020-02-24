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

bool readImages(string baseName){
    cout << "Successfully called readImages" << endl;
}

void diffmap(int sliceI, int sliceJ, string output_prefix){
    cout << "Successfully called diffmap" << endl;
}

void extract(int sliceId, string output_prefix){
    cout << "Successfully called extract" << endl;
}

int volImageSize(void){
    cout << "Successfully called volImageSize" << endl;
}

