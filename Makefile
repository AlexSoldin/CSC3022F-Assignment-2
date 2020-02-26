driver.run: driver.o
	g++ -o driver.run driver.cpp --std=c++11

driver.o: driver.cpp
	g++ -o driver.o driver.cpp --std=c++11

clean: 
	@rm -f *.o *.run

run: driver.run
	./driver.run brain_mri_raws/MRI

#	./driver <basefile> <operation> <indices> <output file>
# e.g.	./driver brain_mri_raws/MRI -x 66 output