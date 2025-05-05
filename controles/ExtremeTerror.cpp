#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T; cin >> T;
    for(int caso = 1; caso <= T; caso++){
        long N, K;
        cin >> N >> K;

        vector<long long> X(N), Y(N), beneficio(N);
        for(int i = 0; i < N; i++) cin >> X[i];
        for(int i = 0; i < N; i++){
            cin >> Y[i];
            beneficio[i] = Y[i] - X[i];
        }

        sort(beneficio.begin(), beneficio.end(), greater<long long>());

        long long ganancia = 0;
        for(int i = 0; i < N; i++){
            if (i < N - K || beneficio[i] > 0)
                ganancia += beneficio[i];
            else
                break;
        }

        cout << "Case " << caso << ": ";
        if (ganancia > 0) {
            cout << ganancia << "\n";
        }
        else{
            cout << "No Profit\n";
        }
    }
    return 0;
}
