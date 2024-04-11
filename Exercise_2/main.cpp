#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main(){

    string fileInput = "data.csv";

    double S = 0.0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double rateOfReturn = 0;
    double V = 0;

    if(letturaDatiFileInput(fileInput, S, n, w, r) != true){
        cerr << "Errore nell'apertura del file di input" << endl;
        return 1;
    }

    calcoloRateOfReturn(S, n, w, r, rateOfReturn, V);

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

    fileOutput << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    fileOutput << "V: " << setprecision(2) << V << endl;

    delete[] w;
    delete[] r;

    fileOutput.close();

    return 0;
}


