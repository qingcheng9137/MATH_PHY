/*************************************************************************************/
/*************************************** 2018.3.28 ***********************************/
/*****************************          Jerry Zheng           ************************/
/**************************** Beijing Insititute of Technology ***********************/
/*************************************************************************************/

//Solve a matrix which is n by n with a two_dimension vector

#include<iostream>
#include "vector"

using namespace std;


void gaussin(vector<vector<double>>&vAUG_MATRIX, vector<double>&vB_MATRIX, int nN)
{
	//判断能否用高斯消元法，如果矩阵主对角线上有0元素存在是不能用的
	for (int ni = 0; ni < nN; ni++)
		if (vAUG_MATRIX[ni][ni] == 0)
		{
			cout << "can't use gaussin method" << endl;
			break;
		}

	int ni, nj, nk;
	vector<double>vAC_MATRIX(nN, 0);   //存储初等行变换的系数，用于行的相减
									//消元的整个过程如下，总共nN-1次消元过程。
	for (nk = 0; nk < nN - 1; nk++)
	{
		//求出第nK次初等行变换的系数
		for (ni = nk + 1; ni < nN; ni++)
			vAC_MATRIX[ni] = vAUG_MATRIX[ni][nk] / vAUG_MATRIX[nk][nk];

		//第nK次的消元计算
		for (ni = nk + 1; ni < nN; ni++)
		{
			for (nj = 0; nj < nN; nj++)
			{
				vAUG_MATRIX[ni][nj] = vAUG_MATRIX[ni][nj] - vAC_MATRIX[ni] * vAUG_MATRIX[nk][nj];
			}
			vB_MATRIX[ni] = vB_MATRIX[ni] - vAC_MATRIX[ni] * vB_MATRIX[nk];
		}
	}

	//解的存储数组
	vector<double>vAX_MATRIX(nN, 0);
	//先计算出最后一个未知数；
	vAX_MATRIX[nN - 1] = vB_MATRIX[nN - 1] / vAUG_MATRIX[nN - 1][nN - 1];
	//求出每个未知数的值
	for (ni = nN - 2; ni >= 0; ni--)
	{
		double dsum = 0;
		for (nj = ni + 1; nj < nN; nj++)
		{
			dsum += vAUG_MATRIX[ni][nj] * vAX_MATRIX[nj];
		}
		vAX_MATRIX[ni] = (vB_MATRIX[ni] - dsum) / vAUG_MATRIX[ni][ni];
	}

	cout << " the solution of the equations is:" << endl;
	cout << endl;
	for (ni = 0; ni < nN; ni++)
	{
		cout << "x" << ni + 1 << "=" << vAX_MATRIX[ni] << endl;
	}
	//delete[]ac;
	//delete[]ax;

}
int main()
{
	cout << "Input the size of your coefficient matrix(example:3) " << endl;
	int nN;
	cin >> nN;
	//double aArgu[nN][nN];
	//double ab[nN];
	//double **array = new double *[nN];
	//for (int ni = 0; ni < nN; ni++)
	//{
	//	array[ni] = new double[nN + 1];
	//}//new a two dimensions array
	//double *ab = new double[nN];//new a one dimension array
	vector<vector <double> > vAUG_MATRIX(nN, vector<double>(nN + 1, 0));
	vector<double> vB_MATRIX(nN, 0);
	cout << "Input your augmented matrix" << endl;
	for (int nIndex1 = 0; nIndex1 < nN; nIndex1++)
	{
		for (int nIndex2 = 0; nIndex2 <= nN; nIndex2++)
		{
			cin >> vAUG_MATRIX[nIndex1][nIndex2];
		}
	}
	for (int nIndexb = 0; nIndexb < nN; nIndexb++)
	{
		vB_MATRIX[nIndexb] = vAUG_MATRIX[nIndexb][nN];
	}
	gaussin(vAUG_MATRIX, vB_MATRIX, nN);
	//for (int ni = 0; ni < nN; ni++)
	//{
	//	delete[] array[ni];
	//	delete[] array;
	//}
	//delete[] ab;
	system("pause");
	return 0;

}
