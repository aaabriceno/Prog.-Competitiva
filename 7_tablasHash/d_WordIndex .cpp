#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long comb(int n, int k) {
    if (k > n) return 0;
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

long long get_posicion(const string& palabra) {
    int len = palabra.length();
    long long position = 0;

   
    for (int k = 1; k < len; k++) {
        position += comb(26, k);
    }

   
    int prev = -1;
    for (int i = 0; i < len; i++) {
        int current = palabra[i] - 'a';
        
        for (int j = prev + 1; j < current; j++) {
            position += comb(26 - j - 1, len - i - 1);
        }
        prev = current;
    }

    return position + 1;
}

bool palabra_valida(const string& palabra) {
    for (int i = 1; i < palabra.length(); i++) {
        if (palabra[i] <= palabra[i - 1]) return false; 
    }
    return true;
}

int main() {
    string palabra;
    while (getline(cin, palabra)) {
        if (palabra_valida(palabra)) {
            // Si es válida, calculamos la posición lexicográfica
            cout << get_posicion(palabra) << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
