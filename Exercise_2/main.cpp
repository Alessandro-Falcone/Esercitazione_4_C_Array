#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main(){

    string fileInput = "./data.csv";

    double S = 0.0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double rateOfReturn = 0;
    double V = 0;

    if(letturaDatiFileInput(fileInput, S, n, w, r) != true){ // Controllo che il file di input sia stato aperto correttamente

        // dato che la funzione letturaDatiFileInput l'ho definita come una funzione booleana che ritorna "true" o "false"
        // se questa funzione ritorna "false" apparirà sullo schermo questo messaggio d'errore
        // in quanto ci sarà stato qualche problema nell'apertura del file di input

        cerr << "Errore nell'apertura del file di input" << endl;

        // inoltre l'esecuzione del programma si arresta e oltre al messaggio d'errore ritorna anche 1
        return 1;

    }else{

        calcoloRateOfReturn(S, n, w, r, rateOfReturn, V);
        // vado a chiamare la funzione calcoloRateOfReturn che calcola RateOfReturn e V

        cout << "Successo nella lettura dei dati del file di input" << endl;
        cout << "Stampo a schermo l'anteprima di quello che andro' a scrivere sul file di output" << endl;
    }

    cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;

    cout << "w = " << arrayToString(n, w) << endl;
    cout << "v = " << arrayToString(n, r) << endl;

    cout << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    cout << "V: " << setprecision(2) << V << endl;

    string fileOutput = "./result.txt";

    if(scritturaSuFileOutput(fileOutput, S, n, w, r, rateOfReturn, V) != true){ // Controllo che il file di output sia stato aperto correttamente

        // dato che la funzione scritturaSuFileOutput l'ho definita come una funzione booleana che ritorna "true" o "false"
        // se questa funzione ritorna "false" apparirà sullo schermo questo messaggio d'errore
        // in quanto ci sarà stato qualche problema nell'apertura del file di output

        // messaggio di errore che dice che il file di output inserito non e' stato aperto correttamente
        cerr << "Errore nell'apertura del file di output che hai inserito\n" << endl;

        // inoltre l'esecuzione del programma si arresta e oltre al messaggio d'errore ritorna anche 1
        return 1;

    }else{

        cout << "Successo della scrittura sul file di output" << endl;
    }

    delete[] w;
    delete[] r;

    // delete[] w (vale lo stesso per delete[] r)  dealloca la memoria assegnata dinamicamente all'array w (vale lo stesso per r)
    // precedentemente creato con l'operatore new[], questo comando libera la memoria
    // che era stata riservata per l'array puntato da w (vale lo stesso per r),
    // consentendo al sistema operativo di recuperare questa memoria per altri scopi.
    // Senza questo comando, potrebbe verificarsi una perdita di memoria (memory leak),
    // poiché la memoria precedentemente allocata non verrebbe mai rilasciata fino alla fine del programma.
    // Rendendo la memoria precedentemente occupata dall'array disponibile per altre allocazioni di memoria.
    // È importante utilizzare delete[] quando si dealloca la memoria di un array allocato dinamicamente
    // per garantire la corretta gestione della memoria.


    // S = 1000.00, n = 8
    // w = [ 0.05 0.2 0.12 0.18 0.15 0.15 0.1 0.05 ]
    // r = [ 0.1 0.01 0.05 0.02 0.02 0.05 0.01 0.03 ]
    // Rate of return of the portfolio: 0.0296
    // V: 1029.60

    return 0;
}


