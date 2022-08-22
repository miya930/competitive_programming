#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<pair<int,int>> paa(n), pab(n), pac(n);
    for (int i = 0; i < n; ++i) {
        cin >> paa[i].first;
        paa[i].second = -i;
        pac[i].first = paa[i].first;
        pac[i].second = -i;
    }

    for (int i = 0; i < n; ++i) {
        cin >> pab[i].first;
        pab[i].second = -i;
        pac[i].first += pab[i].first;
    }
    sort(paa.rbegin(), paa.rend());
    sort(pab.rbegin(), pab.rend());
    sort(pac.rbegin(), pac.rend());
    
    vector<int> seen(n, -1), ans;

    for (int i = 0; i < x; ++i) {
        int idx = -paa[i].second;
        if (seen[idx] == -1) {
            seen[idx] = 1;
            ans.push_back(idx+1);
        }
    }

    int tt = 0;
    int cnt = 0;
    while(tt < y) {
        int idx = -pab[cnt].second;
        if (seen[idx] == -1) {
            seen[idx] = 1;
            ans.push_back(idx+1);
            tt++;
        }
        cnt++;
    }

    tt = 0;
    cnt = 0;
    while(tt < z) {
        int idx = -pac[cnt].second;
        if (seen[idx] == -1) {
            seen[idx] = 1;
            ans.push_back(idx+1);
            tt++;
        }
        cnt++;
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
