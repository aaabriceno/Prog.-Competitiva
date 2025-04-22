#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    int n = 0;
    while (true) {
        cin >> n;

        if (n == 0)
            break;

        multiset <int> numeros;
        long long int precioTotal = 0;

        for (int i = 0; i < n; ++i) {
            int k = 0; cin >> k;

            for (int j = 0; j < k; ++j) {
                int t; cin >> t;
                numeros.insert(t);
            }

            // Comprueba si hay al menos dos billetes para seleccionar
            if (numeros.size() >= 2) {
                int masPequeño = *numeros.begin();
                numeros.erase(numeros.begin());

                int biggest = *numeros.rbegin();
                numeros.erase(prev(numeros.end())); // Use prev para obtener el iterador antes de end()

                precioTotal += (biggest - masPequeño);
            } else if (numeros.size() == 1) {
                // Si hay un solo billete, la diferencia es 0
                numeros.erase(numeros.begin());
            }
            // Si numeros.size() is 0, no se procesa nada
        }
        cout << precioTotal << endl;
    }

    return 0;
}