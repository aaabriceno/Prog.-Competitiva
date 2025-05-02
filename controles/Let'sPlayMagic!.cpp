#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    bool breakmain = false;
    while (!breakmain){
        int size = 0;
        cin >> size;
        if (size == 0){
            breakmain = true;
            continue;
        }
        vector <string> posicion_cartas(size, " ");
        int contador = -1;
        cin.ignore();
        string carta;
        string nombre;
        
        while(size--){
            cin >> carta; cin >> nombre;
            int letras = nombre.size();
            
            while(letras){
                contador++;
                if (contador == posicion_cartas.size()){
                    contador = 0;
                }
                while(posicion_cartas[contador] != " "){
                    contador++;
                    if(contador == posicion_cartas.size()){
                        contador = 0;
                    }
                }
                letras--;
            }
            posicion_cartas[contador] = carta;
        }
        for (int i = 0; i < posicion_cartas.size(); i++){
            cout << posicion_cartas[i];
            if ( i + 1 != posicion_cartas.size()){
                cout << " ";
            }
            else{
                cout << "";
            }
        }
        cout << endl;
    }
    return 0;
}