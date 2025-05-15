#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> ans;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n-1; i++) ans.push_back(i);
    ans.push_back(n); ans.push_back(n-1);

    int cnt2 = 1;

    for (int i = n; i >= 2; i -= 2) {
        ans.push_back(i);

        if (i == 2 && cnt2 > 1) break;
        for (int j = 0; j < i-2; j++) {
            ans.push_back(i-1);
            ans.push_back(i);
        }
        if (i-1 == 2) cnt2++;
    }

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
