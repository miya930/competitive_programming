/**
   created: 18.10.2021 21:40:07
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    int cnt = 1;
    char last = s[0];
    for (int i = 1; i < n; ++i) {
        if (last != s[i]) {
            cnt++;
            last = s[i];
        }
    }

    for (int i = 0; i < k; ++i) {
        if (cnt > 2) cnt -= 2;
        else if (cnt == 2) {
            cnt = 1;
            break;
        } 
    }

    cout << n-cnt << endl;

    return 0;
}
