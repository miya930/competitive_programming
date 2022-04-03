#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    int diff = 0;   // p - g
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'p') {
            if (diff == 0) {
                diff++;
                ans--;
            } else {
                diff--;
            }
        } else {
            if (diff == 0) {
                diff++;
            } else {
                diff--;
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
