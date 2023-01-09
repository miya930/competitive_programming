#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> vec(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> x;
        for (int j = 0; j < k; j++) {
            int xx;
            cin >> xx;
            xx--;
            x.push_back(xx);
        }

        for (int j = 0; j < k; j++) {
            for (int l = j+1; l < k; l++) {
                int t1 = x[j];
                int t2 = x[l];
                vec[t1][t2] = true;
                vec[t2][t1] = true;
            }
        }

    }

    bool flg = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j &&!vec[i][j]) flg = false;
        }
    }

    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
