#include "stdafx.h"
#include "matrix.h"


_MATRIX CMyMatrix::CMyMatrix()
{
	nCol = 0;
	nRow = 0;
	pMatrix = NULL;
}
_MATRIX CMyMatrix::CMyMatrix(unsigned int row, unsigned int col, double value)
{
	nCol = col;
	nRow = row;

	pMatrix = new double [nRow * nCol];
	if(pMatrix != NULL)
	{
		for(unsigned int i = 0; i < nRow * nCol; i++)
		{	
			pMatrix[i] = value;
		}
	}
}


_MATRIX CMyMatrix::CMyMatrix(const CMyMatrix &source)
{
	if(this != &source)
	{
		nRow = source.nRow;
		nCol = source.nCol;

		pMatrix = new double [nRow * nCol];
		if(pMatrix != NULL)
		{
			for(unsigned int i = 0; i < nRow * nCol; i++)
			{	
				pMatrix[i] = source.pMatrix[i];
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
		for(unsigned int i = 0; i < nRow * nCol; ++i)
		{
			pMatrix[i] += source.pMatrix[i];
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


_MATRIX void CMyMatrix::Resize(unsigned int row, unsigned int col, double value)
{
	delete []pMatrix;

	nRow = row;
	nCol = col;

	pMatrix = new double [nRow * nCol];
	if(pMatrix != NULL)
	{
		for(unsigned int i = 0; i < nRow * nCol; i++)
		{	
			pMatrix[i] = value;
		}
	}
}


_MATRIX void CMyMatrix::Transposition()
{
	double *temp;
	unsigned int i, j;
	
	temp = new double [nRow * nCol];
	if(temp != NULL)
	{
		for(i = 0; i < nRow * nCol; i++)
		{	
			temp[i] = pMatrix[i];
		}
	}

	nRow += nCol;
	nCol = nRow - nCol;
	nRow = nRow - nCol;
	
	for(i = 0; i < nRow; i++)
	{	
		for(j = 0; j < nCol; ++j)
		{
			pMatrix[i * nCol + j] = temp[j * nRow + i];
		}
	}
	delete []temp;
}