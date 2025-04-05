#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

struct Team {
    int teamNumber;
    int solved[12];
    int penalty[12];
    bool submit;

    Team(int i = 0) {
        teamNumber = i;
        fill(solved, solved + 12, 0);
        fill(penalty, penalty + 12, 0);
        submit = false;
    }
};

bool cmp(const Team& a, const Team& b) {
    if (a.solved[10] != b.solved[10])
        return a.solved[10] > b.solved[10];
    if (a.penalty[10] != b.penalty[10])
        return a.penalty[10] < b.penalty[10];
    return a.teamNumber < b.teamNumber;
}

int main() {
    int testCase;
    string line;

    cin >> testCase;
    cin.ignore(); 
    getline(cin, line);

    bool blank = false;

    while (testCase--) {
        vector<Team> teams;
        for (int i = 0; i < 105; i++) teams.push_back(Team(i));

        while (getline(cin, line)) {
            if (line.empty()) break;

            int c, p, t;
            char l;
            sscanf(line.c_str(), "%d %d %d %c", &c, &p, &t, &l);

            teams[c].submit = true;

            if (l == 'C') {
                if (!teams[c].solved[p]) {
                    teams[c].solved[p] = 1;
                    teams[c].penalty[p] += t;
                }
            } else if (l == 'I') {
                if (!teams[c].solved[p]) {
                    teams[c].penalty[p] += 20;
                }
            }
            // 'R', 'U', 'E' are ignored
        }
        // Final calculation
        for (int i = 1; i < 105; i++) {
            for (int j = 1; j <= 9; j++) {
                if (teams[i].solved[j]) {
                    teams[i].solved[10]++;
                    teams[i].penalty[10] += teams[i].penalty[j];
                }
            }
        }
        sort(teams.begin(), teams.end(), cmp);
        if (blank) cout << endl;
        blank = true;
        for (auto& t : teams) {
            if (t.submit) {
                cout << t.teamNumber << " " << t.solved[10] << " " << t.penalty[10] << endl;
            }
        }
    }
    return 0;
}
