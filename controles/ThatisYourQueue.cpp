#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int P, C;
    int case_num = 1;

    while (cin >> P >> C && (P || C)) {
        cout << "Case " << case_num++ << ":\n";

        int limit = min(P, C); // Solo se usan los primeros C ciudadanos
        list<int> q;
        unordered_map<int, list<int>::iterator> pos;

        for (int i = 1; i <= limit; ++i) {
            q.push_back(i);
            pos[i] = prev(q.end());
        }

        while (C--) {
            string cmd;
            cin >> cmd;

            if (cmd == "N") {
                int front = q.front();
                q.pop_front();
                cout << front << '\n';

                q.push_back(front);
                pos[front] = prev(q.end());
            } else { // Es "E x"
                int x;
                cin >> x;

                if (pos.count(x)) {    // Si x ya está en la cola, lo quitamos
                    q.erase(pos[x]);
                }

                // Lo insertamos al frente
                q.push_front(x);
                pos[x] = q.begin();
            }
        }
    }
    return 0;
}