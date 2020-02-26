#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ios>

#include "VolImage.h"

using namespace std;

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