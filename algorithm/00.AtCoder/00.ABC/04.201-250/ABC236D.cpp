#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> a;
vector<bool> used;
vector<pair<int,int>> vec;
int n;

int func() {

    if ((int)vec.size() == n) {
        int ret = 0;
        for (auto p : vec) ret ^= a[p.first][p.second];
        return ret;
    }

    int l;
    for (int i = 0; i < 2*n; ++i) {
        if (!used[i]) {
            l = i;
            break;
        }
    }
    used[l] = true;

    int ret = 0;
    for (int i = 0; i < 2*n; ++i) {
        if (!used[i]) {
            vec.push_back({l, i}); used[i] = true;
            ret = max(ret,func());
            vec.pop_back(); used[i] = false;
        }
    }

    used[l] = false;
    return ret;
}

int main()
{
    cin >> n;
    a.assign(2*n, vector<int>(2*n, 0));
    used.assign(2*n, false);
    for (int i = 0; i < 2*n-1; ++i) {
        for (int j = i+1; j < 2*n; ++j) {
            cin >> a[i][j];
        }
    }

    cout << func() << endl;
    return 0;
}
