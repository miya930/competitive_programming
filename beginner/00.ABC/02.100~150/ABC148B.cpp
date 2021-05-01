#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    string S, T;
    cin >> S >> T;

    for (int i = 0; i < N; i++) {
        cout << S[i] << T[i];
        if (i == N-1)
            cout << endl;
    }

    return 0;
}
