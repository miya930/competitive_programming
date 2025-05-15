#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> b[i][j];
    }

    for (int c = 0; c < 4; c++) {
        bool isok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1 && b[i][j] != 1) isok = false;
            }
        }
        if (isok) {
            cout << "Yes" << endl;
            return 0;
        }

        vector<vector<bool>> changed(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (changed[i][j] == false) {
                    swap(a[i][j], a[n-1-j][i]);
                    changed[i][j] = true;
                    changed[n-1-j][i] = true;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
