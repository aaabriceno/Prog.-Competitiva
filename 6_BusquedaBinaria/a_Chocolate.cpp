#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int chocolates[3][131072];

int main() {
    int T, caso = 0;
    cin >> T;
    
    while (T--) {
        int cantidadChocolates[3], tipoChocolate;
        
        // Leer la cantidad de chocolates para cada persona
        for (int i = 0; i < 3; i++) {
            cin >> cantidadChocolates[i];
        }

        // Leer los chocolates de cada persona
        int totalChocolates = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cantidadChocolates[i]; j++) {
                cin >> chocolates[i][j];
            }
            sort(chocolates[i], chocolates[i] + cantidadChocolates[i]);
            cantidadChocolates[i] = unique(chocolates[i], chocolates[i] + cantidadChocolates[i]) - chocolates[i];
        }

        // Inicializar índices y resultados
        int idx[3] = {};
        int resultados[3][2] = {};  // resultados[i][0] = únicos, resultados[i][1] = faltantes

        while (true) {
            int minimoChocolate = INT_MAX;

            // Buscar el chocolate mínimo en las tres personas
            for (int i = 0; i < 3; i++) {
                if (idx[i] < cantidadChocolates[i]) {
                    minimoChocolate = min(minimoChocolate, chocolates[i][idx[i]]);
                }
            }

            if (minimoChocolate == INT_MAX) break;  // Si no hay más chocolates, termina

            int mascara = 0;

            // ActualizO la máscara de las personas que tienen el chocolate mínimo
            for (int i = 0; i < 3; i++) {
                if (idx[i] < cantidadChocolates[i] && chocolates[i][idx[i]] == minimoChocolate) {
                    mascara |= (1 << i);
                }
            }

            // Actualizo los resultados basados en la máscara
            for (int i = 0; i < 3; i++) {
                if (mascara == (1 << i)) {
                    resultados[i][0]++;  // Chocolate único para esta persona
                }
                if (mascara == (((1 << 3) - 1) ^ (1 << i))) {
                    resultados[i][1]++;  // Chocolate faltante para esta persona
                }
            }

            for (int i = 0; i < 3; i++) {
                if (idx[i] < cantidadChocolates[i] && chocolates[i][idx[i]] == minimoChocolate) {
                    idx[i]++;
                }
            }
        }

        cout << "Case #" << ++caso << ":\n";
        for (int i = 0; i < 3; i++) {
            cout << resultados[i][0] << " " << resultados[i][1] << "\n";
        }
    }

    return 0;
}