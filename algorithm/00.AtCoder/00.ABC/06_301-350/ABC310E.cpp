#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    ll ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '0') {
            ans += i;
        } else if (s[i] == '1') {
            ans += i+1;
            if (i >= 1) s[i-1] = '2';
        } else {
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}
