#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PP = pair<int, pair<int,int>>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<PP> a(n), b(m), c;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        a[i].first = u;
        a[i].second.first = 0;
        a[i].second.second = i;
        c.push_back(a[i]);
    }

    for (int i = 0; i < m; i++) {
        int u;
        cin >> u;
        b[i].first = u;
        b[i].second.first = 1;
        b[i].second.second = i;
        c.push_back(b[i]);
    }

    sort(c.begin(), c.end());
    vector<int> ansa(n), ansb(m);
    for (int i = 0; i < n+m; i++) {
        int aorb = c[i].second.first;
        int idx = c[i].second.second;
        
        if (aorb == 0) {
            ansa[idx] = i + 1;
        } else {
            ansb[idx] = i + 1;
        }
    }

    for (int i = 0; i < n; i++) cout << ansa[i] << " ";
    cout << endl;
    for (int i = 0; i < m; i++) cout << ansb[i] << " ";

    return 0;
}
