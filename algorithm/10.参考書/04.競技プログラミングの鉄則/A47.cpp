// ビームサーチ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct State {
    int score;
    int X[29];
    char lastMove;
    int lastPos;
}

bool operator>(const &State a1, const &State a2) {
    if (a1.score > a2.score) return true;
    else return false;
}

const int width = 10000;
int n = 10000;
int t, p[109], q[109], r[109];
int numState[109];
State Beam[109][width];
char answer[109];

void BeamSearch() {
    numState[0] = 1;
    Beam[0][0].score = 0;
    for (int i = 0; i < n; ++i) Beam[0][0].x[i] = 0;

    for (int i = 1; i <= t; i++) {
        vector<State> candidate;
        for (int j = 0; j < numState[i]; j++) {
            State OpA = Beam[i-1][j];
            OpA.lastMove = 'A';
            OpA.lastPos = j;
            OpA.x[p[i]]++;
            OpA.x[q[i]]++;
            OpA.x[r[i]]++;
            for (int k = 1; k <= n; k++) {
                if (OpA.x[k] == 0) OpA.score++;
            }

            State OpB = Beam[i-1][j];
            OpB.lastMove = 'B';
            OpB.lastPos = j;
            OpB.x[p[i]]--;
            OpB.x[q[i]]--;
            OpB.x[r[i]]--;
            for (int k = 1; k <= n; k++) {
                if (OpB.x[k] == 0) OpB.score++;
            }

            candidate.push_back(OpA);
            candidate.push_back(OpB);
        }
        
        sort(candidate.begin(), candidate.end(), greater<State>());
        numState[i] = min(width, (int)candidate.size());
        for (int j = 0; j < numState[i]; j++) Beam[i][j] = candidate[j];
    }
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++) cin >> p[i] >> q[i] >> r[i];

    int curPos = 0;
    for (int i = t; i >= 1; i--) {
        answer[i] = Beam[i][curPos].lastMove;
        curPos = Beam[i][curPos].lastPos;
    }

    for (int i = 1; i <= t; i++) cout << answer[i] << endl; 

    return 0;
}
