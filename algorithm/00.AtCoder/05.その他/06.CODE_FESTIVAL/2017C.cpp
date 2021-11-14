#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    string s;
    cin >> s;

    string t = s, tc = "", sc = "";
    reverse(t.begin(), t.end());

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (t[i] != 'x') tc.push_back(t[i]);
        if (s[i] != 'x') sc.push_back(s[i]);
    }

    if (tc != sc) {
        cout << -1  << endl;
        return 0;
    }

    int front = 0, back = s.size()-1;
    int ans = 0;
    while (front < back) {
        if (s[front] == s[back]) {
            front++;
            back--;
        } else if (s[front] == 'x' && s[back] != 'x') {
            front++;
            ans++;
        } else if (s[front] != 'x' && s[back] == 'x') {
            back--;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
