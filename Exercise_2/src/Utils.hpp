#ifndef __UTILS_H // Header guards
#define __UTILS_H
#include <iostream>
#include <string>

using namespace std;

// funzioni
bool letturaDatiFileInput(const string& fileIn, double& S, size_t& n, double*& w, double*& r);

void calcoloRateOfReturn(const double& S, const size_t& n, const double* const& w, const double* const& r,
                         double& rateOfReturn, double& V);



#endif
