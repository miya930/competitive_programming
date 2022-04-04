#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
multiset<int> mst;
vector<pair<int,int>> a, b;

int main()
{    
    cin >> n >> m;
    a.resize(n); b.resize(m);

    for (int i = 0 ; i < n; ++i) cin >> a[i].first;
    for (int i = 0 ; i < n; ++i) cin >> a[i].second;
    for (int i = 0 ; i < m; ++i) cin >> b[i].first;
    for (int i = 0 ; i < m; ++i) cin >> b[i].second;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());    

    int j = m-1;
    for (int i = n-1; i >= 0;--i) {
        while(j >= 0 && a[i].first <= b[j].first) mst.insert(b[j--].second);
        auto itr = mst.lower_bound(a[i].second);
        if (itr == mst.end()) {
            cout << "No" << endl;
            return 0;
        }
        mst.erase(itr);
    }

    cout << "Yes" << endl;

    return 0;
}
