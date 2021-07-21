#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<int> > a(H, vector<int>(W)), b(H, vector<int>(W));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> b[i][j];
        }
    }

    long long ans = 0;
    for (int i = 0; i < H-1; ++i) {
        for (int j = 0; j < W-1; ++j) {
            if (a[i][j] != b[i][j]) {
                int temp = b[i][j] - a[i][j];
                ans += abs(temp);
                a[i][j] += temp;
                a[i+1][j] += temp;
                a[i][j+1] += temp;
                a[i+1][j+1] += temp;
            }
        }
    }

    bool is_same = true;

    for (int i = 0; i < H; ++i) {
        if (a[i][W-1] != b[i][W-1]) is_same = false;
    }

    for (int i = 0; i < W; ++i) {
        if (a[H-1][i] != b[H-1][i]) is_same = false;
    }

    if (is_same) {
        cout << "Yes" << endl;
        cout << ans << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
