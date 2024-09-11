#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


void Sorting(vector<int>& vec) {
    /*
    **
    Parametros: 
    vec = vector
    **
    Sin retorno
    **
    La funcion ordena la lista mediante la funcion de sorting
    */
    sort(vec.begin(), vec.end());  
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
            Sorting(vec);
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