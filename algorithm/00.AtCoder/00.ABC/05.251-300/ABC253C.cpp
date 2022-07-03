#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int Q;
    cin >> Q;

    map<int,int> mp;
    for (int q = 0; q < Q; ++q) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;
            if (mp[x] == 0) {
                mp[x] = 1;
            } else {
                mp[x]++;
            }
        } else if (t == 2) {
            int x, c;
            cin >> x >> c;
            if (mp[x] <= c) {
                    mp.erase(x);
            } else {
                    mp[x] -= c;
            }
        } else {
            int minv = mp.begin()->first;
            int maxv = mp.rbegin()->first;
            cout << maxv - minv << endl;
        }
    }

    return 0;
}
