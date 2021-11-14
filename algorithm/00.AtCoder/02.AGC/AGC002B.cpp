#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<bool> visit(100100, false);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }

    map<int, int> mp;
    visit[0] = true;
    for (int i = 0; i < n; ++i) mp[i] = 1;

    for (int i = 0; i < m; ++i) {
        if (visit[x[i]]) visit[y[i]] = true;
        mp[x[i]]--; mp[y[i]]++;
        if (visit[x[i]] == true && mp[x[i]] == 0) visit[x[i]] = false;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (visit[i]==true && mp[i] > 0) ans++;
    }

    cout << ans << endl;
}
