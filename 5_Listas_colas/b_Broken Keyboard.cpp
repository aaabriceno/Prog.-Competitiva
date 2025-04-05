#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    string input;
    // Leer hasta EOF
    while (getline(cin, input))
    {
        list<char> cadena_texto; 
        auto It = cadena_texto.begin(); 

        for (auto i : input)
        {
            switch (i)
            {
            case '[':
                It = cadena_texto.begin();  
                break;
            case ']':
                It = cadena_texto.end();    
                break;
            default:
                cadena_texto.insert(It, i); 
                break;
            }
        }
        for (auto it : cadena_texto)
            cout << it;
        cout << endl;
    }

    return 0;
}
