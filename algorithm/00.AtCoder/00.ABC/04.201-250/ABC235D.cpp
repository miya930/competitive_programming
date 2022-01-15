#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1001001001;

map<ll,bool> mp;
ll a, n;
ll ans = inf;

void func(ll x, ll v, ll cnt) {

    string ch1 = to_string(x);
    string ch2 = to_string(v);

    if (mp[x] == true || ch1.size() > ch2.size()) return;  
    if (x == v) {
        ans = min(ans, cnt);
        return;
    }

    mp[x] = true;

    func(a*x, v, cnt+1);

    if (x > 10 && x%10 != 0) {
        string str = to_string(x);
        char t = str[str.size()-1];
        for (int i = (int)str.size()-2; i >= 0; --i) {
            str[i+1] = str[i];
        }
        str[0] = t;
        ll nx = stoll(str);
        func(nx, v, cnt+1);
    }

    return;
}

int main()
{
    cin >> a >> n;

    func(a, n, 1);

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
