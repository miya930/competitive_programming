#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k, s;
    cin >> n >> k >> s;

    vector<int> ans(n);
    int cnt = 0;
    while(cnt < k) {
        ans[cnt] = s;
        cnt++;
    }

    int add = 0;
    if (s != 1e9) add = 1e9;
    else add = 1;

    for (int i = k; i < n; ++i) ans[i] = add;

    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
