#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '1') vec[i]++;
        }
    }
    ll even = 0, odd = 0;

    for (int i = 0; i < n; ++i) {
        if (vec[i]%2 == 0) even++;
        else odd++;
    }

    cout << odd*even << endl;
    return 0;
}
