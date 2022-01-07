#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &v : p)
    cin >> v;
  const int INF = 1e9;
  const bool rev = (n == 2 || p[0] - 1 == p[1] || p[1] - 1 == p[2]);
  const int ind = find(p.begin(), p.end(), 1) - p.begin();
  vector<vector<int>> dist(2, vector<int>(n, INF));
  queue<pair<int, int>> que;
  dist[rev][ind] = 0;
  que.emplace(rev, ind);
 
  const auto update = [&](const int rev, const int ind, const int val) {
    if (dist[rev][ind] <= val)
      return;
    dist[rev][ind] = val;
    que.emplace(rev, ind);
  };
  while (que.size()) {
    const auto [rev, ind] = que.front();
    que.pop();
    update(rev, (ind + n - 1) % n, dist[rev][ind] + 1);
    update(!rev, n - 1 - ind, dist[rev][ind] + 1);
  }
  cout << dist[0][0] << endl;
  return 0;
}