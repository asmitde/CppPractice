// Header file:	Matrix
// Author:	Asmit De

#include <iostream>
#include <string>
using namespace std;

class MatrixException
{
public:
	enum errtype { __DIM_NOT_EQUAL, __ROW_COL_NOT_EQUAL, __NOT_SQUARE, __DIVISION_BY_ZERO };

	string error;
	MatrixException(errtype et)
	{
		if(et == __DIM_NOT_EQUAL)
			error = "\aError: Dimension of matrices are not equal";
		else if(et == __ROW_COL_NOT_EQUAL)
			error = "\aError: Number of columns in first matrix is not equal to the number of rows in second matrix";
		else if(et == __NOT_SQUARE)
			error = "\aError: Matrix is not a square matrix";
		else
			error ="\aError: Division by zero";
	}
};

template <class MT> class Matrix
{
	int row, col;

public:
	MT **_matrix;

	Matrix(int x);
	Matrix(int x, int y);
	Matrix(const Matrix<MT> &cmatrix);
	~Matrix();

	Matrix<MT> operator=(Matrix<MT> &mat);

	Matrix<MT> operator+(Matrix<MT> &mat);
	Matrix<MT> operator+(MT factor);

	Matrix<MT> operator-(Matrix<MT> &mat);
	Matrix<MT> operator-(MT factor);

	Matrix<MT> operator*(Matrix<MT> &mat);
	Matrix<MT> operator*(MT factor);

	Matrix<MT> operator/(MT factor);


	Matrix<MT> transpose();
	Matrix<MT> inverse();
	Matrix<MT> adjoint();
	Matrix<MT> minor(int r, int c);
	MT determinant();

	bool isSquare();
	bool isSymmetric();
	bool isSkewSymmetric();
	bool isIdentity();
	bool isDiagonal();
	bool isUpperTriangular();
	bool isLowerTriangular();


	template <class MT> friend ostream &operator<<(ostream &mout, Matrix<MT> &mat);
	template <class MT> friend istream &operator>>(istream &min, Matrix<MT> &mat);
};

template <class MT> Matrix<MT>::Matrix(int x = 1)
{
	row = col = x;

	_matrix = new MT*[row];

	for(int i = 0; i < row; i++)
		_matrix[i] = new MT[col];
}

template <class MT> Matrix<MT>::Matrix(int x, int y)
{
	row = x;
	col = y;

	_matrix = new MT*[row];

	for(int i = 0; i < row; i++)
		_matrix[i] = new MT[col];
}

template <class MT> Matrix<MT>::Matrix(const Matrix<MT> &cmatrix)
{
	row = cmatrix.row;
	col = cmatrix.col;

	_matrix = new MT*[cmatrix.row];
		
	for(int i = 0; i < cmatrix.row; i++)
		_matrix[i] = new MT[cmatrix.col];

	for(int i = 0; i < cmatrix.row; i++)
		for(int j = 0; j < cmatrix.col; j++)
			_matrix[i][j] = cmatrix._matrix[i][j];
}

template <class MT> Matrix<MT>::~Matrix()
{
	for(int i = 0; i < row; i++)
		delete _matrix[i];

	delete _matrix;
}

template <class MT> Matrix<MT> Matrix<MT>::operator=(Matrix<MT> &mat)
{
	if(row != mat.row || col != mat.col)
		throw MatrixException(MatrixException::__DIM_NOT_EQUAL);
	
	for(int i = 0; i < row; i++)
		for(int j = 0; j < mat.col; j++)
			_matrix[i][j] = mat._matrix[i][j];

	return *this;
}

template <class MT> Matrix<MT> Matrix<MT>::operator+(Matrix<MT> &mat)
{
	if(row != mat.row || col != mat.col)
		throw MatrixException(MatrixException::__DIM_NOT_EQUAL);
	
	Matrix<MT> msum(row, col);
		
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			msum._matrix[i][j] = _matrix[i][j] + mat._matrix[i][j];
	
	return msum;
}

template <class MT> Matrix<MT> Matrix<MT>::operator+(MT factor)
{
	Matrix<MT> msum(row, col);
		
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			msum._matrix[i][j] = _matrix[i][j] + factor;

	return msum;
}

template <class MT> Matrix<MT> Matrix<MT>::operator-(Matrix<MT> &mat)
{
	if(row != mat.row || col != mat.col)
		throw MatrixException(MatrixException::__DIM_NOT_EQUAL);
	
	Matrix<MT> mdiff(row, col);
		
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			mdiff._matrix[i][j] = _matrix[i][j] - mat._matrix[i][j];

	return mdiff;
}

template <class MT> Matrix<MT> Matrix<MT>::operator-(MT factor)
{	
	Matrix<MT> mdiff(row, col);
		
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			mdiff._matrix[i][j] = _matrix[i][j] - factor;

	return mdiff;
}

