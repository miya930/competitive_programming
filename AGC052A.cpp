#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<string> s(3);

        for (int i = 0; i < 3; ++i) cin >> s[i];

        string ans = "";
        for (int i = 0; i < n; ++i) ans += '0';
        for (int i = 0; i < n; ++i) ans += '1';
        ans += '0';
        cout << ans << endl;
    }

    return 0;
}
