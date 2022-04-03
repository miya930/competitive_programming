#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> a(200200), vec(200020);

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vec[a[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < 200000; ++i) {
        ans = max(ans, vec[i]+vec[i+1]+vec[i+2]);
    }

    cout << ans << endl;
    return 0;
}
