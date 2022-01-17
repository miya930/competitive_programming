#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll score(string s) {
    vector<ll> cnt(10);
    iota(cnt.begin(), cnt.end(), 0);
    for (char c : s) cnt[c - '0'] *= 10;
    return accumulate(cnt.begin(), cnt.end(), 0);
}

int main()
{
    ll k;
    string s, t;
    cin >> k >> s >> t;

    vector<ll> cnt(10, k);

    for (auto c : s) cnt[c - '0']--;
    for (auto c : t) cnt[c - '0']--;

    ll win = 0;

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            s.back() = i + '0';
            t.back() = j + '0';
            if (score(s) <= score(t)) continue;
            win += cnt[i] * (cnt[j] - (i == j));
        }
    }
    
    ll tot = (9*k-8)*(9*k-9);
    printf("%.12f\n", double(win) / tot);
    return 0;
}


/*
 * 2022.1.16 復習
 *
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> scard(10, 0), tcard(10, 0);

ll func(ll n) {
    ll res = 1;
    for (int i = 0; i < n; ++i) res *= 10;
    return res;
}

int main()
{
    ll k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    vector<ll> card(10, k);
    for (int i = 0; i < 4; ++i) {
        int nums = s[i] - '0';
        int numt = t[i] - '0';
        card[nums]--;
        card[numt]--;
        scard[nums]++;
        tcard[numt]++;
    }

    ll ans = 0;
    for (ll i = 1; i <= 9; ++i) {
        for (ll j = 1; j <= 9; ++j) {
            vector<ll> stmp = scard, ttmp = tcard;
            stmp[i]++; ttmp[j]++;

            ll sscore = 0, tscore = 0;
            for (ll u = 1; u <= 9; ++u) {
                sscore += (u*func(stmp[u]));
                tscore += (u*func(ttmp[u])); 
            }
            if (sscore > tscore) {
                ans += (card[i]*(card[j]-(i==j)));
            }
        }
    }

    printf("%.12f\n", (double)ans / (9*k-8) / (9*k-9));

    return 0;
}
