#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> vec;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vec.resize(k);

    for (int i = 0; i < n; i += k) {
        for (int j = 0; j < k; ++j) {
            if (i+j < n) vec[j].push_back(a[i+j]);
        }
    }

    for (int i = 0; i < k; ++i) sort(vec[i].begin(), vec[i].end());
    vector<int> ans;

    for (int i = 0; i < n; i+=k) {
        for (int j = 0; j < k; ++j) {
            if (i/k < vec[j].size()) ans.push_back(vec[j][i/k]);
        }
    }

    bool flg = true;
    for (int i = 0; i < ans.size()-1; ++i) {
        if (ans[i] > ans[i+1]) flg = false;
    }
    
    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
