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


_MATRIX CMyMatrix & CMyMatrix::operator=(const CMyMatrix &a)
{
	unsigned int i;
	if(nRow != a.nRow || nCol != a.nCol)
	{
		printf("Unmatch CMyMatrix!\n");
		return *this;
	}
	for(i = 0; i < nRow * nCol; i++)
	{
		pMatrix[i] = a.pMatrix[i];
	}
	return *this;
}


_MATRIX CMyMatrix & CMyMatrix::operator=(double value)
{
	unsigned int i;
	pMatrix = new double[nRow * nCol];
	for(i = 0; i < nRow * nCol; i++)
	{
		pMatrix[i] = value;
	}
	return *this;
}
	

//重载+运算符，要求两个矩阵的大小相同
_MATRIX const CMyMatrix CMyMatrix::operator+(const CMyMatrix &a)
{
	unsigned int i;
	if(nRow != a.nRow || nCol != a.nCol)
	{
		printf("Unmatch CMyMatrix!\n");
		return *this;
	}
	
	for(i = 0; i < nRow * nCol; i++)
	{
		pMatrix[i] += a.pMatrix[i];
	}
	return *this;
}


_MATRIX const CMyMatrix CMyMatrix::operator+(double value)
{
	unsigned int i;
	for(i = 0; i < nRow * nCol; i++)
	{
		pMatrix[i] += value;
	}
	return *this;
}


//重载-运算符，要求两个矩阵的大小相同
_MATRIX const CMyMatrix CMyMatrix::operator-(const CMyMatrix &a)
{
	unsigned int i;
	if(nRow != a.nRow || nCol != a.nCol)
	{
		printf("Unmatch CMyMatrix!\n");
		return *this;
	}
	
	for(i = 0; i < nRow * nCol; i++)
	{
		pMatrix[i] = pMatrix[i] - a.pMatrix[i];
	}
	return *this;
}


_MATRIX const CMyMatrix CMyMatrix::operator-(double value)
{
	unsigned int i;
	for(i = 0; i < nRow * nCol; i++)
	{
		pMatrix[i] -= value;
	}
	return *this;
}

	
//重载*运算符，要求矩阵a的列数等于b的行数
_MATRIX const CMyMatrix CMyMatrix::operator*(const CMyMatrix &a)
{
	unsigned int i, j, k;
	double tmp;
	if(nCol != a.nRow)
	{
		printf("Unmatch CMyMatrix!\n");
		return *this;
	}
	
	CMyMatrix temp(nRow, a.nCol, 0);

	for(i = 0; i < nRow; i++)
	{
		for(j = 0; j < a.nCol; j++)
		{
			tmp = 0;
			for(k = 0; k < a.nRow; k++)
			{
				tmp += pMatrix[i * nCol + k] * a.pMatrix[k * a.nCol + j];
			}
			temp.pMatrix[i * a.nCol + j] = tmp;
		}
	}
	return temp;
}


_MATRIX const CMyMatrix CMyMatrix::operator*(double value)
{
	unsigned int i;
	for(i = 0; i < nRow * nCol; i++)
	{
		pMatrix[i] *= value;
	}
	return *this;
}
	
///重载==运算符，要求两个矩阵的大小相同
_MATRIX bool CMyMatrix::operator==(const CMyMatrix &a)
{
	unsigned int i;
	if(nRow != a.nRow || nCol != a.nCol)
	{
		printf("Unmatch CMyMatrix!\n");
		return false;
	}
	for(i = 0; i < nRow * nCol; i++)
	{
		if(this->pMatrix[i] != a.pMatrix[i])
		{
			return false;
		}
	}
	return true;
}


_MATRIX bool CMyMatrix::operator==(double value)
{
	unsigned int i;
	for(i = 0; i < nRow * nCol; i++)
	{
		pMatrix[i] != value;
		return false;
	}
	return true;
}


_MATRIX bool CMyMatrix::operator!=(const CMyMatrix &source)
{
	unsigned int i;
	if(nRow != source.nRow || nCol != source.nCol)
	{
		printf("Unmatch CMyMatrix!\n");
		return true;
	}
	else
	{
		for(i = 0; i < nRow * nCol; i++)
		{
			pMatrix[i] == source.pMatrix[i];
			return false;
		}
		return true;
	}
}


_MATRIX bool CMyMatrix::operator!=(double value)
{
	unsigned int i;
	for(i = 0; i < nRow * nCol; i++)
	{
		pMatrix[i] == value;
		return false;
	}
	return true;
}
	

_MATRIX double CMyMatrix::get(unsigned int row, unsigned int col)
{
	double value;
	if (row > nRow || col > nCol)
	{
		return -1;
	}
	else
	{
		value = pMatrix[row * nCol +col];
		return value;
	}
}


_MATRIX void CMyMatrix::set(unsigned int row, unsigned int col, double value)
{
	if (row > nRow || col > nCol)
	{
	}
	else
	{
		pMatrix[row * nCol +col] = value;
	}
}
