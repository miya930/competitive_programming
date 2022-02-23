#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> c[i][j];
    }

    vector<int> vecc, vecr;
    for (int i = 0; i < n-1; ++i) {
        vecc.push_back(c[0][i]-c[0][i+1]);
    }
    
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            int tmp = c[i][j] - c[i][j+1];
            if (tmp != vecc[j]) flag = false;
        }
    }

    if (!flag) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    int mi = inf;
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        if (mi > c[i][0]) {
            mi = c[i][0];
            idx = i;
        }
    }

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) b[i] = c[idx][i];

    for (int i = 0; i < n; ++i) {
        if (i == idx) a[i] = 0;
        else {
            a[i] = c[i][0] - mi;
        }
    }

    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < n; ++i) cout << b[i] << " ";
    cout << endl;

    return 0;
}
