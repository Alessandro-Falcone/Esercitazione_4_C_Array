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

    cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    cout << "w = [ ";
    for(unsigned int i = 0; i < n; i++){
        if((int) (w[i]*10) == w[i]*10){
            cout << setprecision(1) << w[i] << " ";
        }else{
            cout << setprecision(2) << w[i] << " ";
        }
    }
    cout << "]" << endl;

    cout << "v = [ ";
    for(unsigned int i = 0; i < n; i++){
        if((int) (r[i]*10) == r[i]*10){
            cout << setprecision(1) << r[i] << " ";
        }else{
            cout << setprecision(2) << r[i] << " ";
        }
    }
    cout << "]" << endl;

    cout << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    cout << "V: " << setprecision(2) << V << endl;

    string fileOut = "result.txt";
    ofstream fileOutput;
    fileOutput.open(fileOut);

    if(fileOutput.fail()){ // Controllo che il file di output sia stato aperto correttamente

        cerr << "errore nell'apertura del file di output che hai inserito\n" << endl;
        // Messaggio di errore che dice che il file di output inserito non e' stato aperto correttamente

        return 1;

    }else{
        scritturaSuFileResultTXT(fileOutput, S, n, w, r, rateOfReturn, V);
    }

    fileOutput.close(); // chiudo il file di output

    delete[] w;
    delete[] r;

    // S = 1000.00, n = 8
    // w = [ 0.05 0.2 0.12 0.18 0.15 0.15 0.1 0.05 ]
    // r = [ 0.1 0.01 0.05 0.02 0.02 0.05 0.01 0.03 ]
    // Rate of return of the portfolio: 0.0296
    // V: 1029.60

    return 0;
}


