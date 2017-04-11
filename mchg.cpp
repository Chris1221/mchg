#include <iostream>
#include <Eigen/Dense>
#include <time.h>
#include "mchg_read_utils.h"

using namespace std;
int main( int argc,
	  char *argv[],
	  char *envp[] )
{
    int count;  
    char* gen = NULL;
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
	"|    	      Multiple Comparrisons          | \n" <<
	"|             in the Human Genome            | \n" <<
	"|   					     | \n" <<
	"|          Website and Quick Start:	     | \n" <<
	"|      https://github.com/Chris1221/mchg     | \n" <<
	"| 				             | \n" <<
	"|            Christpher Cole 2017	     | \n" <<
	"|					     | \n" <<
	"@ ------------------------------------------ @ \n" << "\n";

    time_t current_time;
    char* c_time_string;

    for (count = 1; count < argc; count+=2 )
	if( ! strcmp(argv[count], "--gen") ){
		gen = argv[count+1];
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
	    "    .gen file: \t \t" << gen << "\n" <<
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

    Eigen::MatrixXd test = parse_bed(std::string(gen), 4, 2);

    std::cout << test << std::endl;

}
