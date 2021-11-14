#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int> > v(N);
    for (int i = 0; i < N; ++i) cin >> v[i].first >> v[i].second;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) p[i] = i;

    ld res = 0;
    do {
        for (int i = 1; i < N; ++i) {
            ll dx = v[p[i]].first - v[p[i-1]].first;
            ll dy = v[p[i]].second - v[p[i-1]].second;
            res += sqrt(dx*dx + dy*dy);
        }
    } while(next_permutation(p.begin(), p.end()));
    
    for (int i = 1; i <= N; ++i) res /= i;

    cout << fixed << setprecisiion(7) << res << endl;
}
