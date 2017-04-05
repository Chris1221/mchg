all: clean mchg

mchg: mchg.cpp
	g++ mchg.cpp -o mchg -O2 -larmadillo

clean:
	rm -f mchg
