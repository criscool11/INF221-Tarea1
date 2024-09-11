#include <bits/stdc++.h>
using namespace std;

void multiplyTraditional(int** A, int** B, int** C, int m, int p, int n) {
    /*
    **
    Parametros: 
    A = primera matriz de tamaño m x p
    B = segunda matriz de tamaño p x n
    C = matriz resultado de tamaño m x n
    m = número de filas de A
    p = número de columnas de A (y filas de B)
    n = número de columnas de B
    **
    Sin retorno
    **
    La funcion multiplica las dos matrices y las almacena en la matriz C
    */
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < p; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m = 2, p = 3, n = 2;
    int** A = new int*[m];
    int** B = new int*[p];
    int** C = new int*[m];

    for (int i = 0; i < m; i++) {
        A[i] = new int[p];
    }
    for (int i = 0; i < p; i++) {
        B[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        C[i] = new int[n];
    }
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;

    B[0][0] = 7; B[0][1] = 8;
    B[1][0] = 9; B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;
    multiplyTraditional(A, B, C, m, p, n);
    cout << "Resultado de la multiplicacion tradicional:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}