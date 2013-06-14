
#ifdef _MATRIX_H_INCLUDE
#define _MATRIX __declspec(dllexport)
#else
#define _MATRIX __declspec(dllimport)
#endif

class CMyMatrix
{
public:
	_MATRIX CMyMatrix();
	_MATRIX CMyMatrix(unsigned int row, unsigned int col, double);
	_MATRIX CMyMatrix(const CMyMatrix &source);
	_MATRIX virtual ~CMyMatrix();
	_MATRIX void Add(const CMyMatrix &source);
	_MATRIX unsigned int Row();
	_MATRIX unsigned int Col();
	_MATRIX void Resize(unsigned int row = 10, unsigned int col = 10, double value = 3);
	_MATRIX void Transposition();
	_MATRIX const CMyMatrix operator+(const CMyMatrix &source);
	_MATRIX const CMyMatrix operator+(double value);
	_MATRIX const CMyMatrix operator-(const CMyMatrix &source);
	_MATRIX const CMyMatrix operator-(double value);
	_MATRIX CMyMatrix & operator=(const CMyMatrix &source);
	_MATRIX CMyMatrix & operator=(double value);
	_MATRIX bool operator==(const CMyMatrix &source);
	_MATRIX bool operator==(double value);
	_MATRIX bool operator!=(const CMyMatrix &source);
	_MATRIX bool operator!=(double value);
	_MATRIX const CMyMatrix operator*(const CMyMatrix &source);
	_MATRIX const CMyMatrix operator*(double value);
	_MATRIX double get(unsigned int row, unsigned int col);
	_MATRIX void set(unsigned int row, unsigned int col, double value);
private:
	double *pMatrix;
	unsigned int nRow;
	unsigned int nCol;
};