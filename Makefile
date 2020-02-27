volimage: volimage.o
	g++ -o volimage VolImage.cpp --std=c++11

volimage.o: VolImage.cpp
	g++ -o volimage.o VolImage.cpp --std=c++11

clean: 
	@rm -f *.o *.run

#	./volimage <basefile> <operation> <indices> <output file>
run: volimage
#	./volimage brain_mri_raws/MRI -d 66 67 output
	./volimage brain_mri_raws/MRI -x 66 output