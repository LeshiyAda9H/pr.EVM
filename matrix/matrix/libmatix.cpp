#include "stdafx.h"

#include "matrix.h"
#include <iostream>
/*
Создание матрицы заданной размерности. 
Только выделение памяти.
*/

double** createMatrix(int rows, int columns)
{
	double** M = new double*[rows];
	for (int row = 0; row < rows; ++row)
	{
		M[row] = new double[columns];
	}
	return M;
}

/*
Освобождение памяти.
По факту кол-во столбиков не надо.
Оставлено для унификации вызовов функций.
*/

void deleteMatrix(double** &M, int rows, int columns)
{
	for (int row = 0; row < rows; ++row)
	{
		delete[] M[row];
	}
	delete[] M;
	M = nullptr;
}
void inputMatrix(double** M, int rows, int columns)
{
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < columns; ++col)
		{
			std::cout << "M(" << row + 1 << ", " << col + 1 << ") = ";
			std::cin >> M[row][col];
		}
	}
}
void printMatrix(double** M, int rows, int columns, const char* str)
{
	std::cout << str;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < columns; ++col)
		{
			std::cout << M[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

double** zeros(int rows, int columns)
{
	double** M = createMatrix(rows, columns);
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < columns; ++col)
		{
			M[row][col]=0.0;
		}
	}
	return M;
}
double** ones(int rows, int columns)
{
	double** M = createMatrix(rows, columns);
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < columns; ++col)
		{
			M[row][col] = 1.0;
		}
	}
	return M;
}
double** eye(int size)
{
	double** M = zeros(size, size);
	for (int row = 0; row < size; ++row)
	{
		M[row][row] = 1.0;
	}
	return M;
}
double** linspace(int from, int to)
{
	int size = (from > to) ? (from - to) : (to - from);
	++size;
	double** M = createMatrix(1, size);
	if (from < to)
	{
		for (int i=0; i < size; ++i)
		{
			M[0][i] = from;
			++from;
		}
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			M[0][i] = from;
			--from;
		}
	}
	return M;
}

