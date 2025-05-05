#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<int> pre_factorial(int max_n) {
    vector<int> factoriales;
    int i = 1;
    int fact = 1;

    while (fact <= max_n) {
        factoriales.push_back(fact);
        i++;
        fact *= i;
    }

    return factoriales;
}

int minimo_factorial(int N, const vector<int>& factoriales) {
    vector<int> dp(N + 1, numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int f : factoriales) {
            if (f <= i && dp[i - f] != numeric_limits<int>::max()) {
                dp[i] = min(dp[i], dp[i - f] + 1);  
            }
        }
    }

    return dp[N];
}

int main() {
    int max_n = 100000;
    vector<int> factoriales = pre_factorial(max_n);

    int N;
    while (cin >> N) {
        cout << minimo_factorial(N, factoriales) << endl;
    }

    return 0;
}