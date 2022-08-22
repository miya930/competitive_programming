/**
   created: 23.10.2021 09:25:13
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    ll cycle = 0;
    ll now = 0;
    vector<bool> seen(n, false);
    while (!seen[now]) {
        seen[now] = true;
        now = a[now];
        cycle++;
    }

    ll p = 0, c = 0;;
    for (int i = 0; i < n; ++i) {
        if (p == now) {
            break;
        } else {
            p = a[p];
            c++;
        }
    }

    cycle -= c;

    ll pos = 0;
    if (k < c) {
        while (k > 0) {
            k--;
            pos = a[pos];
        }
        cout << pos+1 << endl;
    } else {
        k -= c;
        k %= cycle;
        while (k > 0) { 
            k--;
            now = a[now];
        }
        cout << now+1 << endl;
    }

    return 0;
}




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

    vector<int> visited(n, 0);
    deque<int> deq;
    int now = 0;

    while(1) {
        if (visited[now]) {
            while(deq[0] != now) {
                k--;
                deq.pop_front();

                if (k == 0) {
                    cout << deq[0] + 1 << endl;
                    return 0;
                }
            }
            break;
        }
        deq.push_back(now);
        visited[now] = true;
        now = a[now];
    }

    cout << deq[k % deq.size()] + 1 << endl;

    return 0;
}


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