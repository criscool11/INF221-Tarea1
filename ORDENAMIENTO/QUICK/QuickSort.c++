#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(vector<int> &vec, int inicio, int high) {
    /*
    **
    Parametros: 
    vec = vector
    inicio: un numero que representa el elemento inicial de un arreglo
    final: un numero que representa el ultimo elemento de un arreglo
    **
    retorna un entero, la posicion del pivote
    **
    La funcion ordena el arreglo de mayor a menor y retorna un numero que indica la posicion del pivote en el arreglo, esto para posterior separar el arreglo en 2
    */
    int pivot = vec[high];
    int i = (inicio - 1);

    for (int j = inicio; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

void quickSort(vector<int> &vec, int inicio, int final) {
    /*
    **
    Parametros: 
    vec = vector
    inicio: un numero que representa el elemento inicial de un arreglo
    final: un numero que representa el ultimo elemento de un arreglo
    **
    Sin return
    **
    La funcion toma un arreglo o subarreglo y se selecciona un pivote mediante la funcion partition para dividir ese arreglo en 2, posterior con los arreglos separados se hacen llamadas recursivas hasta que el inicio < final
    */
    if (inicio < final) {
        int pivote = partition(vec, inicio, final);
        quickSort(vec, inicio, pivote - 1);
        quickSort(vec, pivote + 1, final);
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
            quickSort(vec, 0, vec.size() - 1);
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