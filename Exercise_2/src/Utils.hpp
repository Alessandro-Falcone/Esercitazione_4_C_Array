#ifndef __UTILS_H // Header guards
#define __UTILS_H
#include <iostream>
#include <string>

using namespace std;

// dichiarazione di tutte le funzioni che andrò ad utilizzare

// letturaDatiFileInput legge i dati di input dal file "data.csv"
// percorsoFileInput nome del percorso del file di input
// S: la conseguente ricchezza iniziale
// n: il numero risultante di beni
// w: il vettore risultante dei pesi degli assetin portafoglio
// r: il vettore risultante dei tassi di rendimento delle attività
// risultato della lettura: "true" successo mentre "false" errore

bool letturaDatiFileInput(const string& percorsoFileInput, double& S,
                            size_t& n, double*& w, double*& r);

void calcoloRateOfReturn(const double& S, const size_t& n,
                         const double* const& w, const double* const& r,
                         double& rateOfReturn, double& V);

void scritturaSuFileOutput(ostream& fileOutput, const double& S, const size_t& n,
                              const double* const& w, const double* const& r,
                              double& rateOfReturn, double& V);



#endif
