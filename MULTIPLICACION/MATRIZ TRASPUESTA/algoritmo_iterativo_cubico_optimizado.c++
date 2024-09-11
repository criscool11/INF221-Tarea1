#include <bits/stdc++.h>
using namespace std;

void transposeMatrix(int** B, int** Bt, int p, int n) {
    /*
    **
    Parametros:
    B = matriz original de tamaño p x n
    Bt = matriz transpuesta de tamaño n x p
    p = número de filas de B
    n = número de columnas de B (serán las filas de Bt)
    **
    Sin retorno
    **
    La funcion multiplica traspone la segunda matriz
    */ 
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < n; ++j) {
            Bt[j][i] = B[i][j];
        }
    }
}

void multiplyOptimized(int** A, int** Bt, int** C, int m, int p, int n) {
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
    La funcion multiplica las dos matrices(la matriz B traspuesta) y las almacena en la matriz C
    */
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < p; ++k) {
                C[i][j] += A[i][k] * Bt[j][k]; // Usamos Bt en lugar de B
            }
        }
    }
}

int main() {
    int m = 2, p = 3, n = 2;

    // Inicialización de matrices
    int** A = new int*[m];
    int** B = new int*[p];
    int** Bt = new int*[n]; // Para almacenar la transpuesta de B
    int** C = new int*[m];

    for (int i = 0; i < m; i++) {
        A[i] = new int[p];
    }
    for (int i = 0; i < p; i++) {
        B[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        Bt[i] = new int[p];
    }
    for (int i = 0; i < m; i++) {
        C[i] = new int[n];
    }

    // Rellenar matrices A y B
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;

    B[0][0] = 7; B[0][1] = 8;
    B[1][0] = 9; B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;

    // Transponer matriz B
    transposeMatrix(B, Bt, p, n);

    // Multiplicar matrices usando la optimización
    multiplyOptimized(A, Bt, C, m, p, n);

    // Imprimir matriz resultado C
    cout << "Resultado de la multiplicación optimizada:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}