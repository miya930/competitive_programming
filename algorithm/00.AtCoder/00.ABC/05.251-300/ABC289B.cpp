#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    if (m == 0) {
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        return 0;
    }

    vector<int> p;
    int cur = 0, idx = 0;
    while(1) {
        vector<int> tmp;

        while(1) {
            tmp.push_back(idx);
            idx++;
            if (a[cur] != idx) break;

            cur++;
        }

        reverse(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size(); i++) p.push_back(tmp[i]+1);

        if (idx == n) break;
    }

    for (int i = 0;i < p.size(); i++) cout << p[i] << " ";
    cout << endl;

    return 0;
}
