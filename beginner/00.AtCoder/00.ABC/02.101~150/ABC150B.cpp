#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N;
    string S;
    cin >> N >> S;

    int cnt = 0;
    for (int i = 0; i < N-2; i++) {
        if (S[i] == 'A') {
            if (S[i+1] == 'B') {
                if (S[i+2] == 'C')
                    cnt++;
            }
        }
    }

    cout << cnt << endl;
}
