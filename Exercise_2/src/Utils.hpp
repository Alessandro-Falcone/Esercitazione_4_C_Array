#ifndef __UTILS_H // Header guards
#define __UTILS_H
#include <iostream>
#include <string>

using namespace std;

// dichiarazione di tutte le funzioni che andrò ad utilizzare

bool letturaDatiFileDataCSV(const string& fileIn, double& S,
                          size_t& n, double*& w, double*& r);

void calcoloRateOfReturn(const double& S, const size_t& n,
                         const double* const& w, const double* const& r,
                         double& rateOfReturn, double& V);

void scritturaSuFileResultTXT(ostream& fileOutput, const double& S, const size_t& n,
                              const double* const& w, const double* const& r,
                              double& rateOfReturn, double& V);



#endif
