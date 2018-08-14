/**************************    Least Square   ************************************/
/******************************Jerry Zheng****************************************/
/*********************************************************************************/
#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

//SumXcalculate Σ(x[nvec_iter])^nexpx
//nexpx is the highest times of polynomials
double SumX(int nexpx,vector<double> Vnum)
{
	double dSumX = 0.0;
	for (int nvec_iter = 0; nvec_iter < size(Vnum); nvec_iter++)
	{
		dSumX += pow(Vnum[nvec_iter], nexpx);
	}
	return dSumX;
}

//SumY:calculate Σ(y[nvec_iter])
double SumY(vector<double> Vnum)
{
	double dSumY = 0.0;
	for (int nvec_iter = 0; nvec_iter < size(Vnum); nvec_iter++)
	{
		dSumY += Vnum[nvec_iter];
	}
	return dSumY;
}

//MutilSum:calculate Σ((x[nvec_iter])^nexp*(y[nvec_iter]))
double MutilSum(int nexpx, vector<double> VnumX, vector<double> VnumY)
{
	double dSum_MutilSum = 0.0;
	for (int nvec_iter = 0; nvec_iter < size(VnumX); nvec_iter++)
	{
		dSum_MutilSum += pow(VnumX[nvec_iter], nexpx)*VnumY[nvec_iter];
	}
	return dSum_MutilSum;
}

//Matrix:obtain the argumented matrix
double **Matrix(int nexpx, vector<double> VnumX, vector<double> VnumY)
{
	double **ppMatrix = NULL;
	for (int nScanRow = 0; nScanRow <= nexpx; nScanRow++)
	{
		for (int nScanCol = 0; nScanCol <= nexpx+1; nScanCol++)
		{
			if (nScanCol == nScanRow == 0)
			{
				ppMatrix[nScanRow][nScanCol] = size(VnumX);
			}
			else if (nScanCol == nexpx + 1)//deal with b[i]
			{
				if (nScanRow == 0)
				{
					ppMatrix[nScanRow][nScanCol] = SumY(VnumY);
				}
				else
				{
					ppMatrix[nScanRow][nScanCol] = MutilSum(nScanRow, VnumX, VnumY);
				}
			}
			else
			{
				ppMatrix[nScanRow][nScanCol] = SumX(nScanCol + nScanRow, VnumX);
			}
		}
	}
	return ppMatrix;
}

//CalcMatrix:solve the argumented matrix
double *CalcMatrix(int nexpx, double **ppoint)
{
	double *pxvalue = NULL;//store the coefficients.
	for (int nIndex_Y = 0; nIndex_Y <= nexpx + 1; nIndex_Y++)
	{
		if (ppoint[nIndex_Y][nIndex_Y] != 0)
		{
			for (int nIndex_X = nIndex_Y+1; nIndex_X < nexpx + 1; nIndex_X++)
			{
				double dTimes;
				dTimes = ppoint[nIndex_X][nIndex_Y] / ppoint[nIndex_Y][nIndex_Y];
				for (int nIndex_iter = nIndex_Y; nIndex_iter <= nexpx + 1; nIndex_iter++)
				{
					ppoint[nIndex_X][nIndex_iter] = ppoint[nIndex_X][nIndex_iter] - dTimes * ppoint[nIndex_Y][nIndex_iter];
				}
			}
		}
	}
	/*for (int nbval_x = nexpx; nbval_x >= 0; nbval_x--)
	{
		if (nbval_x == nexpx)
		{
			pxvalue[nexpx] = ppoint[nexpx][nexpx + 1];
		}
		else
		{
			double dTimesTri=ppoint[nexpx-1][nbval_x]/
		}
	}*/ //I can't work it out(just solve a down triangle.But I don't figure
		//it out.)
}


//
int main()
{
	vector<double> Vx;
	vector<double> Vy;
	int nexpx;
	CalcMatrix(nexpx, Matrix(nexpx, Vx, Vy));
	return 0;
}
