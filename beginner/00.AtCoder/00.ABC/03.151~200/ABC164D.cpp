#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

const int m = 2019;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    int x = 1, tot = 0;
    vector<int> cnt(m);
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        cnt[tot]++;
        tot += (s[i]-'0')*x;
        tot %= m;
        ans += cnt[tot];
        x = x*10%m;
    }
    cout << ans << endl;
    return 0;
}
