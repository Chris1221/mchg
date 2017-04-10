all: clean mchg

CFLAGS = -I /usr/include/eigen3 


mchg_read_utils.o: mchg_read_utils.cpp
	g++ $(CFLAGS) -c $<

mchg.o: mchg.cpp
	g++ $(CFLAGS) -c $<

mchg: mchg_read_utils.o mchg.o
	g++ $(CFLAGS) -o mchg mchg.o mchg_read_utils.o
	
	
clean:
	rm -f mchg mchg_read_utils.o mchg.o

test:
	./mchg --gen SAMPLE_GEN.gen \
		--summary SUMMARY.summary \
		--output OUTPUT.txt
