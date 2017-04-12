# Multiple Correction in the Human Genome (MCHG) 
# 
# 	Definition of targets directly above them
# 
# ----------------------------------------------
#
# 		PHONY TARGETS
# 	
# 	These targets accomplish goals
#
# 	(all) Default target: 
# 		By default when make is invoked
# 		clean the directory of all output and
# 		make the binary
all: clean bin/mchg
#
#	(clean) Clean the directory:
#		Get rid of intermediary steps
#		and intermediary object files.
#		Prepare for full make
clean:
	rm -rf build/
#
#	(git) Prepare the repo for committing:
#		First clean then add in all the files.
git: clean
	git add -A
#
# --------------------------------------------
#
# 		FLAG TARGETS
#
#	These flags are for compile flags and various other reusable flags.
#
# 	(CFLAGS) Compile Flags:
# 		Include the eigen library
# 		This target is DYNAMIC.
CFLAGS = -I lib/eigen3 
#
# -------------------------------------------
# 		INTERMEDIARY 
#
#	These targets are intermediary steps.
#
#	(mchg_read_utils.o) Read object:
#		Compile functions for reading 
#		genetic files.
build/mchg_read_utils.o: src/mchg_read_utils.cpp
	mkdir -p build/
	g++ $(CFLAGS) -c $< -o $@
#
#	(mchg.o) Object for (main):
#		Compile the main function
build/mchg.o: src/mchg.cpp
	mkdir -p build/
	g++ $(CFLAGS) -c $< -o $@
#
#	(mchg_calculation_utils.o)
#		Compiles calculation helper functions
build/mchg_calculation_utils.o: src/mchg_calculation_utils.cpp
	mkdir -p build/
	g++ $(CFLAGS) -c $< -o $@

# -------------------------------------------	
#	
#	!!!	MAIN TARGETS	!!!
#
#	These are the main programs that are compilled
#
#	(mchg) Compile the main program
#		This is the main binary output of this program
bin/mchg: build/mchg_read_utils.o build/mchg_calculation_utils.o build/mchg.o
	g++ $(CFLAGS) -o bin/mchg $^
#
# ----------------------------------------------
# 		TEST TARGETS
#
# 	These are targets for testing the program
#
# 	(data/toy.*) Create the test data 
# 		This is important because I manually change the
# 		ped and map to try different things.
data/toy.bed data/toy.bim data/toy.fam: data/toy.ped data/toy.map
	plink --file data/toy --make-bed --out data/toy
#
#	(test): Test the function 
#		This is the test function to make sure everything works.
#
test: clean bin/mchg	
	bin/mchg --bfile data/toy \
		--summary SUMMARY.summary \
		--output OUTPUT.txt
#
# -------------------------------------------------
