#include <iostream>
#include <armadillo>

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

    cout << pc << endl;
}
