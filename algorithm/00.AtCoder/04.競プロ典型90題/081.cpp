#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > sum(5010, vector<int>(5010, 0));

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n ;++i) cin >> a[i] >> b[i];

    for (int i = 0; i < n; ++i) sum[a[i]+1][b[i]+1]++;

    for (int i = 1; i < 5010; ++i) {
        for (int j = 1; j < 5010; ++j) {
            sum[i][j] += sum[i-1][j];
        }
    }

    for (int i = 1; i < 5010; ++i) {
        for (int j = 1; j < 5010; ++j) {
            sum[i][j] += sum[i][j-1]; 
        }
    }

    int ans = 0;
    for (int i = 0; i < 5009 - k; ++i) {
        for (int j = 0; j < 5009 - k; ++j) {
            ans = max(ans, sum[i+k+1][j+k+1] - sum[i][j+k+1] - sum[i+k+1][j] + sum[i][j]);
        }
    }
    cout << ans << endl;
}
