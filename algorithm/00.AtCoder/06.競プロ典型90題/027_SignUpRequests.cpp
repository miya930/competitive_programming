#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];

    map<string, int> mp;

    for(int i = 0; i < N; i++) {
        if (mp[s[i]]) continue;
        mp[s[i]]++;
        cout << i+1 << endl;
    }
}


/*** 2022.3.13 復習 ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i ) cin >> s[i];
    map<string, int> mp;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (mp[s[i]] == 0) {
            ans.push_back(i+1);
            mp[s[i]]++;
        }
    }

    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << endl;
    return 0;
}
