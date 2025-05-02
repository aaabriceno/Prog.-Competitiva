#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class RedEmpresarial {
private:
    vector<int> padre;
    vector<int> distancia;

public:
    RedEmpresarial(int n) {
        padre.resize(n + 1);
        distancia.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            padre[i] = i;
        }
    }

    int encontrarCentro(int empresa) {
        if (empresa == padre[empresa]) return empresa;
        int centro = encontrarCentro(padre[empresa]);
        distancia[empresa] += distancia[padre[empresa]];
        return padre[empresa] = centro;
    }

    void unirEmpresas(int empresaA, int empresaB) {
        padre[empresaA] = empresaB;
        distancia[empresaA] = abs(empresaA - empresaB) % 1000;
    }

    int obtenerDistancia(int empresa) {
        encontrarCentro(empresa);
        return distancia[empresa];
    }
};

int main() {
    int casosPrueba;
    cin >> casosPrueba;

    for (int caso = 1; caso <= casosPrueba; ++caso) {
        int cantidadEmpresas;
        cin >> cantidadEmpresas;
        RedEmpresarial red(cantidadEmpresas);

        char comando[10];
        while (cin >> comando) {
            if (comando[0] == 'O') break;

            if (comando[0] == 'E') {
                int empresa;
                cin >> empresa;
                cout << red.obtenerDistancia(empresa) << "\n";
            } else if (comando[0] == 'I') {
                int empresaA, empresaB;
                cin >> empresaA >> empresaB;
                red.unirEmpresas(empresaA, empresaB);
            }
        }
    }

    return 0;
}