// #ifndef __UTILS_H // Header guards
// #define __UTILS_H

#pragma once
#include "iostream"

using namespace std;

// dichiarazione di tutte le funzioni che andrò ad utilizzare

// letturaDatiFileInput legge i dati di input dal file di input ("data.csv")
// percorsoFileInput: nome del percorso del file di input
// S: lettura della ricchezza iniziale
// n: lettura del numero di assets
// w: lettura del vettore dei pesi degli assets nel portafoglio
// r: lettura del vettore dei tassi di rendimento delle attività
// restituisce il risultato della lettura: "true" successo mentre "false" errore
bool letturaDatiFileInput(const string& percorsoFileInput, double& S, size_t& n,
                          double*& w, double*& r);

// calcoloRateOfReturnAndV calcola il tasso di rendimento del portafoglio (RateOfReturn) e l'importo finale della ricchezza (V)
// S: la ricchezza iniziale
// n: il numero di assets
// w: il vettore dei pesi degli assets nel portafoglio
// r: il vettore dei tassi di rendimento degli assets
// rateOfReturn: il risultato del tasso di rendimento del portafoglio
// V: il risultato della ricchezza finale
void calcoloRateOfReturnAndV(const double& S, const size_t& n,
                             const double* const& w, const double* const& r,
                             double& rateOfReturn, double& V);

// scritturaSuFileOutput scrive i risultati ottenuti sul file di output ("result.txt")
// percorsoFileOutput: nome del percorso del file di output
// S: scrittura della ricchezza iniziale
// n: scrittura del numero di assets
// w: scrittura del vettore dei pesi degli assets nel portafoglio
// r: scrittura del vettore dei tassi di rendimento degli assets
// rateOfReturn: scrittura del tasso di rendimento del portafoglio
// V: scrittura della ricchezza finale
// restituisce il risultato della scrittura: "true" successo mentre "false" errore
bool scritturaSuFileOutput(const string& percorsoFileOutput, const double& S, const size_t& n,
                           const double* const& w, const double* const& r,
                           double& rateOfReturn, double& V);

// esporta il vettore in una stringa
// n: dimensione del vettore
// v: vettore
// ritorna la stringa finale
string arrayToString(const size_t& n, const double* const& v);

// #endif
