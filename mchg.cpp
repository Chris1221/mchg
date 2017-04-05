#include <iostream>
#include <armadillo>

using namespace std;
int main( int argc,
	  char *argv[],
	  char *envp[] )
{
    int count;  
    char* gen = NULL;
  
    // Display each command-line argument.  
    cout << "\nCommand-line arguments:\n";  
    for( count = 0; count < argc; count++ )  
         cout << "  argv[" << count << "]   "  
	            << argv[count] << "\n";

    // Parse command line arguements to variables

    for (count = 0; count < argc; count++ )
	//char arg = argv[count];	
	//std::string str(arg);
	//std::string args( argv[count] );
	char* dat = argv[count];
    	char* argument = "--gen";
	if(dat == argument)
		cout << argv[count];


}
