#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1000100;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n; ++i) cin >> a[i];

    vector<int> vec(2010, 0);
    for (int i = 0; i < n; ++i) {
        vec[a[i]]++;
    }

    int ans = inf;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == 0)ans = min(ans, i);
    }

    cout << ans << endl;
    return 0;
}
