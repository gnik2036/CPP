#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include<iostream>
using namespace std;
class Matrix
{
private:
    int r;
    int c;
    int** matrix ;
public:
    Matrix();
    Matrix(int row, int col);
    ~Matrix();
    friend istream& operator>>(istream& in,const  Matrix& mat);
    friend ostream& operator<<(ostream& out,const  Matrix& mat);
    Matrix operator+(const Matrix &mat);
    Matrix operator*(const Matrix &mat);
    Matrix operator-(const Matrix &mat);
    Matrix transpose();

};

#endif // MATRIX_H_INCLUDED
