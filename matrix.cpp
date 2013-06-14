#include "stdafx.h"
#include "matrix.h"

_MATRIX CMyMatrix::CMyMatrix(const double init, const unsigned int row, const unsigned int col)
{
	nCol = col;
	nRow = row;

	pMatrix = new double *[nRow];
	if(pMatrix != NULL)
	{
		for(unsigned int i = 0; i < nRow; i++)
		{
			pMatrix[i] = new double [nCol];
			if(pMatrix[i] != NULL)
			{
				for(unsigned int j = 0; j < nCol; ++j)
				{
					pMatrix[i][j] = init;
				}
			}
		}
	}
}


_MATRIX CMyMatrix::CMyMatrix(const CMyMatrix &source)
{
	if(this != &source)
	{
		nRow = source.nRow;
		nCol = source.nCol;

		pMatrix = new double *[nRow];
		if(pMatrix != NULL)
		{
			for(unsigned int i = 0; i < nRow; ++i)
			{
				pMatrix[i] = new double [nCol];
				if(pMatrix[i] != NULL)
				{
					for(unsigned int j = 0; j < nCol; ++j)
					{
						pMatrix[i][j] = source.pMatrix[i][j];
					}
				}
			}
		}
	}
}


_MATRIX CMyMatrix::~CMyMatrix()
{
	if(pMatrix != NULL)
	{
		delete []pMatrix;
	}
}


_MATRIX void CMyMatrix::Add(const CMyMatrix &source)
{
	if(pMatrix != NULL && nRow == source.nRow && nCol == source.nCol)
	{
		for(unsigned int i = 0; i < nRow; ++i)
		{
			for(unsigned int j = 0; j < nCol; ++j)
			{
				pMatrix[i][j] += source.pMatrix[i][j];
			}
		}
	}
}


_MATRIX unsigned int CMyMatrix::Col()
{
	return nCol;
}


_MATRIX unsigned int CMyMatrix::Row()
{
	return nRow;
}


_MATRIX void CMyMatrix::Resize(const double change, const unsigned int row, const unsigned int col)
{
	delete []pMatrix;

	nRow = row;
	nCol = col;

	pMatrix = new double *[nRow];
	if(pMatrix != NULL)
	{
		for(unsigned int i = 0; i < nRow; i++)
		{
			pMatrix[i] = new double [nCol];
			if(pMatrix[i] != NULL)
			{
				for(unsigned int j = 0; j < nCol; ++j)
				{
					pMatrix[i][j] = change;
				}
			}
		}
	}
}


_MATRIX void CMyMatrix::Trans()
{
	double **temp;

	temp = new double *[nCol];
	if(temp != NULL)
	{
		for(unsigned int i = 0; i < nCol; i++)
		{
			temp[i] = new double [nRow];
			if(temp[i] != NULL)
			{
				for(unsigned int j = 0; j < nRow; ++j)
				{
					temp[i][j] = pMatrix[j][i];
				}
			}
		}
	}

	delete []pMatrix;

	nRow += nCol;
	nCol = nRow - nCol;
	nRow = nRow - nCol;

	pMatrix = new double *[nRow];
	if(pMatrix != NULL)
	{
		for(unsigned int i = 0; i < nRow; i++)
		{
			pMatrix[i] = new double [nCol];
			if(pMatrix[i] != NULL)
			{
				for(unsigned int j = 0; j < nCol; ++j)
				{
					pMatrix[i][j] = temp[i][j];
				}
			}
		}
	}

	delete []temp;
}