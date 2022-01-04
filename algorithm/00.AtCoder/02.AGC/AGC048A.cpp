#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int t;
    cin >> t;

    string a = "atcoder";

    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;

        if (s > "atcoder") {
            cout << 0 << endl;
            continue;
        } 
        int n = s.size();

        bool alla = true;
        for (int j = 0; j < n; ++j) {
            if (s[j] != 'a') alla = false;
        }
        if (alla) {
            cout << -1 << endl;
            continue;
        }
        
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != 'a') {
                if (s[i] > 't') ans = min(ans, i-1);
                else ans = min(ans, i);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
