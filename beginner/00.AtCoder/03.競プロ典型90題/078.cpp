#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef vector<vector<int> > Graph;

int main()
{
    int n, m;
    cin >> n >> m;

    map<int, int> mp;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        
        if (a < b) mp[b]++;
        else mp[a]++;
    }

    int ans = 0;
    for (auto x : mp) {
        if (x.second == 1) ans++;
    }

    cout << ans << endl;
    return 0;
}
