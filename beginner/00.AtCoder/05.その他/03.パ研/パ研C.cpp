#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m ; ++j) {
            cin >> a[i][j];
        }
    }

    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            long long sum = 0;
            for (int k = 0; k < n; ++k) {
                int ma = 0;
                ma = max (a[k][i], a[k][j]);
                sum += ma;
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}
