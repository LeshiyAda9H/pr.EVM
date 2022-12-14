
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

	

	try
	{
		Matrix Z = zeros(n, m);
		printMatrix(Z, "Z = \n");

		Matrix O = ones(n, m);
		printMatrix(O, "O = \n");

		Matrix L = linspace(1, n);
		printMatrix(L, "L = \n");

		Matrix A = plusMatrix(O, O);
		printMatrix(A, "O + O = \n");

		Matrix Lt = transpose(L);

		Matrix B = multMatrix(Lt, L);
		printMatrix(B, "B = \n");

		saveMatrix("result.txt", B);

		std::cout << "Minimum in B: " << minMatrix(B) << std::endl;
		minMatrix(B) = 100;
		printMatrix(B, "B = \n");

		Matrix H = horzcat(B, Z);
		printMatrix(H, "H = \n");

		deleteMatrix(H);
		deleteMatrix(Z);
		deleteMatrix(O);
		deleteMatrix(L);
		deleteMatrix(A);
		deleteMatrix(Lt);
		deleteMatrix(B);
	}
	catch (const char *error)
	{
		std::cout << "Error: " << error << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknow error." << std::endl;
	}

	
}

