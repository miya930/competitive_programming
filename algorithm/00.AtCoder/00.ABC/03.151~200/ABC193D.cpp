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
