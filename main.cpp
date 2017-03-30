#include <iostream>
#include <armadillo>

using namespace std;
int main( int argc,
	  char *argv[],
	  char *envp[] )
{
	    int count;  
  
    // Display each command-line argument.  
    cout << "\nCommand-line arguments:\n";  
    for( count = 0; count < argc; count++ )  
         cout << "  argv[" << count << "]   "  
                << argv[count] << "\n";  
}
