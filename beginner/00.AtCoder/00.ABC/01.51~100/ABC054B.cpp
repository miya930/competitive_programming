#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    map<pair<int, int>, char> mp;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            mp[{i, j}] = b[i][j];
        }
    }

    for (int i = 0; i <= n - m; ++i) {
        for (int j = 0; j <= n - m; ++j) {
            bool flag = true;
            for (int k = 0; k < m; ++k) {
                for (int l = 0; l < m; ++l) {
                    if (a[k+i][l+j] != mp[{k, l}]) flag = false;
                }
            }
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
