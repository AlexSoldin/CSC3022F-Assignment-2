#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ios>

#ifndef _VOLIMAGE_CLASS_H
#define _VOLIMAGE_CLASS_H

namespace SLDALE003{

    class VolImage {
        private: // private members
            int width, height; // width and height of image stack
            std::vector<unsigned char **> slices; // data for each slice, in order
        
        public: // public members
            VolImage(); // default constructor
            ~VolImage(); // destructor

            // populate the object with images in stack and set member variables
            bool readImages(std::string baseName);

            // compute difference map and write out
            void diffmap(int sliceI, int sliceJ, std::string output_prefix);

            // extract slice sliceId and write to output
            void extract(int sliceId, std::string output_prefix);

            // extract row rowId from all slices and write to output
            void extractRow(int rowId, std::string output_prefix);

            // number of bytes uses to store image data bytes and pointers (ignore vector<> container, dims etc)
            int volImageSize(void);

            // method used to write to an output file
            // length integer indicates whether the output file is being written to a length of height or slices.size()
            void writeOutputFile(unsigned char ** slice, std::string output_prefix, int lengthOutputFile);
    };
}

#endif