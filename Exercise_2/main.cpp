#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("data.csv"); // Sostituisci "nome_file.txt" con il nome effettivo del tuo file

    if (!file.is_open()) {
        cerr << "Impossibile aprire il file." << endl;
        return 1;
    }

    string line;
    unsigned int size;
    while (getline(file, line)) {
        string filteredLine;
        size = line.length();
        for (unsigned int i = 0; i < size; i++) {
            char c = line[i];
            if (c != ';') {
                filteredLine += c;
            }
        }
        cout << filteredLine << endl;
    }

    file.close();

    return 0;
}

