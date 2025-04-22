#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Para consumir el salto de línea después del número de casos

    while (n--) {
        string linea;
        // Saltar líneas vacías entre casos
        while (getline(cin, linea)) {
            if (!linea.empty()) break;
        }

        int p = stoi(linea);  // Convertir la línea leída en número de lugares
        vector<int> numero_vecinos(p + 1, 0);
        vector<vector<int>> grafo_vecinos(p + 1);

        for (int i = 1; i <= p; ++i) {
            getline(cin, linea);
            stringstream extraer_num(linea);
            int vecino;
            while (extraer_num >> vecino) {
                grafo_vecinos[i].push_back(vecino);
                numero_vecinos[i]++;
            }
        }

        int min_vecinos = p;
        for (int i = 1; i <= p; ++i) {
            min_vecinos = min(min_vecinos, numero_vecinos[i]);
        }

        vector<int> mejor_lugar;
        for (int i = 1; i <= p; ++i) {
            if (numero_vecinos[i] == min_vecinos) {
                mejor_lugar.push_back(i);
            }
        }

        sort(mejor_lugar.begin(), mejor_lugar.end());

        for (size_t i = 0; i < mejor_lugar.size(); ++i) {
            cout << mejor_lugar[i] << (i == mejor_lugar.size() - 1 ? "" : " ");
        }
        cout << endl;

        if (n > 0) {
            cout << endl;
        }
    }
    return 0;
}