#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main(void)
{
    string S;
    cin >> S;

    int cnt = 0;

    for (int i = 0; i < S.size()-3; i++) {
        if ((S[i] == 'Z') && (S[i + 1] == 'O') && (S[i + 2] == 'N') && (S[i + 3] == 'e'))
            cnt++;
    }
    cout << cnt << endl;
}
