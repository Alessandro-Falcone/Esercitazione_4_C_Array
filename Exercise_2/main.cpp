#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main(){

    double S = 0.0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double rateOfReturn = 0;
    double V = 0;

    string fileInput = "./data.csv";

    if(!letturaDatiFileInput(fileInput, S, n, w, r)){ // Controllo che il file di input sia stato aperto correttamente

        // messaggio di errore che dice che il file di input inserito non e' stato aperto correttamente
        cerr << "Errore: impossibile aprire il file di input." << endl;

        // l'esecuzione del programma si arresta e oltre al messaggio d'errore viene restituito 1
        return 1;

    }else{

        calcoloRateOfReturnAndV(S, n, w, r, rateOfReturn, V);
        // vado a chiamare la funzione calcoloRateOfReturnAndV che calcola il tasso di rendimento (rateOfReturn) e la ricchezza finale (V)

        cout << "Successo: dati del file di input letti correttamente." << endl;
        cout << "Contenuto che andro' a scrivere sul file di output:" << endl;

        // Stampa dei dati
        cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
        cout << "w = " << arrayToString(n, w) << endl;
        cout << "r = " << arrayToString(n, r) << endl;
        cout << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
        cout << "V: " << setprecision(2) << V << endl;
    }

    string fileOutput = "./result.txt";

    if(!scritturaSuFileOutput(fileOutput, S, n, w, r, rateOfReturn, V)){ // Controllo che il file di output sia stato aperto correttamente

        // messaggio di errore che dice che il file di output inserito non e' stato aperto correttamente
        cerr << "Errore: Impossibile aprire il file di output." << endl;

        // l'esecuzione del programma si arresta e oltre al messaggio d'errore viene restituito 1
        return 1;

    }else{

        cout << "Successo: risultati scritti correttamente sul file di output." << endl;
    }

    // deallocazione della memoria
    delete[] w;
    delete[] r;

    // delete[] w (vale lo stesso per delete[] r) dealloca la memoria assegnata dinamicamente all'array w (vale lo stesso per r)
    // precedentemente creato con l'operatore new[], consentendo al sistema operativo di recuperare questa memoria per altri scopi.
    // Senza questo comando, potrebbe verificarsi una perdita di memoria (memory leak),
    // in quanto la memoria precedentemente allocata non verrebbe mai rilasciata fino alla fine del programma.

    return 0;
}


