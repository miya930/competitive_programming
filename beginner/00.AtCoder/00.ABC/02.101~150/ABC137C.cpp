#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
map<string, ll> memo;

int main()
{  
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0;i < n; ++i) cin >> s[i];

    for (int i = 0; i < n; ++i) {
        sort(s[i].begin(), s[i].end());
        memo[s[i]]++;
    }

    ll ans = 0;

    for (auto x : memo) {
        ans += memo.second * (memo.second -1) / 2;
    }
    cout << ans << endl;
}
