#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Utils.hpp"

using namespace std;



int main(){

    ifstream fileInput("data.csv"); // Sostituisci "nome_file.txt" con il nome effettivo del tuo file

    if(fileInput.fail()){
        cerr << "Errore nell'apertura del file di input" << endl;
        return 1;
    }

    string line;
    double S = 0.0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double rateOfReturn = 0;
    double V = 0;

    getline(fileInput, line, ';');
    getline(fileInput, line);
    S = stod(line);

    getline(fileInput, line, ';');
    getline(fileInput, line);
    n = stoi(line);

    getline(fileInput, line);
    w = new double[n];
    r = new double[n];

    for(unsigned int i = 0; i < n; i++){
        getline(fileInput, line, ';');
        w[i] = stod(line);
        getline(fileInput, line);
        r[i] = stod(line);
    }

    cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    cout << "w = [ ";
    for(unsigned int i = 0; i < n; i++){
        cout << w[i] << " ";
    }
    cout << "]" << endl;

    cout << "v = [ ";
    for(unsigned int i = 0; i < n; i++){
        cout << r[i] << " ";
    }
    cout << "]" << endl;



    // for(unsigned int i=0;i<n; i++){
    //     rateOfReturn = w1[i]*r1[i] + rateOfReturn;
    //     // cout << setprecision(4) << rateOfReturn  << " ";
    //     V = S*w1[i]*r1[i] + V;
    //     // cout << setprecision(2) << V << " ";
    // }

    cout << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    cout << "V: " << setprecision(2) << V << endl;

    ofstream fileOutput("result.txt");

    fileOutput << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    fileOutput << "w = [ ";
    for(unsigned int i = 0; i < n; i++){
        fileOutput << w[i] << " ";
    }
    fileOutput << "]" << endl;

    fileOutput << "v = [ ";
    for(unsigned int i = 0; i < n; i++){
        fileOutput << r[i] << " ";
    }
    fileOutput << "]" << endl;


    ComputeRateOfReturn(S,  n, w, r, rateOfReturn, V);


    fileOutput << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    fileOutput << "V: " << setprecision(2) << V << endl;

    delete[] w;
    delete[] r;

    fileInput.close();
    fileOutput.close();

    return 0;
}

