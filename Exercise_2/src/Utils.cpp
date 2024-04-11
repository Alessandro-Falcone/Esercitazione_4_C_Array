#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// funzioni
bool letturaDatiFileDataCSV(const string& fileIn, double& S, size_t& n, double*& w, double*& r){

    ifstream fileInput;
    fileInput.open(fileIn); // apre il file di input

    if(fileInput.fail()){ // controllo se il file di input viene

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

void scritturaSuFileResultTXT(ostream& fileOutput, const double& S, const size_t& n,
                              const double* const& w, const double* const& r,
                              double& rateOfReturn, double& V){

    fileOutput << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    fileOutput << "w = [ ";
    for(unsigned int i = 0; i < n; i++){
        fileOutput << w[i] << " ";
    }
    fileOutput << "]" << endl;

    // if (ceil(w[i]*10)==w[i]*10){
    //     out << setprecision(1) << w[i]<< " ";
    // }
    // else{
    //     out << setprecision (2) << w[i] << " " ;
    // }

    fileOutput << "v = [ ";
    for(unsigned int i = 0; i < n; i++){
        fileOutput << r[i] << " ";
    }
    fileOutput << "]" << endl;

    fileOutput << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    fileOutput << "V: " << setprecision(2) << V << endl;

}

