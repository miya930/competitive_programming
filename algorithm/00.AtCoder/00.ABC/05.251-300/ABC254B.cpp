#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(40, vector<int>(40));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (j == 0 || j == i) a[i][j] = 1;
            else a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
