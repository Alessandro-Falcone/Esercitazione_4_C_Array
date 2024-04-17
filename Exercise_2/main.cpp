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

        // dato che la funzione letturaDatiFileInput l'ho definita come una funzione booleana che ritorna "true" o "false"
        // se questa funzione ritorna "false" apparirà sullo schermo un messaggio d'errore
        // in quanto ci sarà stato qualche problema nell'apertura del file di input

        // messaggio di errore che dice che il file di input inserito non e' stato aperto correttamente
        cerr << "Errore: impossibile aprire il file di input." << endl;

        // inoltre l'esecuzione del programma si arresta e oltre al messaggio d'errore il programma ritorna 1
        return 1;

    }else{

        calcoloRateOfReturn(S, n, w, r, rateOfReturn, V);
        // vado a chiamare la funzione calcoloRateOfReturn che calcola il tasso di rendimento e V

        cout << "Successo: dati del file di input letti correttamente." << endl;
        cout << "Contenuto che andro' a scrivere sul file di output:" << endl;
    }

    // Stampa dei dati
    cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    cout << "w = " << arrayToString(n, w) << endl;
    cout << "v = " << arrayToString(n, r) << endl;
    cout << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    cout << "V: " << setprecision(2) << V << endl;

    string fileOutput = "./result.txt";

    if(!scritturaSuFileOutput(fileOutput, S, n, w, r, rateOfReturn, V)){ // Controllo che il file di output sia stato aperto correttamente

        // dato che la funzione scritturaSuFileOutput l'ho definita come una funzione booleana che ritorna "true" o "false"
        // se questa funzione ritorna "false" apparirà sullo schermo un messaggio d'errore
        // in quanto ci sarà stato qualche problema nell'apertura del file di output

        // messaggio di errore che dice che il file di output inserito non e' stato aperto correttamente
        cerr << "Errore: Impossibile aprire il file di output." << endl;

        // inoltre l'esecuzione del programma si arresta e oltre al messaggio d'errore il programma ritorna 1
        return 1;

    }else{

        cout << "Successo: risultati scritti correttamente sul file di output." << endl;
    }

    // dealloco la memoria
    delete[] w;
    delete[] r;

    // delete[] w (vale lo stesso per delete[] r)  dealloca la memoria assegnata dinamicamente all'array w (vale lo stesso per r)
    // precedentemente creato con l'operatore new[], questo comando libera la memoria
    // che era stata riservata per l'array puntato da w (vale lo stesso per r),
    // consentendo al sistema operativo di recuperare questa memoria per altri scopi.
    // Senza questo comando, potrebbe verificarsi una perdita di memoria (memory leak),
    // poiché la memoria precedentemente allocata non verrebbe mai rilasciata fino alla fine del programma.
    // Rendendo la memoria precedentemente occupata dall'array disponibile per altre allocazioni di memoria.

    return 0;
}


