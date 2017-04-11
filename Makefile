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
all: clean mchg
#
#	(clean) Clean the directory:
#		Get rid of intermediary steps
#		and intermediary object files.
#		Prepare for full make
clean:
	rm -f mchg mchg_read_utils.o mchg.o
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
CFLAGS = -I /usr/include/eigen3 
#
# -------------------------------------------
# 		INTERMEDIARY 
#
#	These targets are intermediary steps.
#
#	(mchg_read_utils.o) Read object:
#		Compile functions for reading 
#		genetic files.
mchg_read_utils.o: mchg_read_utils.cpp
	g++ $(CFLAGS) -c $<
#
#	(mchg.o) Object for (main):
#		Compile the main function
mchg.o: mchg.cpp
	g++ $(CFLAGS) -c $<
#
# -------------------------------------------	
#	
#	!!!	MAIN TARGETS	!!!
#
#	These are the main programs that are compilled
#
#	(mchg) Compile the main program
#		This is the main binary output of this program
mchg: mchg_read_utils.o mchg.o
	g++ $(CFLAGS) -o mchg mchg.o mchg_read_utils.o
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
test: clean mchg	
	./mchg --gen data/toy.bed \
		--summary SUMMARY.summary \
		--output OUTPUT.txt
#
# -------------------------------------------------
