#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll,int> mp;
vector<ll> ameba;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ameba.push_back(a[0]);
    mp[a[0]] = 0;
    for (int i = 0; i < n; i++) {
        ameba.push_back(2*(i+1));
        ameba.push_back(2*(i+1)+1);
        mp[2*(i+1)] += (mp[a[i]] + 1);
        mp[2*(i+1)+1] += (mp[a[i]] + 1);
    }

    for (int i = 0; i < (int)ameba.size(); ++i) {
        cout << mp[ameba[i]] << endl;
    }

    return 0;
}
