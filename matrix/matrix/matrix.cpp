
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


int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;

	if (argc == 2)
	{
		try
		{
			Matrix A = loadMatrix(argv[1]);
			Matrix A2 = multMatrix(A, A);
			Matrix A3 = multMatrix(A, A2);
			printMatrix(A, "A^3 = \n");
			matrix2tex(A3);
			deleteMatrix(A);
			deleteMatrix(A2);
			deleteMatrix(A3);

		}
		catch (const char* error)
		{
			std::cout << error << std::endl;
		}
		catch (...)
		{
			std::cout << "Unknow error" << std::endl;
		}
		return 0;
	}

	if (argc < 3)
	{
		std::cout << "Use " << argv[0] << " rows columns" << std::endl;
		return 1;
	}

	n = atoi(argv[1]);
	m = atoi(argv[2]);


	/*
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
	*/


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

