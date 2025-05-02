#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

struct Equipo {
    int numeroEquipo;
    int resueltos[12];
    int penalidad[12];
    bool enviado;

    Equipo(int i = 0) {
        numeroEquipo = i;
        fill(resueltos, resueltos + 12, 0);
        fill(penalidad, penalidad + 12, 0);
        enviado = false;
    }
};

bool cmp(const Equipo& a, const Equipo& b) {
    if (a.resueltos[10] != b.resueltos[10])
        return a.resueltos[10] > b.resueltos[10];
    if (a.penalidad[10] != b.penalidad[10])
        return a.penalidad[10] < b.penalidad[10];
    return a.numeroEquipo < b.numeroEquipo;
}

int main() {
    int casosPrueba;
    string linea;

    cin >> casosPrueba;
    cin.ignore(); 
    getline(cin, linea);

    bool espacioVacio = false;

    while (casosPrueba--) {
        vector<Equipo> equipos;
        for (int i = 0; i < 105; i++) equipos.push_back(Equipo(i));

        while (getline(cin, linea)) {
            if (linea.empty()) break;

            int equipo, problema, tiempo;
            char estado;
            sscanf(linea.c_str(), "%d %d %d %c", &equipo, &problema, &tiempo, &estado);

            equipos[equipo].enviado = true;

            if (estado == 'C') {
                if (!equipos[equipo].resueltos[problema]) {
                    equipos[equipo].resueltos[problema] = 1;
                    equipos[equipo].penalidad[problema] += tiempo;
                }
            } else if (estado == 'I') {
                if (!equipos[equipo].resueltos[problema]) {
                    equipos[equipo].penalidad[problema] += 20;
                }
            }
            // 'R', 'U', 'E' son ignorados
        }
        // Cálculo final
        for (int i = 1; i < 105; i++) {
            for (int j = 1; j <= 9; j++) {
                if (equipos[i].resueltos[j]) {
                    equipos[i].resueltos[10]++;
                    equipos[i].penalidad[10] += equipos[i].penalidad[j];
                }
            }
        }
        sort(equipos.begin(), equipos.end(), cmp);
        if (espacioVacio) cout << endl;
        espacioVacio = true;
        for (auto& e : equipos) {
            if (e.enviado) {
                cout << e.numeroEquipo << " " << e.resueltos[10] << " " << e.penalidad[10] << endl;
            }
        }
    }
    return 0;
}