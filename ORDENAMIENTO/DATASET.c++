#include<bits/stdc++.h>
using namespace std;

void Ordenar(vector<int>& data){
    sort(data.begin(), data.end());
}
/*
**
Parametros: 
data = vector
**
Tipo de retorno:
Sin retorno
**
Descripcion:
Esta función ordena los numeros en un vector
*/
void Invertir(vector<int>& data){
    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());
}
/*
**
Parametros: 
data = vector
**
Tipo de retorno:
Sin retorno
**
Descripcion:
Esta función invierte el orden de los numeros un vector
*/
void generateData(const string& filename, int numero) {
    srand(time(0));
    vector<int> data(numero);
    vector<int> data_o(numero);
    vector<int> data_i(numero);
    for(int i = 0; i< numero;i++){
         data_i[i] = rand() % (1000000 - 1) + 1;
    }
    Invertir(data_i);
    for(int i = 0; i< numero;i++){
         data_o[i] = rand() % (1000000 - 1) + 1;
    }
    Ordenar(data_o);
    for (int i = 0; i < numero; ++i) {
        data[i] = rand() % (1000000 - 1) + 1;
    }
    ofstream file(filename);
    for (size_t i = 0; i < data_o.size(); ++i) {
        file << data_o[i] <<" ";
    }
    file <<endl;
    for (size_t i = 0; i < data.size(); ++i) {
        file << data[i] <<" ";
    }
    file <<endl;
    for (size_t i = 0; i < data_i.size(); ++i) {
        file << data_i[i] <<" ";
    }
    file.close();
}

int main() {
    srand(time(0));
    string filename = "dataset.txt";
    size_t num_elements =  20000;
    generateData(filename, num_elements);
    return 0;
}