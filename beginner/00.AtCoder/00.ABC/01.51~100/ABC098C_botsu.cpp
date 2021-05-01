#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define DEBUG 0

int main(void)
{
    int N;
    cin >> N;

    string S;
    cin >> S;

    int minimum = 1000000000;

    vector<int> Num_W(N, 0);
    vector<int> Num_E(N, 0);

    for (int i = 0; i < N; i++) {
        if (S[i] == 'W') {
            if (i == 0)
                Num_W[i] = 1;
            else {
                Num_W[i] = Num_W[i-1] + 1;
                Num_E[i] = Num_E[i-1];
            }
        } else {
            if (i == 0) {
                Num_E[i] = 1;
            } else {
                Num_E[i] = Num_E[i-1] + 1;
                Num_W[i] = Num_W[i-1];
            }
        }
    }

    #if DEBUG
    for (int i = 0;i < N;i++) {
        cout << "Num_W[" << i << "] = " << Num_W[i] << endl;
        cout << "Num_E[" << i << "] = " << Num_E[i] << endl;
    }
    #endif


    for (int i = 0; i < N; i++) {
        if (i == 0)
            minimum = min(minimum, Num_E[N-1] - Num_E[0]);
        else if (i == N-1)
            minimum = min(minimum, Num_W[N-2]);
        else
            minimum = min(minimum, Num_W[i-1] + (Num_E[N-1]-Num_E[i+1]));
    }

    cout << minimum << endl;
}
