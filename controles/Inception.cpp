#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    stack<string> sueno_acumulado;
    for (int i = 0; i < n; ++i){
        string query;
        getline(cin,query);
        
        if(query.substr(0,5) == "Sleep"){
            string name = query.substr(6);
            sueno_acumulado.push(name);
        }

        else if(query == "Kick"){
            if(!sueno_acumulado.empty()){
                sueno_acumulado.pop();
            }
        }

        else if(query == "Test"){
            if(!sueno_acumulado.empty()){
                cout << sueno_acumulado.top() << endl;
            }
            else {
                cout << "Not in a dream" << endl;
            }
        }
    }
    return 0;
}