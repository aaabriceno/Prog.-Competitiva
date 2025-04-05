#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int Case = 1; Case <= t; Case++) {
        cout << "Case #" << Case << ":\n"; 
        int A[3];
        vector<int> B[3];
        int mark[10001] = {};
        for (int i = 0; i < 3; i++) {
            cin >> A[i];
            for (int j = 0; j < A[i]; j++) {
                int problem;
                cin >> problem;
                B[i].push_back(problem);
                mark[problem]++;
            }
            sort(B[i].begin(), B[i].end());
        }
        int max = 0;
        int solve[3];
        for (int i = 0; i < 3; i++) {
            int tmp = 0;
            for (int j = 0; j < A[i]; j++) {
                if (mark[B[i][j]] == 1) {
                    tmp++;
                }
            }
            solve[i] = tmp;
            if (tmp > max) {
                max = tmp;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (solve[i] == max) {
                cout << i + 1 << " " << solve[i];
                for (int j = 0; j < A[i]; j++) {
                    if (mark[B[i][j]] == 1) {
                        cout << " " << B[i][j];
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}