#include <iostream>
#include <fstream>
//#include <cmath>
#include <Eigen/Dense>
//#include "mchg_read_utils.h"

// Reading in binary gen file


Eigen::MatrixXd parse_bed ( std::string input, // The file path and prefix to the .bed file
		     int n_snp, // The number of SNPs (found by parse_bim() ) 
		     int n_id // The number of people (found by parse_fam() )
		    ) 
	{
	using namespace std;
	// Define some counters
	int count = 0; // Which byte are we on
	int id = 0; // Number of SNP so far (if snp hits n then we need to go back down again)
	//arma::uword n_u = n; // unsigned n, used for constructing matrix
	int which_snp = 0; // unsigned SNP

	// Make the output matrix	
	Eigen::MatrixXd results(n_snp, n_id); // maybe have to convert to unsigned
	//resuts.fill(0);
	
	// Def the stream
	std::ifstream in(input.c_str(), std::ios::binary);

	// Init the charcater and open the stream
	char c;
	while (in.get(c)) {
	
		char mask = 1;
		char bits[8];

		for (int i = 0; i < 8; i++) {
			bits[i] = (c & (mask << i)) != 0;
		}

		// Read in, incriment count
		// If the count is less than 4 then its still in either
		// the magic number portion or the format
		//	
		// Will probably want to check the format portion 
		// at some point.
		count++;
		if(count < 4) continue;
	
		
		int gen;
		// Convert to gen and add in to results vector.
		for(int i = 0; i < 8; i+=2){
			
			
			// ! -------------------- ! //
			//	CHECK SNP COUNT     //
			// ! -------------------- ! //		
			
			// This effectivly checks if the number of SNPs has hit the maximum
			// but does not check if it's used up within a byte
			//
			// It worked before becuase it was symetric 
			// 	Same number of snps and people.
			// 	so they would be used up at the same time.
			//
			// To do this: 
			// 	i. maybe while snp  < individual

			if( (id - n_id) == 0) {
				id = 0;
				which_snp = which_snp+1;
				break;
			} // If hit the number of SNPs then skip the rest of the byte	
			// Find gen coding
			if( (bits[i] == 0) && (bits[i+1] == 0) ) {
				gen = 0;
			} else if( (bits[i] == 0) && (bits[i+1] == 1) ) {
				gen = 1; // check
			} else if( (bits[i] == 1) && (bits[i+1] == 0) ) {
				gen = 0; //missing is the same as 0
			} else if( (bits[i] == 1) && (bits[i+1] == 1) ) {
				gen = 2;
			} else {
				throw std::invalid_argument( "Non binary input or improper input." );
			}
		
			results(which_snp, id) = gen;

			
			id++; // On first snp counter is going to be 1	
				
	
		}	
	
	}
	return results;
}




