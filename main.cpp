#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;
int determinant(int matrix[10][10], int n);

int main()
{
    int n, i, j;
    int matrix[10][10];

    cout << "This program claculates the determinant of a matrix. " << endl;
    cout << "Enter the size of the matrix (2x2 = 2, 10x10 = 10): ";
    {
        cin >> n;
        cout << "\nEnter the elements of the matrix "
             << "with a space between each integer:\n";

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                cin >> matrix[i][j];

        cout << "\nThe determinant of the matrix is " << determinant(matrix, n) << endl;
        return 0;
    }
}
int determinant(int matrix[10][10], int n)
{
    int det = 0;
    int submatrix[10][10];

    // If matrix is 2 then determinant is directly calculated
    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    // If matrix is larger then 2, three nested loops calc det
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            } // calc determinent
            det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
        }
    }
    return det;
}
