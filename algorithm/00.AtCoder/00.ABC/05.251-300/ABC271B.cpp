#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            int tmp;
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }

    for (int iii = 0; iii < q; iii++) {
        int s, t;
        cin >> s >> t;
        s--; t--;

        cout << a[s][t] << endl;
    }

    return 0;
}
