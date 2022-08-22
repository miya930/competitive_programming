#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
 
    vector<int> visited(n, 0), vec, start, cycle;
    int now = 0;
    vec.push_back(now);
 
    while(1) {
        visited[now]++;
        if (visited[now] > 2) break;
        vec.push_back(a[now]);
        now = a[now];
    }
 
    for (int i = 0; i < n; ++i) {
        if (visited[vec[i]] == 1) start.push_back(vec[i]);
        else break;
    }
 
    int si = start.size();
    int vesi = vec.size();
 
    for (int i = si; i < si + (vesi-1-si)/2; ++i) {
        cycle.push_back(vec[i]);
    }
 
    if (k < si) cout << start[k]+1 << endl;
    else {
        k -= si;
        k %= (ll)cycle.size();
        cout << cycle[k%cycle.size()]+1 << endl;
    }
 
    return 0;
}