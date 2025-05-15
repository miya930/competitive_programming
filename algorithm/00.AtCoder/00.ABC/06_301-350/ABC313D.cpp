#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void out(vector<int> v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int send(vector<int> v) {
    for (auto &x : v) x++;
    cout << "? ";
    out(v);
    int x;
    cin >> x;
    return x;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);

    int r = 0;
    for (int i = 0;i < k+1; i++) {
        vector<int> v;
        for (int j = 0; j < k+1; j++) {
            if (i != j) v.push_back(j);
        }
        ans[i] = send(v);
        r ^= ans[i];
    }
    for (int i = 0; i < k+1; i++) ans[i] ^= r;

    vector<int> v(k);
    int s = 0;
    for (int i = 0; i < k-1; i++) {
        v[i] = i;
        s ^= ans[i];
    }
    for (int i = k+1; i < n; i++) {
        v.back() = i;
        int t = send(v);
        ans[i] = s ^ t;
    }
    cout << "! ";
    out(ans);
    return 0;
}
