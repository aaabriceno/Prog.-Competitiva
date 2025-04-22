#include <iostream>
#include <unordered_map>
#include <cmath>  
using namespace std;

int main() {
    int casos;
    cin >> casos;  

    while (casos--) {
        int n, m;
        cin >> n >> m;  
        unordered_map<int, int> lista_n, lista_m;  

        // Leer la primera lista y contar las frecuencias
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            lista_n[x]++;  // Incrementamos la frecuencia del número x
        }

        // Leer la segunda lista y contar las frecuencias
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            lista_m[x]++;  // Incrementamos la frecuencia del número x
        }

        int eliminaciones = 0;

        for (auto& elem : lista_n) {
            int num = elem.first;
            int freq1 = elem.second;
            int freq2 = lista_m[num];  
            eliminaciones += abs(freq1 - freq2);
        }
        for (auto& elem : lista_m) {
            int num = elem.first;
            if (lista_n.find(num) == lista_n.end()) {  
                eliminaciones += elem.second;
            }
        }
        cout << eliminaciones << endl;
    }

    return 0;
}