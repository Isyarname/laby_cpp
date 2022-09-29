#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
void p(int matrixA[4][5], int matrixC[4][4])
{
    unsigned l = 4, m = 5;
    int s;
    unsigned &n = m;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s = 0;
            for (int r = 0; r < m; r++)
            {
                s += matrixA[i][r] * matrixA[j][r];
            }
            matrixC[i][j] = s;
        }
    }
}

void printM(int matrix[4][4])
{
    unsigned n = 4;
    int len;
    string p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p = "";
            len = to_string(matrix[i][j]).length();
            cout << string(4 - len, ' ') << matrix[i][j];
        }
        cout << endl;
    }
} 
 
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
 
    const unsigned n = 4, m = 5;
    int matrixA[n][m];
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrixA[i][j] = (rand() % 11) - 5;
        }
    }
 
    int matrixC[n][n];
    p(matrixA, matrixC);
    printM(matrixC);
    
    return 0;
}