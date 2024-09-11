#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void Merge(vector<int>& vect, int l,int m, int r){
    /*
    **
    Parametros: 
    vect = vector
    l: un numero que representa el elemento inicial de un arreglo
    l: un numero que representa el elemento del medio  de un arreglo
    r: un numero que representa el ultimo elemento de un arreglo
    **
    Sin retorno
    **
    La funcion mediante la creacion de dos subarreglos, va combinando esos dos subarreglos de forma ordenada para formar una lista ordenada
    */
    int arr1 = m-l+1;
    int arr2 = r-m;
    int C[arr1], D[arr2];

    for(int i = 0;i<arr1;i++){
        C[i] = vect[l+i];
    }
    for(int j = 0;j<arr2;j++){
        D[j] = vect[m+j+1];
    }
    int i = 0, j = 0, k = l;
    while (i < arr1 && j < arr2) {
        if (C[i] <= D[j]) {
            vect[k] = C[i];
            i++;
        } else {
            vect[k] = D[j];
            j++;
        }
        k++;
    }
    while (i < arr1) {
        vect[k] = C[i];
        i++;
        k++;
    }

    while (j < arr2) {
        vect[k] = D[j];
        j++;
        k++;
    }
}
void MergeSort(vector<int>& vect, int inicio, int final){
    /*
    **
    Parametros: 
    vect = vector
    inicio: un numero que representa el elemento inicial de un arreglo
    final: un numero que representa el ultimo elemento de un arreglo
    **
    Sin retorno
    **
    La funcion va separando los elementos del arreglo de manera recursiva hasta llegar a solo elementos, posterior a eso, une todos esos elementos con merge
    */
    if (inicio >= final){
        return;
    }
    int pivote = inicio + (final-inicio)/2;
    MergeSort(vect,inicio,pivote);
    MergeSort(vect,pivote+1,final);
    Merge(vect,inicio,pivote,final);
}

vector<int> DatosToVector(const string &filename,int caso){
    /*
    **
    Parametros: 
    filename = string con el nombre de un archivo
    caso = numero para saber en que linea nos encontramos
    **
    retorna un vector con numeros(ordenados/invertidos/aleatorios)
    **
    La funcion toma las lineas de un archivo y mete los numeros en el vector
    */
    ifstream file(filename);
    vector<int> data;
    string linea;
    int numero_vector;
    int casos = 0;
    while (getline(file, linea)){
        if(casos == caso){
            stringstream dato(linea);
            while(dato >> numero_vector){
                data.push_back(numero_vector);
            }
            break;
        }
        casos++;
    }
    file.close();
    return data;
}


int main(){
    string filename = "dataset.txt";
    vector<int>vec;
    int casos = 3;
    double Tiempo = 0.0;
    for (int i = 0; i < casos; ++i) {
        double num = 0;
        for(int j=0; j<10;j++){
            vec = DatosToVector(filename,i);
            auto start = high_resolution_clock::now();
            MergeSort(vec, 0, vec.size() - 1);
            auto stop = high_resolution_clock::now();
            Tiempo = duration<double>(stop - start).count();  
            num += Tiempo;    
        }
        double prom = 0;
        prom = num/10;
        cout<<prom<<" ";
    }
    return 0;
}