#include <iostream>
using namespace std;

void bafana_bafana(int T) {
    for (int t = 1; t <= T; t++) {
        int N, K, P;
        cin >> N >> K >> P;
        int final_position = ((K - 1) + P) % N + 1; // Cálculo del jugador final
        cout << "Case " << t << ": " << final_position << endl;
    }
}

int main() {
    int T;
    cin >> T; // Número de casos de prueba
    bafana_bafana(T);
    return 0;
}