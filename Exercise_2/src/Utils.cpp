#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// funzioni
bool letturaDatiFileInput(const string& fileIn, double& S, size_t& n, double*& w, double*& r){

    ifstream fileInput;
    fileInput.open(fileIn);

    if(fileInput.fail()){
        return false;
    }else{

        string line;
        S = 0.0;
        n = 0;

        getline(fileInput, line, ';');
        getline(fileInput, line);
        S = stod(line);

        getline(fileInput, line, ';');
        getline(fileInput, line);
        n = stoi(line);

        getline(fileInput, line);
        w = new double[n];
        r = new double[n];

        for(unsigned int i = 0; i < n; i++){
            getline(fileInput, line, ';');
            w[i] = stod(line);
            getline(fileInput, line);
            r[i] = stod(line);
        }
        return true;
    }
}

void calcoloRateOfReturn(const double& S, const size_t& n, const double* const& w, const double* const& r,
                         double& rateOfReturn, double& V){
    rateOfReturn = 0;
    V = S;
    for(unsigned int i = 0; i < n; i++){
        rateOfReturn = w[i]*r [i] + rateOfReturn;
        V = S*w[i]*r[i] + V;
    }
}
