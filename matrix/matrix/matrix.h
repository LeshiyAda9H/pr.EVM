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

#endif