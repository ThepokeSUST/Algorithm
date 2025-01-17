#include <iostream>
using namespace std;

void addMatrices(int A[][10], int B[][10], int result[][10], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[][10], int B[][10], int result[][10], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int A[][10], int B[][10], int C[][10], int size)
{
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        int newSize = size / 2;

        // Declare sub-matrices
        int A11[10][10], A12[10][10], A21[10][10], A22[10][10];
        int B11[10][10], B12[10][10], B21[10][10], B22[10][10];

        int M1[10][10], M2[10][10], M3[10][10], M4[10][10], M5[10][10], M6[10][10], M7[10][10];

        int temp1[10][10], temp2[10][10];

        // Divide A into four sub-matrices
        for (int i = 0; i < newSize; i++)
        {
            for (int j = 0; j < newSize; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];
            }
        }

        // Divide B into four sub-matrices
        for (int i = 0; i < newSize; i++)
        {
            for (int j = 0; j < newSize; j++)
            {
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }

        // M1 = A11 * (B12 - B22)
        subtractMatrices(B12, B22, temp1, newSize);
        strassen(A11, temp1, M1, newSize);

        // M2 = (A11 + A12) * B22
        addMatrices(A11, A12, temp1, newSize);
        strassen(temp1, B22, M2, newSize);

        // M3 = (A21 + A22) * B11
        addMatrices(A21, A22, temp1, newSize);
        strassen(temp1, B11, M3, newSize);

        // M4 = A22 * (B21 - B11)
        subtractMatrices(B21, B11, temp1, newSize);
        strassen(A22, temp1, M4, newSize);

        // M5 = (A11 + A22) * (B11 + B22)
        addMatrices(A11, A22, temp1, newSize);
        addMatrices(B11, B22, temp2, newSize);
        strassen(temp1, temp2, M5, newSize);

        // M6 = (A12 - A22) * (B21 + B22)
        subtractMatrices(A12, A22, temp1, newSize);
        addMatrices(B21, B22, temp2, newSize);
        strassen(temp1, temp2, M6, newSize);

        // M7 = (A11 - A21) * (B11 + B12)
        subtractMatrices(A11, A21, temp1, newSize);
        addMatrices(B11, B12, temp2, newSize);
        strassen(temp1, temp2, M7, newSize);

        // Combine the 7 matrices to get the final result
        // C11 = M5 + M4 - M2 + M6
        addMatrices(M5, M4, temp1, newSize);
        subtractMatrices(temp1, M2, temp2, newSize);
        addMatrices(temp2, M6, C, newSize);

        // C12 = M1 + M2
        addMatrices(M1, M2, temp1, newSize);
        for (int i = 0; i < newSize; i++)
        {
            for (int j = 0; j < newSize; j++)
            {
                C[i][j + newSize] = temp1[i][j];
            }
        }

        // C21 = M3 + M4
        addMatrices(M3, M4, temp1, newSize);
        for (int i = 0; i < newSize; i++)
        {
            for (int j = 0; j < newSize; j++)
            {
                C[i + newSize][j] = temp1[i][j];
            }
        }

        // C22 = M5 + M1 - M3 - M7
        addMatrices(M5, M1, temp1, newSize);
        subtractMatrices(temp1, M3, temp2, newSize);
        subtractMatrices(temp2, M7, temp1, newSize);
        for (int i = 0; i < newSize; i++)
        {
            for (int j = 0; j < newSize; j++)
            {
                C[i + newSize][j + newSize] = temp1[i][j];
            }
        }
    }
}

int main()
{
    int n;

    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int A[10][10], B[10][10], C[10][10];

    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    strassen(A, B, C, n);

    cout << "The result matrix C is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}