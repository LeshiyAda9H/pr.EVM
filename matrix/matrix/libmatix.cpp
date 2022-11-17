#include "stdafx.h"

#include "matrix.h"
#include <iostream>
#include <fstream>
/*
Создание матрицы заданной размерности. 
Только выделение памяти.
*/

Matrix createMatrix(int rows, int columns)
{
	Matrix M;
	M.data = new double*[rows];
	for (int row = 0; row < rows; ++row)
	{
		M.data[row] = new double[columns];
	}
	M.rows = rows;
	M.columns = columns;

	return M;
}

/*
Освобождение памяти.
По факту кол-во столбиков не надо.
Оставлено для унификации вызовов функций.
*/

void deleteMatrix(Matrix & M)
{
	for (int row = 0; row < M.rows; ++row)
	{
		delete[] M.data[row];
	}
	delete[] M.data;
	M.data = nullptr;
}
void inputMatrix(Matrix M)
{
	for (int row = 0; row < M.rows; ++row)
	{
		for (int col = 0; col < M.columns; ++col)
		{
			std::cout << "M(" << row + 1 << ", " << col + 1 << ") = ";
			std::cin >> M.data[row][col];
		}
	}
}
void printMatrix(const Matrix & M, const char* str)
{
	std::cout << str;
	for (int row = 0; row < M.rows; ++row)
	{
		for (int col = 0; col < M.columns; ++col)
		{
			std::cout << M.data[row][col] << " ";
		}
		std::cout << std::endl;
	}
}
void matrix2tex(const Matrix & M)
{
	std::cout << "\\left (\\begin{matrix}" << std::endl;
	for (int row = 0; row < M.rows; ++row)
	{
		std::cout << M.data[row][0];
		for (int col = 1; col < M.columns; ++col)
		{
			std::cout << " & " << M.data[row][col];
		}
		std::cout << "\\\\" << std::endl;
	}
	std::cout << "\\end{matrix} \\right)"<< std::endl;
}

Matrix zeros(int rows, int columns)
{
	Matrix M = createMatrix(rows, columns);
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < columns; ++col)
		{
			M.data[row][col]=0.0;
		}
	}
	return M;
}
Matrix ones(int rows, int columns)
{
	Matrix M = createMatrix(rows, columns);
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < columns; ++col)
		{
			M.data[row][col] = 1.0;
		}
	}
	return M;
}
Matrix eye(int size)
{
	Matrix M = zeros(size, size);
	for (int row = 0; row < size; ++row)
	{
		M.data[row][row] = 1.0;
	}
	return M;
}
Matrix linspace(int from, int to)
{
	int size = (from > to) ? (from - to) : (to - from);
	++size;
	Matrix M = createMatrix(1, size);
	if (from < to)
	{
		for (int i=0; i < size; ++i)
		{
			M.data[0][i] = from;
			++from;
		}
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			M.data[0][i] = from;
			--from;
		}
	}
	return M;
}

Matrix plusMatrix(const Matrix & A, const Matrix & B)
{
	if (A.columns != B.columns)
	{
		throw "Plus matrix: wrong matrix size";
	}
	if (A.rows != B.rows)
	{
		throw "Plus matrix: wrong matrix size";
	}
	Matrix C = createMatrix(A.rows, A.columns);
	for (int row = 0; row < A.rows; ++row)
	{
		for (int col = 0; col < A.columns; ++col)
		{
			C.data[row][col] = A.data[row][col] + B.data[row][col];
		}
	}
	return C;
}

Matrix mulMatrix(Matrix A, double B)
{
	Matrix C = createMatrix(A.rows, A.columns);
	for (int row = 0; row < A.rows; ++row)
	{
		for (int col = 0; col < A.columns; ++col)
		{
			C.data[row][col] = B * A.data[row][col];
		}
	}
	return C;
}


Matrix multMatrix(Matrix A, Matrix B)
{
	if (A.columns != B.rows)
	{
		throw "Multiplication: wrang matrix size";
	}
	Matrix C = zeros(A.rows, B.columns);
	for (int rowA = 0; rowA < A.rows; ++rowA)
	{
		for (int colB = 0; colB < B.columns; ++colB)
		{
			for (int k = 0; k < A.columns; ++k)
			{
				C.data[rowA][colB] += A.data[rowA][k] * B.data[k][colB];
			}
		}
	}
	return C;
}

Matrix transpose(Matrix A)
{
	Matrix B = createMatrix(A.columns, A.rows);
	for (int row = 0; row < A.rows; ++row)
	{
		for (int col = 0; col < A.columns; ++col)
		{
			B.data[col][row] = A.data[row][col];
		}
	}
	return B;
}
	void saveMatrix(const char *fname, Matrix A)
	{
		std::ofstream outFile(fname);
		if (!outFile)
		{
			throw "Can not write to file";
		}
		outFile << A.rows << " " << A.columns << std::endl;

		for (int row = 0; row < A.rows; ++row)
		{
			for (int col = 0; col < A.columns; ++col)
			{
				outFile << A.data[row][col] << " ";
			}
			outFile << std::endl;
		}

		outFile.close();
	}

	Matrix loadMatrix(const char* fname)
	{
		std::ifstream inFile(fname);
		if (!inFile)
		{
			throw "Can not read file";
		}
		int rows, int columns;
		inFile >> rows >> columns;
		Matrix M = createMatrix(rows, columns);
		for (int row=0; row < rows; ++row)
		{
			for (int col = 0; col < columns; ++col)
			{
				inFile >> M.data[row][columns];
			}
		}
		inFile.close();
		return M;


	}

	double& minMatrix(const Matrix& A)
	{
		int i = 0;
		int j = 0;
		for (int row = 0; row < A.rows; ++row)
		{
			for (int col = 0; col < A.columns; col++)
			{
				if (A.data[row][col] < A.data[i][j])
				{
					i = row;
					j = col;
				}
			}
			return A.data[i][j];
		}
	

	}

	Matrix horzcat(const Matrix& A, const Matrix& B)
	{
		if (A.rows != B.rows)
		{
			throw "Horzcat: wrong matrix size";
		}

		Matrix C = createMatrix(A.rows, A.columns + B.columns);
		for (int row = 0; row < A.rows; row++)
		{
			for (int col = 0; col < A.columns; col++)
			{
				C.data[row][col] = A.data[row][col];
			}
		}

		for (int row = 0; row < B.rows; row++)
		{
			for (int col = 0; col < B.columns; col++)
			{
				C.data[row][col + A.columns] = B.data[row][col];
			}
		}
		return C;
	}
	


