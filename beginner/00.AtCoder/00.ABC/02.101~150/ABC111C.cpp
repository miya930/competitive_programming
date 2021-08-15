#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int INF = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    map<int, int> omp, emp;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) emp[v[i]]++;
        else omp[v[i]]++;
    }

    vector<pair<int, int> > o_p, e_p;
    o_p.push_back(make_pair(0, 0));
    e_p.push_back(make_pair(0, 0));
    for (auto e : omp) {
        o_p.push_back(make_pair(e.second, e.first));
    }
    for (auto e : emp){
        e_p.push_back(make_pair(e.second, e.first));
      }

    sort(o_p.rbegin(), o_p.rend());
    sort(e_p.rbegin(), e_p.rend());

    int ans = INF;
    if (o_p[0].second == e_p[0].second) {
        ans = min(ans, n - o_p[0].first - e_p[1].first);
        ans = min(ans, n - o_p[1].first - e_p[0].first);
    } else {
        ans = n - o_p[0].first - e_p[0].first;
    }
    cout << ans << endl;

}
