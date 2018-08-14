/*************************************************************************************/
/*************************************** 2018.3.27 ***********************************/
/*****************************          Jerry Zheng           ************************/
/**************************** Beijing Insititute of Technology ***********************/
/*************************************************************************************/

#include "Eigen/Dense"
#include "iostream"
#include <Eigen/Cholesky>

using namespace std;
using namespace Eigen;

int main()
{
	cout << "Input the size(example:3)" << endl;
	int nN;
	cin >> nN;
	cout << "Input your argumented matrix，size is (n*（n+1)）:" << endl;
	MatrixXf mCoeff(nN, nN);//Unbelievable!!Dynamic Matrix!!
	MatrixXf mArgu(nN, nN+1);
	float nArgu;
	for (int ni = 0; ni < nN; ni++)
	{
		for (int nj = 0; nj <= nN; nj++)
		{
			cin >> nArgu;
			mArgu(ni, nj) = nArgu;
		}
	}//create the argumented matrix
	cout << endl;
	cout << "The argumented matrix is :" << endl;
	cout << mArgu << endl;
	cout << endl;
	for (int ni = 0; ni < nN; ni++)
	{
		for (int nj = 0; nj < nN; nj++)
		{
			mCoeff(ni, nj) = mArgu(ni,nj);
		}
	}//create the coefficient matrix
	cout << "The coefficient matrix is :" << endl;
	cout << mCoeff << endl;
	cout << endl;
	VectorXf B(nN);
	for (int ni = 0; ni < nN; ni++)
	{
		B(ni) = mArgu(ni, nN);
	}//create the b vector
	cout << "The b is :" << endl;
	cout << B << endl;
	cout << endl;
	VectorXf x(nN);
	x = mCoeff.lu().solve(B);
	cout << "The LU solution is :" << endl;
	cout << x << endl;
	system("pause");
	return 0;
}
