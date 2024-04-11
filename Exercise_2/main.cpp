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

    if(letturaDatiFileDataCSV(fileInput, S, n, w, r) != true){
        cerr << "Errore nell'apertura del file di input" << endl;
        return 1;
    }

    calcoloRateOfReturn(S, n, w, r, rateOfReturn, V);

    // cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    // cout << "w = [ ";
    // for(unsigned int i = 0; i < n; i++){
    //     cout << w[i] << " ";
    // }
    // cout << "]" << endl;

    // cout << "v = [ ";
    // for(unsigned int i = 0; i < n; i++){
    //     cout << r[i] << " ";
    // }
    // cout << "]" << endl;

    // cout << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    // cout << "V: " << setprecision(2) << V << endl;

    string fileOut = "result.txt";
    ofstream fileOutput;
    fileOutput.open(fileOut);

    if(fileOutput.is_open()){
       scritturaSuFileResultTXT(fileOutput, S, n, w, r, rateOfReturn, V);
    }

    fileOutput.close();

    delete[] w;
    delete[] r;



    return 0;
}


