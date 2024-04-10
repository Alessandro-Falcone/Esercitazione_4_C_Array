#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    ifstream fileInput("data.csv"); // Sostituisci "nome_file.txt" con il nome effettivo del tuo file

    if (fileInput.fail()){
        cerr << "Errore nell'apertura del file" << endl;
        return 1;
    }

    string line;
    double S = 0.0;
    unsigned int n = 0;
    string w;
    string r;


    getline(fileInput, line, ';');
    getline(fileInput, line);
    S = stod(line);
    cout << "S=" << S << endl;

    getline(fileInput, line, ';');
    getline(fileInput, line);
    n = stoi(line);
    cout << "n=" << n << endl;

    double *w1 = new double[n];
    double *v1 = new double[n];
    getline(fileInput, line, ';');
    w = line;
    cout << line << endl;
    getline(fileInput, line);
    r = line;
    cout << line << endl;

    for(unsigned int i = 0; i < n; i++){
        getline(fileInput, line, ';');
        w1[i] = stod(line);
        getline(fileInput, line);
        v1[i] = stod(line);
    }

    for(unsigned int i = 0; i < n; i++){
        cout << w1[i] << " ";
    }
    cout << "\n";
    for(unsigned int i = 0; i < n; i++){
        cout << v1[i] << " ";
    }
    cout << "\n";
    delete[] w1;
    delete[] v1;






    while (getline(fileInput, line)) {
        cout << line << endl;
    }

    fileInput.close();

    return 0;
}
