# CSC3022F-Assignment-2

## VolImage.cpp
This class contains all methods for manipulating the slices as well as the main method which deals with the recieving of input instructions. These methods include:

* VolImage() - default constructor 
* ~VolImage() - destructor
* readImages(std::string baseName) - reads in .data and .raw files and builds the internal representation
* diffmap(int sliceI, int sliceJ, std::string output_prefix) - performs a difference map on the i'th and j'th slice of the data and writes the result to an output file
* extract(int sliceId, std::string output_prefix) - retrieves the slice given by the specified index and writes the result to an output file
* extractRow(int rowId, std::string output_prefix) - extracts an image along a particular row across all slices and writes the result to an output file 
* int volImageSize(void) - returns the number of bytes uses to store image data bytes and pointers
* writeOutputFile(unsigned char ** slice, std::string output_prefix, int lengthOutputFile) - writes both the header .data file and the .raw file of the output

## VolImage.h
This class contains all the method calls held in VolImage.cpp

## Makefile
The Makefile compiles and links all necessary files into the volimage.run executable. 

This practical has 3 main tasks including extract ("-x"), difference map ("-d") and extract rows ("-g"). This can be called by changing the run command according to the form:

./volimage "basefile" "operation" "indices" "output file name"

Some examples have been commented out in the Makfile. The main commands include:

* make - compiles files
* make run - runs executable according to specific instruction
* make clean - removes executables

