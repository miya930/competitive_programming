/**
   created: 21.10.2021 22:41:03
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    ll x;
    cin >> x;

    ll sum = 0;
    int count = 0;
    for (int i = 1; i < 100000; i++) {
        sum += i;
        count++;
        if (sum >= x) break;
    }

    cout << count << endl;

    return 0;
}
