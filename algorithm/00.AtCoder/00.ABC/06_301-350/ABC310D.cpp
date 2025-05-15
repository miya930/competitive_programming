#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> hate, teams;
int n, t, m;

int dfs(int now) {
    if (now == n) {
        return teams.size() == t;
    }

    int ans = 0;
    for (auto &&team : teams) {
        if (team & hate[now]) continue;

        team ^= (1 << now);
        ans += dfs(now + 1);
        team ^= (1 << now);
    }

    if (teams.size() < t) {
        teams.emplace_back(1 << now);
        ans += dfs(now + 1);
        teams.pop_back();
    }

    return ans;
}

int main()
{
    cin >> n >> t >> m;
    hate = vector<int>(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        hate[b] |= (1 << a);
    }

    teams.reserve(t);
    cout << dfs(0) << endl;

    return 0;
}
