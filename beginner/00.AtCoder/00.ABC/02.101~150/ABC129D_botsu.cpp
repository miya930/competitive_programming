#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) cin >> a[i];

    vector<vector<int> > b(h, vector<int>(w, 0)), c(h, vector<int>(w, 0));

    for (int i = 0; i < h; ++i) {
        int right = 0;
        int left = 0;
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '.') {
                right++;
            } else if (a[i][j] == '#'){
                for (int k = left; k < right; ++k) {
                    b[i][k] = right - left;
                }
                if (left == right) right++;
                left = right;
            } 
            if (j == w-1) {
                for (int k = left; k < w; ++k) {
                    if (a[i][k] == '#') {
                        left++;
                        continue;
                    }
                    b[i][k] = w - left;
                }
                if (left == 0) b[i][left] = right = left;
            }
        }
    }

    for (int j = 0; j < w; ++j) {
        int up = 0;
        int low = 0;
        for (int i = 0; i < h; ++i) {
            if (a[i][j] == '.') {
                low++;
            } else if (a[i][j] == '#') {
                for (int k = up; k < low; ++k) {
                    c[k][j] = low - up;
                }
                if (low == up) low++;
                up = low;
            }
            if (i == h-1) {
                for (int k = up; k < h; ++k) {
                    if (a[k][j] == '#') {
                        up++;
                        continue;
                    }
                    c[k][j] = h - up;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans = max(ans, b[i][j]+c[i][j]-1);
        }
    }
    cout << ans << endl;
}
