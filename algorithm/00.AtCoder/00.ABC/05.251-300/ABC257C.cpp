#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int,int>> a;
int n;
string s;

int main()
{
    cin >> n >> s;

    a.resize(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = s[i] - '0';
        if (s[i] == '1') ans++;
    }

    sort(a.begin(), a.end());

    int x = ans;
    for (int i = 0; i < n; ++i) {
        if (a[i].second == 1) x--;
        else x++;

        if (i < n-1 && (a[i].first == a[i+1].first)) continue;
        ans = max(ans, x);
    }

    cout << ans << endl;

    return 0;
}
