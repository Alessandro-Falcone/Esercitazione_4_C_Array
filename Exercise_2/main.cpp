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

        // dato che la funzione letturaDatiFileInput l'ho definita come una funzione booleana che ritorna "true" o "false"
        // se questa funzione ritorna "false" apparirà sullo schermo questo messaggio d'errore
        // in quanto c'è stato qualche problema

        cerr << "Errore nell'apertura del file di input" << endl;

        // inoltre l'esecuzione del programma si arresta e oltre al messaggio d'errore ritorna anche 1
        return 1;
    }

    calcoloRateOfReturn(S, n, w, r, rateOfReturn, V);
    // vado a chiamare la funzione calcoloRateOfReturn che calcola il RateOfReturn e V

    scritturaSuFileOutput(cout, S, n, w, r, rateOfReturn, V);

    string fileOut = "result.txt";
    ofstream fileOutput;
    fileOutput.open(fileOut); // apro il file di output

    if(fileOutput.fail()){ // Controllo che il file di output sia stato aperto correttamente

        cerr << "errore nell'apertura del file di output che hai inserito\n" << endl;
        // messaggio di errore che dice che il file di output inserito non e' stato aperto correttamente

        // inoltre l'esecuzione del programma si arresta e oltre al messaggio d'errore ritorna anche 1
        return 1;

    }else{
        scritturaSuFileOutput(fileOutput, S, n, w, r, rateOfReturn, V);
        // se il file di output è stato aperto correttamente vado a chiamare la funzione scritturaSuFileOutput
        // che ho definito in modo tale da scrivere sul file di output
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


