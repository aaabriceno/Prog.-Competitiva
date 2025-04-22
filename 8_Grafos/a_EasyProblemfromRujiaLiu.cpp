#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n,m;
    while(cin >> n >> m){
        vector <int> numeros_del_array(n);
        map<int, vector <int>> numero_ocurrencias;
        for (int i = 0; i < n; i++){
            cin >> numeros_del_array[i];
            numero_ocurrencias[numeros_del_array[i]].push_back(i+1);
        }
        for(int i = 0; i < m; i++){
            int k, v;
            cin >> k >> v;
            if(numero_ocurrencias.find(v) != numero_ocurrencias.end()){
                if (numero_ocurrencias[v].size() >= k){
                    cout << numero_ocurrencias[v][k-1] << endl;
                }
                else{
                    cout << 0 << endl;
                }
            }
            else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}