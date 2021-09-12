#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    map<int, vector<int> > mpx;
    for (int i = 0; i < n; ++i) mpx[x[i]].push_back(y[i]);
    for (int i = 0; i < n; ++i) sort(mpx[x[i]].begin(), mpx[x[i]].end());
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (x[i] == x[j] || y[i] == y[j]) continue;
            if (x[i] > x[j] || y[i] > y[j]) continue;

            auto iter_1 = lower_bound(mpx[x[i]].begin(), mpx[x[i]].end(), y[j]);
            auto iter_2 = lower_bound(mpx[x[j]].begin(), mpx[x[j]].end(), y[i]);
            if (iter_1 == mpx[x[i]].end() || iter_2 == mpx[x[j]].end()) continue;
            
            int in1 = iter_1 - mpx[x[i]].begin();
            int in2 = iter_2 - mpx[x[j]].begin();

            if (mpx[x[i]][in1] == y[j] && mpx[x[j]][in2] == y[i]) {
                ans++;
                
            }
        }
    }

    cout << ans << endl;
}

