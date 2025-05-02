#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    
    map<string, int> paises_y_amores;
    while (n--){
        string s,t;
        getline(cin, s);
        istringstream sin(s);
        
        int a = 0;
        while (sin >> t &&  a == 0){
            paises_y_amores[t]++;
            a = 1;
        }
    }
    for (auto&i:paises_y_amores) cout << i.first  << " " << i.second << endl;
    return 0;
}