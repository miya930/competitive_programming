#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> rvec, lvec;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 0) k--;
        else if (x > 0) rvec.push_back(x);
        else lvec.push_back(-x);
    }

    sort(rvec.begin(), rvec.end());
    sort(lvec.begin(), lvec.end());

    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }

    map<int,int> rmp, lmp;
    int cnt = 1;
    for (int i = 0; i < (int)lvec.size(); ++i) {
        lmp[cnt] = lvec[i];
        cnt++;
    }
    cnt = 1;
    for (int i = 0; i < (int)rvec.size(); ++i) {
        rmp[cnt] = rvec[i];
        cnt++;
    }

    int ans = inf;
    if (lmp[k] != 0) ans = min(ans, lmp[k]);
    if (rmp[k] != 0) ans = min(ans, rmp[k]);

    for (auto x : rmp) {
        int rpos = x.second;
        int lpos = lmp[k-x.first];
        if (rpos == 0 || lpos == 0) continue;
        int tmp = min(rpos+lpos*2, rpos*2+lpos);
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
