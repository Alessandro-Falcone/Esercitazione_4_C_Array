#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// funzioni
bool letturaDatiFileInput(const string& percorsoFileInput, double& S, size_t& n, double*& w, double*& r){

    ifstream fileInput;
    fileInput.open(percorsoFileInput); // apro il file di input

    if(fileInput.fail()){ // controllo se il file di input è stato aperto correttamente

        // se il file di input inserito non e' stato aperto correttamente la funzione ritorna "false"
        return false;

    }else{

        string line;
        S = 0.0;
        n = 0;

        getline(fileInput, line, ';');
        getline(fileInput, line);
        S = stod(line);

        getline(fileInput, line, ';');
        getline(fileInput, line);
        n = stoi(line);

        getline(fileInput, line);
        w = new double[n];
        // alloco dinamicamente un array w di numeri double di lunghezza n.
        // double indica il tipo di dati dell'array, che in questo caso è un array di numeri in virgola mobile.
        // n rappresenta la lunghezza dell'array, ovvero il numero di elementi che verranno allocati.

        r = new double[n];
        // alloco dinamicamente un array w di numeri double di lunghezza n.
        // double indica il tipo di dati dell'array, che in questo caso è un array di numeri in virgola mobile.
        // n rappresenta la lunghezza dell'array, ovvero il numero di elementi che verranno allocati.

        for(unsigned int i = 0; i < n; i++){
            getline(fileInput, line, ';');
            w[i] = stod(line);
            getline(fileInput, line);
            r[i] = stod(line);
        }
        return true;
    }
    // fileInput.close(); // chiudo il file di input
}

void calcoloRateOfReturn(const double& S, const size_t& n,
                         const double* const& w, const double* const& r,
                         double& rateOfReturn, double& V){
    rateOfReturn = 0;
    V = S;
    for(unsigned int i = 0; i < n; i++){
        rateOfReturn = w[i]*r[i] + rateOfReturn;
        V = S*w[i]*r[i] + V;
    }
}

void scritturaSuFileOutput(ostream& fileOutput, const double& S, const size_t& n,
                              const double* const& w, const double* const& r,
                              double& rateOfReturn, double& V){

    fileOutput << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    fileOutput << "w = [ ";
    for(unsigned int i = 0; i < n; i++){
        if((int) (w[i]*10) == w[i]*10){
            fileOutput << setprecision(1) << w[i] << " ";
        }else{
            fileOutput << setprecision(2) << w[i] << " ";
        }
    }
    fileOutput << "]" << endl;

    // ceil(w[i]*10)==w[i]*10

    fileOutput << "v = [ ";
    for(unsigned int i = 0; i < n; i++){
        if((int) (r[i]*10) == r[i]*10){
            fileOutput << setprecision(1) << r[i] << " ";
        }else{
            fileOutput << setprecision(2) << r[i] << " ";
        }
    }
    fileOutput << "]" << endl;

    fileOutput << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    fileOutput << "V: " << setprecision(2) << V << endl;

    // S = 1000.00, n = 8
    // w = [ 0.05 0.2 0.12 0.18 0.15 0.15 0.1 0.05 ]
    // r = [ 0.1 0.01 0.05 0.02 0.02 0.05 0.01 0.03 ]
    // Rate of return of the portfolio: 0.0296
    // V: 1029.60
}

