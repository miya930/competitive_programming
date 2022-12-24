#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<pair<int,int>,int> mp;

int main()
{
    int n, Q;
    cin >> n >> Q;
    
    for (int q = 0; q < Q; ++q) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) {
            mp[make_pair(a, b)] = 1;

        } else if (t == 2) {
            mp[make_pair(a, b)] = 0;
        } else {
            if (mp[make_pair(a, b)] == 1 && mp[make_pair(b, a)] == 1) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
