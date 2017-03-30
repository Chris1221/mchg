all: mchg

mchg: mchg.cpp
	g++ mchg.cpp -o mchg -O2 -armadillo
