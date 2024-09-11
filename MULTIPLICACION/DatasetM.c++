#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> GenerarMatriz(int size) {
    /*
    **
    Parametros: 
    size = tamaño de la matriz
    **
    Tipo de retorno:
    vector con vectores, la representacion de una matriz
    **
    Descripcion:
    Almacena datos random en un vector de vectores para despues ser representado como matriz
    */
    vector<vector<int>> matriz(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matriz[i][j] = rand() % (1000000 - 1) + 1;
        }
    }
    return matriz;
}

void MatrizToData(const string& filename, const vector<vector<int>>& matriz,int size){
    /*
    **
    Parametros: 
    filename = nombre del archivo donde se guardará la matriz
    matriz = la matriz generada anteriormente
    size = tamaño de la matriz
    **
    Tipo de retorno:
    Sin retorno
    **
    Descripcion:
    Guarda la matriz en un archivo de texto con filas separadas por saltos de línea y valores separados por espacios. También añade el tamaño de la matriz.
    */
    ofstream file(filename, ios::app);
    file << "Matriz " << size << "x" << size << ":\n";
    for (const auto& fila : matriz) {
        for (const auto& num : fila) {
            file << num << " ";
        }
        file << endl;
    }
    file << endl; 
    file.close();
}

int main(){
    srand(time(0));
    string filename = "datasetM.txt";
    int Tamano_inicial = 2;
    for(int i = 0;i<6;i++){
        int size = Tamano_inicial * pow(2,i);
        for(int j = 0;j<2;j++){
            vector<vector<int>> matriz = GenerarMatriz(size);
            MatrizToData(filename, matriz,size);
        }
    }
    
}
