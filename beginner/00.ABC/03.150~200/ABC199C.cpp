#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int main(void)
{
    int N;
    string S;
    cin >> N >> S;

    int Q;
    cin >> Q;

    vector<int> A(Q), B(Q), T(Q);
    for (int i = 0; i < Q; i++)
        cin >> T[i] >> A[i] >> B[i];

    for (int i = 0; i < Q; i++) {
        if (i < Q-1) {
            if ((T[i] == 2) && (T[i+1] == 2)){
                i++;
                continue;
            }
        }
        if(T[i] == 1) {
            char temp = S[A[i]-1];
            S[A[i]-1] = S[B[i]-1];
            S[B[i]-1] = temp;
        } else {
            S = S.substr(N) + S.substr(0,N);
        }
    }

    cout << S << endl;
}
