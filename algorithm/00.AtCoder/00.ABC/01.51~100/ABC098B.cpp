#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> vec1(26, 0), vec2(26, 0);
    for (int i = 0; i < n; ++i) {
        vec1[s[i]-'a']++;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int ch = s[i] - 'a';
        vec1[ch]--;
        vec2[ch]++;
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            if (vec1[i] > 0 && vec2[i] > 0) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
