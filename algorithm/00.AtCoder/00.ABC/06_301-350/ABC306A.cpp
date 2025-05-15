#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += s[i];
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}
