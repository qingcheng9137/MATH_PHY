/*************************************************************************************/
/*************************************** 2018.3.26 ***********************************/
/*****************************          Jerry Zheng           ************************/
/**************************** Beijing Insititute of Technology ***********************/
/*************************************************************************************/

//Solve a matrix which is n by n

#include<iostream>
#include "vector"

using namespace std;


void gaussin(double **aArgu, double *ab, int nN)
{
	//判断能否用高斯消元法，如果矩阵主对角线上有0元素存在是不能用的
	for (int ni = 0; ni < nN; ni++)
		if (aArgu[ni][ni] == 0)
		{
			cout << "can't use gaussin method" << endl;
			break;
		}

	int ni, nj, nk;
	double *ac = new double[nN];    //存储初等行变换的系数，用于行的相减
					//消元的整个过程如下，总共nN-1次消元过程。
	for (nk = 0; nk < nN - 1; nk++)
	{
		//求出第nK次初等行变换的系数
		for (ni = nk + 1; ni < nN; ni++)
			ac[ni] = aArgu[ni][nk] / aArgu[nk][nk];

		//第nK次的消元计算
		for (ni = nk + 1; ni < nN; ni++)
		{
			for (nj = 0; nj < nN; nj++)
			{
				aArgu[ni][nj] = aArgu[ni][nj] - ac[ni] * aArgu[nk][nj];
			}
			ab[ni] = ab[ni] - ac[ni] * ab[nk];
		}
	}

	//解的存储数组
	double *ax = new double[nN];
	//先计算出最后一个未知数；
	ax[nN - 1] = ab[nN - 1] / aArgu[nN - 1][nN - 1];
	//求出每个未知数的值
	for (ni = nN - 2; ni >= 0; ni--)
	{
		double dsum = 0;
		for (nj = ni + 1; nj < nN; nj++)
		{
			dsum += aArgu[ni][nj] * ax[nj];
		}
		ax[ni] = (ab[ni] - dsum) / aArgu[ni][ni];
	}

	cout << " the solution of the equations is:" << endl;
	cout << endl;
	for (ni = 0; ni < nN; ni++)
	{
		cout << "x" << ni + 1 << "=" << ax[ni] << endl;
	}
	delete[]ac;
	delete[]ax;

}
int main()
{
	cout << "Input the size of your coefficient matrix(example:3) " << endl;
	int nN;
	cin >> nN;
	//double aArgu[nN][nN];
	//double ab[nN];
	double **array = new double *[nN];
	for (int ni = 0; ni < nN; ni++)
	{
		array[ni] = new double[nN+1];
	}//new a two dimensions array
	double *ab = new double[nN];//new a one dimension array
	cout << "Input your argumented matrix" << endl;
	for (int nIndex1 = 0; nIndex1 < nN; nIndex1++)
	{
		for (int nIndex2 = 0; nIndex2 <= nN; nIndex2++)
		{
			cin >> array[nIndex1][nIndex2];
		}
	}
	for (int nIndexb = 0; nIndexb < nN; nIndexb++)
	{
		ab[nIndexb] = array[nIndexb][nN];
	}
	gaussin(array, ab, nN);
	for (int ni = 0; ni < nN; ni++)
	{
		delete[] array[ni];
		delete[] array;
	}
	delete[] ab;
	return 0;
}
