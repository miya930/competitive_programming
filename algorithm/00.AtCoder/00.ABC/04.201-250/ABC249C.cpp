#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    int ans = 0;
    for (int bits = 0; bits < 1<<n; ++bits) {
        map<char,int> mp;
        for (int i = 0; i < n; ++i) {
            if (bits>>i & 1) {
                set<char> st;

                for (auto c : s[i]) {
                    st.insert(c);
                }
                
                for (auto c : st) {
                    mp[c]++;
                }
            }
        }

        int tmp = 0;
        for (auto x : mp) {
            if (x.second == k) tmp++;
        }

        ans = max(tmp, ans);
    }

    cout << ans << endl;
    
    return 0;
}
