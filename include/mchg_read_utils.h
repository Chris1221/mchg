#ifndef MCHG_READ_UTIL_H_   /* Include guard */
#define MCHG_READ_UTIL_H_

// Parse a bed file to create a genetic matrix
// 	Requires:
// 	i. The bfile path (appends .bed)
// 	ii. The number of SNPs (found through parse_bim)
// 	iii. The number of individuals (found through parse_fam)
Eigen::MatrixXd parse_bed( std::string input, int n_snp, int n_id);
int parse_fam ( std::string input );
int parse_bim ( std::string input );

#endif 
