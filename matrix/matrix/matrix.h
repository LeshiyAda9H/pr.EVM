#ifndef __MYMATIX2022__

#define __MYMATIX2022__
double** createMatrix(int rows, int columns);
void deleteMatrix(double** &M, int rows, int columns);
void inputMatrix(double** M, int rows, int columns);
void printMatrix(double** M, int rows, int columns, const char* str);
double** zeros(int rows, int columns);
double** ones(int rows, int columns);
double** eye(int size);
double** linspace(int from, int to);

double** plusMatrix(double** A, double** B, int rows, int columns);
double** mulMatrix(double** A, double B, int rows, int columns);
double** multMatrix(double** A, int rowsA, int columnsA, 
					double** B, int rowsB, int columnsB);
double** transpose(double** A, int rows, int columns);

void saveMatrix(const char *fname, double** A, int rows, int columns);

#endif