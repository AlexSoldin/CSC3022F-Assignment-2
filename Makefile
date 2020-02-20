driver: driver.o
	g++ -o driver driver.cpp --std=c++11

driver.o: driver.cpp
	g++ -o driver.o driver.cpp --std=c++11

clean: 
	@rm -f *.o driver

#run: volimage
#	./volimage <basefile> <operation> <indices> <output file>
# e.g.	./volimage brain_mri_raws/MRI -x 66 output
