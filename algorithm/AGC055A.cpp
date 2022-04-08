#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(3, 0);
    string ans = "";
    for (int i = 0; i < 3*n; ++i) {
        int now = s[i] - 'A';
        cnt[now]++;
        ans += (char)(cnt[now]+'0');
    }

    cout << ans << endl;
    return 0;
}
