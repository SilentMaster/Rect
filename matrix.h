
#ifdef _MATRIX_H_INCLUDE
#define _MATRIX __declspec(dllexport)
#else
#define _MATRIX __declspec(dllimport)
#endif

class CMyMatrix
{
public:
	_MATRIX CMyMatrix(const double init = 5, const unsigned int row = 10, const unsigned int col = 10);
	_MATRIX CMyMatrix(const CMyMatrix &);
	_MATRIX ~CMyMatrix();
	_MATRIX void Add(const CMyMatrix &);
	_MATRIX unsigned int Row();
	_MATRIX unsigned int Col();
	_MATRIX void Resize(const double change = 3, const unsigned int row = 10, const unsigned int col = 10);
	_MATRIX void Trans();
private:
	double **pMatrix;
	unsigned int nRow;
	unsigned int nCol;
};