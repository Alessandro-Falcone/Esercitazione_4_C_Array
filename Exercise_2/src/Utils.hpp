// #ifndef __UTILS_H // Header guards
// #define __UTILS_H

#pragma once
#include "iostream"

using namespace std;

// dichiarazione di tutte le funzioni che andrò ad utilizzare

// letturaDatiFileInput legge i dati di input dal file di input "data.csv"
// percorsoFileInput: nome del percorso del file di input
// S: la ricchezza iniziale
// n: il risultato del numero di assets
// w: il risultato del vettore dei pesi degli assets nel portafoglio
// r: il risultato del vettore dei tassi di rendimento delle attività
// ritorna il risultato della lettura: "true" successo mentre "false" errore

bool letturaDatiFileInput(const string& percorsoFileInput, double& S, size_t& n,
                          double*& w, double*& r);

// calcoloRateOfReturn calcola il tasso di rendimento del portafoglio e l'importo finale della ricchezza
// S: la ricchezza iniziale
// n: il numero di assets
// w: il vettore dei pesi degli assets nel portafoglio
// r: il vettore dei tassi di rendimento degli assets
// rateOfReturn: il risultato del tasso di rendimento del portafoglio
// V: il risultato della ricchezza finale

void calcoloRateOfReturnAndV(const double& S, const size_t& n,
                         const double* const& w, const double* const& r,
                         double& rateOfReturn, double& V);

// scritturaSuFileOutput scrive i risultati ottenuti sul file di output "result.txt"
// percorsoFileOutput: nome del percorso del file di output
// S: la ricchezza iniziale
// n: il numero di assets
// w: il vettore dei pesi degli assets nel portafoglio
// r: il vettore dei tassi di rendimento degli assets
// rateOfReturn: il tasso di rendimento del portafoglio
// V: la ricchezza finale
bool scritturaSuFileOutput(const string& percorsoFileOutput, const double& S, const size_t& n,
                              const double* const& w, const double* const& r,
                              double& rateOfReturn, double& V);

// esporta il vettore in una stringa
// n: dimensione del vettore
// v: vettore
// ritorna la stringa finale
string arrayToString(const size_t& n, const double* const& v);

// #endif
