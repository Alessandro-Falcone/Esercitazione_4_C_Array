// #ifndef __UTILS_H // Header guards
// #define __UTILS_H

#pragma once
#include "iostream"

using namespace std;

// dichiarazione di tutte le funzioni che andrò ad utilizzare

// letturaDatiFileInput legge i dati di input dal file "data.csv"
// percorsoFileInput: nome del percorso del file di input
// S: la conseguente ricchezza iniziale
// n: il numero risultante di beni
// w: il vettore risultante dei pesi degli asset nel portafoglio
// r: il vettore risultante dei tassi di rendimento delle attività
// ritorna il risultato della lettura: "true" successo mentre "false" errore

bool letturaDatiFileInput(const string& percorsoFileInput, double& S,
                            size_t& n, double*& w, double*& r);

// calcoloRateOfReturn calcola il tasso di rendimento del portafoglio e l'importo finale della ricchezza
// S: la ricchezza iniziale
// n: il numero di asset
// w: il vettore dei pesi degli asset nel portafoglio
// r: il vettore dei tassi di rendimento degli asset
// rateOfReturn: il tasso di rendimento risultante del portafoglio
// V: la ricchezza finale risultante

void calcoloRateOfReturn(const double& S, const size_t& n,
                         const double* const& w, const double* const& r,
                         double& rateOfReturn, double& V);

// scritturaSuFileOutput stampa i dati (su un flusso di output)
// percorsoFileOutput: oggetto di tipo ostream
// S: la ricchezza iniziale
// n: il numero di asset
// w: il vettore dei pesi degli asset nel portafoglio
// r: il vettore dei tassi di rendimento degli asset
// rateOfReturn: il tasso di rendimento del portafoglio
// V: la ricchezza finale
bool scritturaSuFileOutput(const string& percorsoFileOutput, const double& S, const size_t& n,
                              const double* const& w, const double* const& r,
                              double& rateOfReturn, double& V);

string arrayToString(const size_t& n, const double* const& v);

// #endif
