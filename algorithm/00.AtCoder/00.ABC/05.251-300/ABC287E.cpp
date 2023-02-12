#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<pair<string,int>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].first;
        s[i].second = i;
    }

    sort(s.begin(), s.end());
    vector<int> ans(n, 0);
    for (int i = 0; i < n-1; i++) {
        string a = s[i].first;
        string b = s[i+1].first;
        int num = 0;
        while(num < a.size() && num < b.size()) {
            if (a[num] == b[num]) num++;
            else break;
        }
        int idx1 = s[i].second;
        int idx2 = s[i+1].second;
        ans[idx1] = max(ans[idx1], num);
        ans[idx2] = max(ans[idx2], num);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }


    return 0;
}
