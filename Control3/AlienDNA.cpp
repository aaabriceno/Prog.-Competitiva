#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bitset<26>> bases(n);

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (char c : s)
                bases[i][c - 'a'] = 1;
        }

        int cortes = 0;
        bitset<26> comunes = bases[0];

        for (int i = 1; i < n; i++) {
            if ((comunes & bases[i]).any()) {
                comunes &= bases[i]; 
            } else {
                cortes++;
                comunes = bases[i]; 
            }
        }

        cout << cortes << "\n";
    }

    return 0;
}