#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;



int main(){

    ifstream fileInput("data.csv"); // Sostituisci "nome_file.txt" con il nome effettivo del tuo file

    if(fileInput.fail()){
        cerr << "Errore nell'apertura del file di input" << endl;
        return 1;
    }

    string line;
    double S = 0.0;
    size_t n = 0;
    string w;
    string r;

    getline(fileInput, line, ';');
    getline(fileInput, line);
    S = stod(line);

    getline(fileInput, line, ';');
    getline(fileInput, line);
    n = stoi(line);

    double *w1 = new double[n];
    double *r1 = new double[n];
    getline(fileInput, line, ';');
    w = line;
    getline(fileInput, line);
    r = line;

    for(unsigned int i = 0; i < n; i++){
        getline(fileInput, line, ';');
        w1[i] = stod(line);
        getline(fileInput, line);
        r1[i] = stod(line);
    }

    cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    cout << "w = [ ";
    for(unsigned int i = 0; i < n; i++){
        cout << w1[i] << " ";
    }
    cout << "]" << endl;

    cout << "v = [ ";
    for(unsigned int i = 0; i < n; i++){
        cout << r1[i] << " ";
    }
    cout << "]" << endl;

    double rateOfReturn = 0;
    double V = S;

    // for(unsigned int i=0;i<n; i++){
    //     rateOfReturn = w1[i]*r1[i] + rateOfReturn;
    //     // cout << setprecision(4) << rateOfReturn  << " ";
    //     V = S*w1[i]*r1[i] + V;
    //     // cout << setprecision(2) << V << " ";
    // }

    cout << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    cout << "V: " << setprecision(2) << V << endl;

    ofstream fileOutput("result.txt");

    fileOutput << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    fileOutput << "w = [ ";
    for(unsigned int i = 0; i < n; i++){
        fileOutput << w1[i] << " ";
    }
    fileOutput << "]" << endl;

    fileOutput << "v = [ ";
    for(unsigned int i = 0; i < n; i++){
        fileOutput << r1[i] << " ";
    }
    fileOutput << "]" << endl;


    for(unsigned int i=0;i<n; i++){
        rateOfReturn = w1[i]*r1[i] + rateOfReturn;
        // cout << setprecision(4) << rateOfReturn  << " ";
        V = S*w1[i]*r1[i] + V;
        // cout << setprecision(2) << V << " ";
    }

    fileOutput << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    fileOutput << "V: " << setprecision(2) << V << endl;

    delete[] w1;
    delete[] r1;

    fileInput.close();
    fileOutput.close();

    return 0;
}

