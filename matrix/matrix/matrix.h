#ifndef __MYMATIX2022__
#define __MYMATIX2022__

struct Matrix
{
	double** data;
	int rows;
	int columns;
};


Matrix createMatrix(int rows, int columns);
void deleteMatrix(Matrix & M);
void inputMatrix(Matrix M);
void printMatrix(const Matrix & M, const char* str);


Matrix zeros(int rows, int columns);
Matrix ones(int rows, int columns);
Matrix eye(int size);
Matrix linspace(int from, int to);
Matrix plusMatrix(const Matrix & A, const Matrix & B);

Matrix mulMatrix(Matrix A, double B);
Matrix multMatrix(Matrix A, Matrix B);

Matrix transpose(Matrix A);

void saveMatrix(const char *fname, Matrix A);

double& minMatrix(const Matrix& A);
Matrix horzcat(const Matrix& A, const Matrix& B);


#endif