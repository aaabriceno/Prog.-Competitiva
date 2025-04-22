#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    while (n--){
        int min_val = 100000;
        int m;
        cin >> m;
        getchar();
        m++;
        vector<int> grafo_vecinos(m,0);
        for (int i=1; i < m;i++){
            string linea;
            int contador = 1;
            getline(cin, linea);
            for (int j = 0; j <linea.length(); j++){
                if (linea[j] == ' '){
                    contador++;
                }
            }
            grafo_vecinos[i] = contador;

            min_val = min_val < contador ? min_val : contador;
            
        }
        vector <int> respuesta;
        for (int i = 1; i < m;i++){
            if(grafo_vecinos[i] == min_val){
                respuesta.push_back(i);
            }
        }
        for (int i = 0; i < respuesta.size();i++){
            cout << respuesta[i] << (i != respuesta.size() -1 ? " " : "\n");
        }
    }
    return 0;
}