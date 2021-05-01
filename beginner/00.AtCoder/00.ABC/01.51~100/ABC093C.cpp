#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> S(3);
    S[0] = A;
    S[1] = B;
    S[2] = C;
    sort(S.rbegin(), S.rend());

    int cnt = 0;
    if (((S[0]-S[1]) + (S[0] - S[2])) % 2 == 1 ) {
        cnt++;
        S[0]++;
        S[1]++;
    }

    if ((S[0]-S[1])%2 == 1) {
        cnt++;
        S[1]++;
        S[2]++;
    }
    cnt += (S[0]-S[1])/2;
    cnt += (S[0]-S[2])/2;

    cout << cnt << endl;
}
