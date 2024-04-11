#include "Utils.hpp"
#include <iostream>

// funzioni
void ComputeRateOfReturn(const double& S, const size_t& n, const double* const& w, const double* const& r,
                         double& rateOfReturn, double& V){
    rateOfReturn = 0;
    V = S;
    for(unsigned int i = 0; i < n; i++){
        rateOfReturn = w[i]*r [i] + rateOfReturn;
        V = S*w[i]*r[i] + V;
    }
}
