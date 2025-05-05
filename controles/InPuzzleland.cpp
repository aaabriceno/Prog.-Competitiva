#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int MAX_NODOS = 15;

int totalNodos;
unordered_map<char, int> letraANodo;
char nodoALetra[MAX_NODOS];
vector<int> grafo[MAX_NODOS];

bool visitado[1 << MAX_NODOS][MAX_NODOS];
string caminoGuardado[1 << MAX_NODOS][MAX_NODOS];

string encontrarCamino(int nodoActual, int mascaraVisitados, int nodoDestino) {
    if (mascaraVisitados == (1 << totalNodos) - 1) {
        if (nodoActual == nodoDestino) return string(1, nodoALetra[nodoActual]);
        else return "";
    }

    if (visitado[mascaraVisitados][nodoActual])
        return caminoGuardado[mascaraVisitados][nodoActual];

    visitado[mascaraVisitados][nodoActual] = true;
    string mejorCamino = "";

    for (int vecino : grafo[nodoActual]) {
        if (!(mascaraVisitados & (1 << vecino))) {
            string siguienteCamino = encontrarCamino(vecino, mascaraVisitados | (1 << vecino), nodoDestino);
            if (!siguienteCamino.empty()) {
                string nuevoCamino = nodoALetra[nodoActual] + siguienteCamino;
                if (mejorCamino.empty() || nuevoCamino < mejorCamino) {
                    mejorCamino = nuevoCamino;
                }
            }
        }
    }
    return caminoGuardado[mascaraVisitados][nodoActual] = mejorCamino;
}

int main() {
    int casosPrueba;
    cin >> casosPrueba;
    string lineaVacia;
    getline(cin, lineaVacia); // Consumir la linea vacia

    for (int caso = 1; caso <= casosPrueba; ++caso) {
        getline(cin, lineaVacia); // Linea en blanco
        int numeroNodos, numeroAristas;
        cin >> numeroNodos >> numeroAristas;

        letraANodo.clear();
        for (int i = 0; i < MAX_NODOS; ++i) grafo[i].clear();

        totalNodos = numeroNodos;
        for (int i = 0; i < numeroNodos; ++i) {
            char letra;
            cin >> letra;
            letraANodo[letra] = i;
            nodoALetra[i] = letra;
        }

        int nodoInicio = 0;
        int nodoFin = numeroNodos - 1;

        for (int i = 0; i < numeroAristas; ++i) {
            char nodoA, nodoB;
            cin >> nodoA >> nodoB;
            int idA = letraANodo[nodoA];
            int idB = letraANodo[nodoB];
            grafo[idA].push_back(idB);
            grafo[idB].push_back(idA);
        }

        memset(visitado, false, sizeof(visitado));
        string resultado = encontrarCamino(nodoInicio, 1 << nodoInicio, nodoFin);

        cout << "Case " << caso << ": ";
        if (resultado.empty()) {
            cout << "impossible" << endl;
        } else {
            cout << resultado << endl;
        }
    }

    return 0;
}