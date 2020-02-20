volimage: volimage.o
	g++ -o volimage volimage.cpp --std=c++11

volimage.o: volimage.cpp
	g++ -o volimage.o volimage.cpp --std=c++11

clean: 
	@rm -f *.o volimage

#run: volimage
#	./volimage <basefile> <operation> <indices> <output file>
# e.g.	./volimage brain_mri_raws/MRI -x 66 output
