#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> vec(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (vec[i] == 0) {
            vec[a[i-1]] = 1;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (vec[i] == 0) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
