
#include "stdafx.h"
#include <iostream>
#include "matrix.h"

/*
Создание матриц произвольной размерности
Вводить матрицы с клавиатуры
Читать матрицы из файлов
Сложения файлов
Умножения матрицы
Транспорнирование матриц
*/


int main()
{
	int n = 0;
	int m = 0;
	do
	{
		std::cout << " n = ";
		std::cin >> n;
	} while (n < 1);

	do
	{
		std::cout << " m = ";
		std::cin >> m;
	} while (m < 1);

	/*
	double** M = createMatrix(n, n);

	inputMatrix(M, n, m);

	printMatrix(M, n, m);

	deleteMatrix(M, n, m);
	*/

	double** Z = zeros (n,m);
	printMatrix(Z, n, m, "Z = \n");

	double** O =  ones(n,m);
	printMatrix(O, n, m, "O = \n");

	double** L = linspace(1,m);
	printMatrix(L, 1, m, "L = \n");

	deleteMatrix(Z, n, m);
	deleteMatrix(O, n, m);
	deleteMatrix(L, 1, m);
}

