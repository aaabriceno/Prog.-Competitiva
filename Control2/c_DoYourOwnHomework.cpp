#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Función para verificar en qué categoría cae el tiempo de entrega
string verificarTiempo(int diasLimite, int diasRequeridos) {
    if (diasRequeridos <= diasLimite)
        return "Yesss";
    if (diasRequeridos <= diasLimite + 5)
        return "Late";
    return "Do your own homework!";
}

int main() {
    int cantidadCasos;
    cin >> cantidadCasos;
    cin.ignore();

    for (int caso = 1; caso <= cantidadCasos; caso++) {
        unordered_map<string, int> materias; // Almacena materia -> días que necesita Sparrow
        int cantidadMaterias;
        cin >> cantidadMaterias;

        for (int i = 0; i < cantidadMaterias; i++) {
            string nombreMateria;
            int diasNecesarios;
            cin >> nombreMateria >> diasNecesarios;
            materias[nombreMateria] = diasNecesarios;
        }

        int diasLimite;
        cin >> diasLimite;

        string materiaPendiente;
        cin >> materiaPendiente;

        // Mostrar resultado según las reglas dadas
        cout << "Case " << caso << ": ";
        if (materias.count(materiaPendiente)) {
            cout << verificarTiempo(diasLimite, materias[materiaPendiente]) << endl;
        } else {
            cout << "Do your own homework!" << endl;
        }
    }
    return 0;
}
