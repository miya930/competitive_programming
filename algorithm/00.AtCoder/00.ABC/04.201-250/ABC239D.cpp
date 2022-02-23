#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<bool> isprime(250, true);
    isprime[0] = false; isprime[1] = false;

    for (int i = 2; i <= 200; ++i) {
        for (int j = i*2; j <= 200; j += i) {
            isprime[j] = false;
        }
    }

    bool taka = false;
    for (int i = a; i <= b; ++i) {
        bool win = true;

        for (int j = c; j <= d; ++j) {
            if (isprime[i+j]) win = false;
        }

        if (win) taka = true;
    }
    
    if (taka) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}
