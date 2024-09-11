#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void SelectionSort(int arr[], int tamano){
    /*
    **
    Parametros: 
    arr = arreglo
    tamano = tamaño del arreglo
    **
    Sin retorno
    **
    La funcion primero elige el elemento mayor, intercambia ese elemento con el ultimo elemento(excluyendo el mayor elegido anteriormente), realizando esos pasos de manera recursiva hasta ordenar el arreglo
    */
    for(int i = 0;i<tamano-1;i++){
        int m = i;
        for (int j = i+1;j<tamano;j++){
            if(arr[j] < arr[m]){
                m = j;
            }
        }
        swap(arr[m],arr[i]);
    }
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

int main() {
    string filename = "dataset.txt";
    vector<int>vec;
    int casos = 3;
    double Tiempo = 0.0;
    for (int i = 0; i < casos; ++i) {
        double num = 0;
        for(int j=0; j<10;j++){
            vec = DatosToVector(filename,i);
            auto start = high_resolution_clock::now();
            SelectionSort(vec.data(),vec.size());
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