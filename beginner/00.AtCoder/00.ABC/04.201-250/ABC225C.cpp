#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > B(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> B[i][j];
        }
    }

    bool ng = false;
    for (int i = 0; i < m; ++i) {
        if (i != m-1 && B[0][i]%7 == 0) {
            ng = true;
        } else {
            if (i != m-1) {
                if (B[0][i+1] != (B[0][i])+1) ng = true;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (B[i][j] != B[i-1][j]+7) ng = true;
        }
    }

    if (!ng) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
