volimage: volimage.o
	g++ -o volimage VolImage.cpp --std=c++11

volimage.o: VolImage.cpp
	g++ -o volimage.o VolImage.cpp --std=c++11

clean: 
	@rm -f *.o *.run

run: volimage
	./volimage brain_mri_raws/MRI

#	./volimage <basefile> <operation> <indices> <output file>
# e.g.	./volimage brain_mri_raws/MRI -x 66 output