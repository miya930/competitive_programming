#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i <= n - k; ++i) {
        for (int j = 0; j <= n - k; ++j) {
            vector<int> mi;
            for (int l = i; l < i+k; ++) {
                
            }
        }
    }

}
