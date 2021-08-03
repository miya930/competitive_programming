#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    
    vector<int> vec, vec_1;

    for (int i = 0; i < n; ++i) {
        vec.push_back(m-p[i]);
        vec_1.push_back(p[i]);
        for (int j = 0; j < n; ++j) {
            vec.push_back(m-p[i]-p[j]);
            vec_1.push_back(p[i]+p[j]);
        }
    }

    sort(vec.begin(), vec.end());

    int ans = 0;
    for (int i = 0; i < vec.size(); ++i) {
        int iter = upper_bound(vec.begin(), vec.end(), vec_1[i]) - vec.begin();
        if (iter==vec.size()) continue;

        ans = max(ans, m - vec[iter] + vec_1[i]);
    }

    cout << ans << endl;

}
