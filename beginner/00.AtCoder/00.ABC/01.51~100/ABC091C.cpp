#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > ab(n);
    for (int i = 0; i < n; ++i) cin >> ab[i].second >> ab[i].first;
    sort(ab.rbegin(), ab.rend());
    
    vector<pair<int, int> > cd(n);
    for (int i = 0; i < n; ++i) cin >> cd[i].first >> cd[i].second;
    sort(cd.begin(), cd.end());

    int res = 0;
    vector<bool> useab(n, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (useab[j]) continue;
            if(ab[j].first < cd[i].second && ab[j].second < cd[i].first) {
                res++;
                useab[j] = true;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
