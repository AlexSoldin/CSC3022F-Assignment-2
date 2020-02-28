volimage.run: volimage.o
	g++ -o volimage.run VolImage.cpp --std=c++11

volimage.o: VolImage.cpp
	g++ -o volimage.o VolImage.cpp --std=c++11

clean: 
	@rm -f *.o *.run

#	./volimage <basefile> <operation> <indices> <output file>
run: volimage.run
	./volimage brain_mri_raws/MRI -d 66 67 outputDiffMap
#	./volimage brain_mri_raws/MRI -x 66 outputExtractSlice
#	./volimage brain_mri_raws/MRI -g 6 outputExtractRow