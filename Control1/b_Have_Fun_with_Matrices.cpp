#include <iostream>
#include <vector>
#include <string>
using namespace std;

void readMatrix(int tam, vector<vector<int>>& matriz) {
    string tmp, data = "";
    for (int x = 0; x < tam; x++) {
        cin >> tmp;
        data += tmp;
    }

    int index = 0;
    for (int x = 0; x < tam; x++) {
        for (int y = 0; y < tam; y++) {
            matriz[x][y] = data[index++] - '0';
        }
    }
}

void print(int tam, const vector<vector<int>>& matriz) {
    for (int x = 0; x < tam; x++) {
        for (int y = 0; y < tam; y++) {
            cout << matriz[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

void addOne(int tam, vector<vector<int>>& matriz) {
    for (int x = 0; x < tam; x++) {
        for (int y = 0; y < tam; y++) {
            matriz[x][y]++;
            if (matriz[x][y] > 9) {
                matriz[x][y] = 0;
            }
        }
    }
}

void restOne(int tam, vector<vector<int>>& matriz) {
    for (int x = 0; x < tam; x++) {
        for (int y = 0; y < tam; y++) {
            matriz[x][y]--;
            if (matriz[x][y] < 0) {
                matriz[x][y] = 9;
            }
        }
    }
}

void transpose(int tam, vector<vector<int>>& matriz) {
    vector<vector<int>> tmpMatriz(tam, vector<int>(tam));
    for (int x = 0; x < tam; x++) {
        for (int y = 0; y < tam; y++) {
            tmpMatriz[y][x] = matriz[x][y];
        }
    }
    matriz = tmpMatriz;
}

void swapRow(int r1, int r2, int tam, vector<vector<int>>& matriz) {
    for (int x = 0; x < tam; x++) {
        swap(matriz[r1][x], matriz[r2][x]);
    }
}

void swapCol(int c1, int c2, int tam, vector<vector<int>>& matriz) {
    for (int x = 0; x < tam; x++) {
        swap(matriz[x][c1], matriz[x][c2]);
    }
}

int main() {
    int casos;
    cin >> casos;
    for (int i = 1; i <= casos; i++) {
        int tam, queries;
        cin >> tam;
        vector<vector<int>> matriz(tam, vector<int>(tam));
        readMatrix(tam, matriz);
        cin >> queries;
        for (int j = 0; j < queries; j++) {
            string str;
            cin >> str;
            if (str == "inc") {
                addOne(tam, matriz);
            } else if (str == "dec") {
                restOne(tam, matriz);
            } else if (str == "transpose") {
                transpose(tam, matriz);
            } else if (str == "row") {
                int r1, r2;
                cin >> r1 >> r2;
                swapRow(r1 - 1, r2 - 1, tam, matriz);  
            } else if (str == "col") {
                int c1, c2;
                cin >> c1 >> c2;
                swapCol(c1 - 1, c2 - 1, tam, matriz);
            }
        }
        cout << "Case #" << i << endl;
        print(tam, matriz);
    }
    return 0;
}