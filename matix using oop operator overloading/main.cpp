#include <iostream>
#include"matrix.h"
using namespace std;


/*class Matrix
{
private:
    int r;
    int c;
    int** matrix ;
public:

    ~Matrix();
    Matrix(int row=0, int col=0 )
    {
        r=row;
        c=col;
        matrix= new int* [r];
    }
    ~Matrix()
    {
        delete [] matrix;
    }

   /* int operator[][](int i, int j) {
         if( i > mRow ) {
            cout << "Index out of bounds" <<endl;
            // return first element.
            return matrix[i][j];
         }
    }*/

/*   friend istream& operator>>(istream& in,const  Matrix& mat);
   friend ostream& operator<<(ostream& out,const  Matrix& mat);
   Matrix operator+(const Matrix &mat);
   Matrix operator*(const Matrix &mat);
   Matrix operator-(const Matrix &mat);
   Matrix transpose();

};*/
Matrix::Matrix()
{

}
Matrix::Matrix(int row, int col )
{
    r=row;
    c=col;
    matrix= new int* [r];
}
Matrix::~Matrix()
{
    delete [] matrix;
}
Matrix Matrix::operator+(const Matrix &mat)
{
    Matrix res(r,c);

    for(int i = 0 ; i<r; i++)
    {
        res.matrix[i] = new int[c];
        for(int j = 0 ; j<c ; j++)
        {

            res.matrix[i][j] = matrix[i][j] + mat.matrix[i][j];

        }

    }
    return res;


}
Matrix Matrix:: operator-(const Matrix &mat)
{
    Matrix res(r,c);
    for(int i = 0 ; i<r; i++)
    {
        res.matrix[i] = new int[c];
        for(int j = 0 ; j<c ; j++)
        {

            res.matrix[i][j] = matrix[i][j] - mat.matrix[i][j];

        }

    }
    return res ;

}
Matrix Matrix:: operator*(const Matrix &mat)
{
    int   a[100][100];

    Matrix res(r,c);
    for(int i = 0 ; i<r; i++)
    {
        res.matrix[i] = new int[c];
        for(int j = 0 ; j<c ; j++)
        {
            a[i][j]=0;
            for ( int k=0 ; k <c; k++)
            {
                a[i][j]=a[i][j] +( matrix[i][k]*mat.matrix[k][j]);
            }
            res.matrix[i][j] = a[i][j];
        }
    }
    return res ;
}
istream& operator>>(istream& in,const Matrix& mat)
{
    for(int i = 0 ; i<mat.r ; i++)
    {
        mat.matrix[i] = new int[mat.c];
        for(int j = 0 ; j<mat.c ; j++)
        {
            in>>mat.matrix[i][j];
        }

    }
    return in;
}
ostream& operator<<(ostream& out,const Matrix& mat)
{
    for(int i = 0 ; i<mat.r; i++)
    {

        for(int j = 0 ; j<mat.c; j++)
        {
            out<<mat.matrix[i][j]<<" ";

        }
        out<<'\n';
    }

    return out;
}
Matrix Matrix::transpose()
{

    Matrix res(r,c);

    for(int i = 0 ; i<r; i++)
    {
        res.matrix[i] = new int[c];
        for(int j = 0 ; j<c ; j++)
        {
            res.matrix[i][j] = matrix[j][i];
        }
    }
    return res;
}
int main()
{
    Matrix m1(2,2),m2(2,2);
    cout<<"enter your first matrix 2 * 2 : "<<endl ;

    cin>>m1;
    cout<<endl<<m1<<endl;
    cout<<"enter your Second matrix 2 * 2 : "<<endl ;
    cin>>m2;
    cout<<endl<<m2;
    cout<<"sum of them  :"<<endl ;
    cout<<endl<< m1 + m2;
    cout<<"multi of them  :"<<endl ;
    cout<<endl<<m1*m2;
    cout<<"sub of them  :"<<endl ;
    cout<<endl<<m1-m2;
    cout<<"transpose of them  :"<<endl ;
    cout<<endl<<m1.transpose();

    return 0;
}
