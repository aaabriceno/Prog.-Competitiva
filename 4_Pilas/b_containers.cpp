#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    string cadena;
    int caso_numeros = 1;
    while (true) {
        cin >> cadena;
        if (cadena == "end") break;
        vector<stack<char>> pilas;
        for (char contenedor : cadena) {
            int pos = -1;
            // Buscar la pila adecuada (la primera cuyo top >= contenedor)
            for (int i = 0; i < pilas.size(); i++) {
                if (pilas[i].top() >= contenedor) {
                    if (pos == -1 || pilas[i].top() < pilas[pos].top()) {
                        pos = i;
                    }
                }
            }
            // Si se encontró una pila adecuada, colocar ahí
            if (pos != -1) {
                pilas[pos].push(contenedor);
            } else {
                stack<char> nueva;
                nueva.push(contenedor);
                pilas.push_back(nueva);
            }
        }
        cout << "Case " << caso_numeros++ << ": " << pilas.size() << endl;
    }
    return 0;
}
