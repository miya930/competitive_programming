#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    bool ans = false;
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            for (int c = 0; c < n; ++c) {
                int left = 0;
                int right = n;
                int key = m - a - b - c;
                while (right - left > 1) {
                    int mid = (right+left) / 2;
                    if (mid < key) left = mid;
                    else right = mid;
                }
                if (right == key) ans = true;
            }
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
