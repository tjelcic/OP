#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct
{
    int r;
    int c;
    float **mat;
}Matrix;

Matrix inputMatrix(int r,int c)
{
    Matrix matrix;
    matrix.r=r;
    matrix.c=c;
    matrix.mat=new float*[r];
    for(int i=0;i<r;i++)
        matrix.mat[i]=new float[c];

    cout<<"unesi elemente matrice"<<endl;

    for (int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>matrix.mat[i][j];
        }
    }
    cout<<endl;
    return matrix;
}

void printMatrix(Matrix m,int r, int c)
{
    for(int i=0; i < r;i++)
    {
        for(int j=0; j < c;j++)
        {
            cout<<fixed<<setprecision(4)<<right<<m.mat[i][j]<<" ";
        }
    cout<<endl;
    }
}

Matrix generateMatrix(int r, int c)
{
    srand(time(0));
    int a=1,b=100;
    Matrix matrix;
    matrix.r=r;
    matrix.c=c;
    matrix.mat=new float*[r];
    for(int i=0;i<r;i++)
        matrix.mat[i]=new float[c];

    for(int i=0; i < r;i++)
    {
        for(int j=0; j < c;j++)
        {
            matrix.mat[i][j]=a + (rand()%(b-a+1));
        }
    }
    return matrix;
}

Matrix addMatrices(Matrix mat1, Matrix mat2,int r,int c)
{
    Matrix matrix;
    matrix.r=r;
    matrix.c=c;
    matrix.mat=new float*[r];
    for(int i=0;i<r;i++)
        matrix.mat[i]=new float[c];

    if (mat1.c!=mat2.c && mat1.r!=mat2.r)
    {
        cout<<"Matrice nisu jednakog tipa"<<endl;
    }
    else
    {
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                matrix.mat[i][j] = (mat1.mat[i][j] + mat2.mat[i][j]);
            }
        }
    }
    return matrix;
}

Matrix substractMatrices(Matrix mat1, Matrix mat2,int r,int c)
{
    Matrix matrix;
    matrix.r=r;
    matrix.c=c;
    matrix.mat=new float*[r];
    for(int i=0;i<r;i++)
        matrix.mat[i]=new float[c];

    if (mat1.c!=mat2.c && mat1.r!=mat2.r)
    {
        cout<<"Matrice nisu jednakog tipa"<<endl;
    }
    else
    {
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                matrix.mat[i][j] = (mat1.mat[i][j] - mat2.mat[i][j]);
            }
        }
    }
    return matrix;
}

Matrix multiplyMatrices(Matrix mat1, Matrix mat2, int r, int c)
{
    Matrix matrix;
    matrix.r=r;
    matrix.c=c;
    matrix.mat=new float*[r];
    for(int i=0;i<r;i++)
        matrix.mat[i]=new float[c];

    if (mat1.c!=mat2.r)
    {
        cout<<"Matrice nisu ulancane!"<<endl;
    }

    else
    {
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                for(int k = 0; k < c; ++k)
                {
                    matrix.mat[i][j] += mat1.mat[i][k] * mat2.mat[k][j];
                }
            }
        }
    }
    return matrix;
}

Matrix transposeMatrix(Matrix m, int r, int c)
{
    Matrix matrix;
    matrix.r=c;
    matrix.c=r;
    matrix.mat=new float*[c];
    for(int i=0;i<c;i++)
        matrix.mat[i]=new float[r];

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            matrix.mat[j][i] = m.mat[i][j];
        }
    }
    return matrix;
}

void deleteMatrix(float** m, int r)
{
    for(int i = 0; i < r; i++)
        delete [] m[i];
    delete [] m;
}

int main()
{
    int m,n;
    cout<<"unesite dimenzije m i n"<<endl;
    cin>>m>>n;
    Matrix mat1=inputMatrix(m,n);
    printMatrix(mat1,m,n);
    cout<<endl;
    Matrix mat2=generateMatrix(m,n);
    printMatrix(mat2,m,n);
    cout<<endl;
    Matrix mat3=addMatrices(mat1,mat2,m,n);
    printMatrix(mat3,m,n);
    cout<<endl;
    Matrix mat4=substractMatrices(mat3,mat2,m,n);
    printMatrix(mat4,m,n);
    cout<<endl;
    Matrix mat5=multiplyMatrices(mat1,mat4,m,n);
    printMatrix(mat5,m,n);
    cout<<endl;
    Matrix mat6=transposeMatrix(mat1,m,n);
    printMatrix(mat6,n,m);
    deleteMatrix(mat1.mat,m);
    deleteMatrix(mat2.mat,m);
    deleteMatrix(mat3.mat,m);
    deleteMatrix(mat4.mat,m);
    deleteMatrix(mat5.mat,m);
    deleteMatrix(mat6.mat,n);
}
