#include <Eigen/Dense>

Eigen::VectorXf calculate_maf ( Eigen::MatrixXd genMat ) {

	// The matrix is SNPs x IDs so SNPs on the rows and IDs on the columns
	// So take the sum of each row and divide it by the number of columns
	
	Eigen::VectorXf maf(genMat.rows());

	for( int snp = 0; snp < genMat.rows(); snp++){
		maf(snp) = genMat.row(snp).sum() / (2*genMat.cols());
	}	

	return maf;

}
