#include <iostream> 
using namespace std; 

void inputMatrix(int matrix[3][3])
{
    cout<< "Enter elements of the matrix (3x3):\n";
    for (int i = 0; i< 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>> matrix[i][j];
        }
    }
} 

void multiplyMatrices(int A[3][3], int B[3][3], int C[3][3])
{
    for (int i = 0; i< 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j];
        }
    }
} 

void displayMatrix(int matrix[3][3])
{
    for (int i = 0; i< 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<< matrix[i][j] << " ";
        }
    cout<<endl;
    }
} 

int main()
{
    int A[3][3], B[3][3], C[3][3];

    inputMatrix(A);
    inputMatrix(B);
    multiplyMatrices(A, B, C); 

    cout<< "The product of matrix A and matrix B is:\n"; 

    displayMatrix(C); 
    system("pause");
    return 0;
}