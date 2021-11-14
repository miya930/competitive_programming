#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;

    map<pair<int, int>, int> mp;

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int dx = pos[j].first - pos[i].first;
            int dy = pos[j].second - pos[i].second;

            int g = gcd(dx, dy);
            
            mp[make_pair(dx/g, dy/g)]++;
        }
    } 

    cout << mp.size()*2 << endl;

    return 0;
}
