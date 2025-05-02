#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    int cantidadCasos;
    cin >> cantidadCasos;

    while (cantidadCasos--) {
        int cantidadMedicinas, cantidadTomasNecesarias;
        cin >> cantidadMedicinas >> cantidadTomasNecesarias;

        vector<string> nombresMedicinas(cantidadMedicinas);   
        vector<int> frecuenciasMedicinas(cantidadMedicinas);  
        set<pair<int, int>> agenda;                          

        // Leer los datos de cada medicina
        for (int prioridad = 0; prioridad < cantidadMedicinas; prioridad++) {
            cin >> nombresMedicinas[prioridad] >> frecuenciasMedicinas[prioridad];
            agenda.insert({frecuenciasMedicinas[prioridad], prioridad}); // primera toma
        }

        // Simular las tomas de medicina
        for (int i = 0; i < cantidadTomasNecesarias; i++) {
            auto siguienteToma = *agenda.begin();
            agenda.erase(agenda.begin());
            int momento = siguienteToma.first;
            int indiceMedicina = siguienteToma.second;
            cout << momento << " " << nombresMedicinas[indiceMedicina] << endl;
            // Agendar la próxima toma de esta medicinaze
            int proximoMomento = momento + frecuenciasMedicinas[indiceMedicina];
            agenda.insert({proximoMomento, indiceMedicina});
        }
    }
    return 0;
}