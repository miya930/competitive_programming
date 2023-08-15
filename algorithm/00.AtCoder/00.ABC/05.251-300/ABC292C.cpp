#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int func(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n%i != 0) continue;
        res.push_back(i);
        if (n/i != i) res.push_back(n/i);
    }
    sort(res.begin(), res.end());

    return (int)res.size();
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n+1, 0);
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        vec[i] = func(i);
    }

    for (int i = 1; i <= n-1; i++) {
        ans += (vec[i] * vec[n-i]);
    }

    cout << ans << endl;

    return 0;
}
