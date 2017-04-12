#include <iostream>
#include <Eigen/Dense>
#include <time.h>
#include "../include/mchg_read_utils.h"
#include "../include/mchg_calculation_utils.h"

using namespace std;
int main( int argc,
	  char *argv[],
	  char *envp[] )
{
    int count;  
    char* bfile = NULL;
    char* summary = NULL;
    char* output = NULL;
    double h2 = 0.5;
    double pc = 0.5;
    double pnc = 0.5;
    double nc = 0.5;
    bool maf = false; 
    double maf_range = 0;
    int nrep = 1; 
    
    cout << 
	"@ ------------------------------------------ @ \n" <<
	"|  				             | \n" <<
	"|    	      Multiple Comparisons           | \n" <<
	"|             in the Human Genome            | \n" <<
	"|   					     | \n" <<
	"|          Website and Quick Start:	     | \n" <<
	"|      https://github.com/Chris1221/mchg     | \n" <<
	"| 				             | \n" <<
	"|            Christpher Cole 2017	     | \n" <<
	"| 				             | \n" <<
	"|  !--------------------------------------!  | \n" <<
	"|         April 2017     |   Alpha 1.0       | \n" <<
	"@ ------------------------------------------ @ \n" << "\n";

    time_t current_time;
    char* c_time_string;

    for (count = 1; count < argc; count+=2 )
	if( ! strcmp(argv[count], "--bfile") ){
		bfile = argv[count+1];
	}else if( ! strcmp(argv[count], "--summary") ){
		summary = argv[count+1];
	}else if( ! strcmp(argv[count], "--output") ){
		output = argv[count+1];
	}else if( ! strcmp(argv[count], "--h2") ){
		h2 = strtod(argv[count+1], NULL);	
	}else if( ! strcmp(argv[count], "--pc") ){
		pc = strtod(argv[count+1], NULL);
	}else if( ! strcmp(argv[count], "--pnc") ){
		pnc = strtod(argv[count+1], NULL);
	}else if( ! strcmp(argv[count], "--nc") ){
		nc = strtod(argv[count+1], NULL);
	}else if( ! strcmp(argv[count], "--maf") ){
		maf = strcmp(argv[count+1],"true");
	}else if( ! strcmp(argv[count], "--maf-range") ){
		maf_range = strtod(argv[count+1], NULL);
	}else if( ! strcmp(argv[count], "--nrep") ){
		nrep = strtod(argv[count+1], NULL);
	} else {
		cout << "\n" << argv[count] << " is an unrecognized tag, please read the documentation for more details." << "\n";
		exit(EXIT_FAILURE);
	}

    cout << "Input options: " << "\n" <<
	    "    Plink file: \t" << bfile << "\n" <<
	    "    .summary file: \t" << summary << "\n\n" <<
	    "    Heritability: \t" << h2 << "\n" <<
	    "    % Causal: \t\t" << pc << "\n" <<
    	    "    % Non-Causal: \t" << pnc << "\n" <<
	    "    Number of Causal: \t" << nc << "\n\n" <<
	    "    MAF: \t\t" << maf << "\n" <<
	    "    MAF Range: \t\t" << maf_range << "\n\n" <<
	    "    # Permuations: \t" << nrep << "\n\n" <<
	    "    Output File: \t" << output << "\n\n";
	
    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    cout << "Analysis started at " << c_time_string << "\n";

    // Calculate the Number of people from the number of
    // 		lines in the .fam file
    //
    // And the number of SNPs from the .bim file
    int n_id = parse_fam ( std::string(bfile) );
    int n_snp = parse_bim ( std::string(bfile) );

    // Read in the binary genetic file into a matrix
    // 		Use this for regression going forward.
    Eigen::MatrixXd genMat = parse_bed(std::string(bfile), n_snp, n_id );

    // Echo out the genetic matrix 
    // 		But don't do this when it gets bigger.
    std::cout << "\tGenetic data (SNP x ID):" << std::endl;
    std::cout << genMat << std::endl;

    // Im just demoing this
    Eigen::VectorXf mafVec = calculate_maf ( genMat ); 

    std::cout << "\n\tMinor Allele Frequency Vector: \n" << std::endl;
    std::cout << mafVec << std::endl;
}