template <class MT> Matrix<MT> Matrix<MT>::operator*(Matrix<MT> &mat)
{
	if(col != mat.row)
		throw MatrixException(MatrixException::__ROW_COL_NOT_EQUAL);
	
	Matrix<MT> mprod(row, mat.col);
		
	for(int i = 0; i < row; i++)
		for(int j = 0; j < mat.col; j++)
		{
			mprod._matrix[i][j] = 0;
			for(int k = 0; k < col; k++)
				mprod._matrix[i][j] += _matrix[i][k] * mat._matrix[k][j];
		}

	return mprod;
}

template <class MT> Matrix<MT> Matrix<MT>::operator*(MT factor)
{	
	Matrix<MT> mprod(row, col);
		
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			mprod._matrix[i][j] = _matrix[i][j] * factor;

	return mprod;
}

template <class MT> Matrix<MT> Matrix<MT>::operator/(MT factor)
{
	if(factor == 0)
		throw MatrixException(MatrixException::__DIVISION_BY_ZERO);

	Matrix<MT> mquot(row, col);
		
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			mquot._matrix[i][j] = _matrix[i][j] / factor;

	return mquot;
}

template <class MT> Matrix<MT> Matrix<MT>::transpose()
{	
	Matrix<MT> mtrans(col, row);

	for(int i = 0; i < col; i++)
		for(int j = 0; j < row; j++)
			mtrans._matrix[i][j] = _matrix[j][i];

	return mtrans;
}

template <class MT> MT Matrix<MT>::determinant()
{
	if(!isSquare())
		throw MatrixException(MatrixException::__NOT_SQUARE);
	
	if(row == 1 && col == 1)
		return _matrix[0][0];
	
	MT det = 0;
	int sign = 1;

	for(int i = 0; i < col; i++)
	{
		det += _matrix[0][i] * sign * minor(0, i).determinant();
		sign = -sign;
	}

	return det;
}

template <class MT> Matrix<MT> Matrix<MT>::inverse()
{
	if(!isSquare())
		throw MatrixException(MatrixException::__NOT_SQUARE);
	
	Matrix<MT> inv(row, col);

	inv = *this / this->determinant();

	return inv;
}

template <class MT> Matrix<MT> Matrix<MT>::adjoint()
{
	if(!isSquare())
		throw MatrixException(MatrixException::__NOT_SQUARE);
	
	Matrix<MT> cof(row, col);
	int sign;

	for(int i = 0; i < row; i++)
	{
		if(i % 2 == 0)
			sign = 1;
		else
			sign = -1;

		for(int j = 0; j < col; j++)
		{
			cof._matrix[i][j] = minor(i, j).determinant() * sign;
			sign = -sign;
		}
	}

	return cof.transpose();
}

template <class MT> Matrix<MT> Matrix<MT>::minor(int r, int c)
{
	int dim = col - 1;
	Matrix<MT> min(dim);

	for(int i = 0; i < dim; i++)
	{
		int k = i;
		if(i >= r)
			k = i + 1;
		for(int j = 0; j < dim; j++)
		{
			int l = j;
			if(j >= c)
				l = j + 1;

			min._matrix[i][j] = _matrix[k][l];
		}
	}

	return min;
}

template <class MT> bool Matrix<MT>::isSquare()
{
	if(row == col)
		return true;
	else
		return false;
}

template <class MT> bool Matrix<MT>::isDiagonal()
{
	if(!isSquare())
		return false;

	bool d = true;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			if(!((_matrix[i][j] != 0 && i == j) || (_matrix[i][j] == 0 && i != j)))
				d = false;

	return d;
}

template <class MT> bool Matrix<MT>::isIdentity()
{
	if(!isSquare())
		return false;

	bool d = true;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			if(!((_matrix[i][j] == 1 && i == j) || (_matrix[i][j] == 0 && i != j)))
				d = false;

	return d;
}

template <class MT> bool Matrix<MT>::isSymmetric()
{
	if(!isSquare())
		return false;
	
	bool d = true;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			if(i != j)
				if(_matrix[i][j] != _matrix[j][i])
					d = false;

	return d;
}

template <class MT> bool Matrix<MT>::isSkewSymmetric()
{
	if(!isSquare())
		return false;
	
	bool d = true;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			if(!(_matrix[i][j] == -_matrix[j][i] && i != j))
				d = false;

	return d;
}

template <class MT> ostream &operator<<(ostream &mout, Matrix<MT> &mat)
{
	for(int i = 0; i < mat.row; i++)
	{
		for(int j = 0; j < mat.col; j++)
			mout<<mat._matrix[i][j]<<"\t";

		mout<<endl;
	}

	return mout;
}

template <class MT> istream &operator>>(istream &min, Matrix<MT> &mat)
{
	for(int i = 0; i < mat.row; i++)
		for(int j = 0; j < mat.col; j++)
			min>>mat._matrix[i][j];

	return min;
}
