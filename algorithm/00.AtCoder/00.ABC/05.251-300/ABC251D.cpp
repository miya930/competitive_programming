#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int w;
    cin >> w;
    vector<int> ans;
    int d[] = {1, 100, 10000};
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j < 100; ++j) {
            ans.push_back(d[i]*j);
        }
    }
    ans.push_back(1000000);

    cout << (int)ans.size() << endl;
    for (int i = 0;i < (int)ans.size(); ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
