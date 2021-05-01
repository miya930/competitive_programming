#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N;
    string S;
    cin >> N >> S;

    for (int i = 0; i < S.size(); i++) {
        S[i] += N;
        if (S[i] > 'Z') {
            S[i] = S[i] - 'Z' + 'A' - 1;
        }
        cout << S[i];
        if (i == S.size())
            cout << endl;
    }
    return 0;
}
