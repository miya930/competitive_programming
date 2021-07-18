#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;

int main()
{
    long long h, w, c;
    cin >> h >> w >> c;

    vector<vector<long long> > a(h, vector<long long>(w));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    vector<long long> num(h+w-1, INF);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i+j > h+w-1) continue;
            num[i+j] = min(num[i+j], a[i][j]);
        }
    }

    long long ans = INF;
    for (int i = 0; i < h+w-1; ++i) {
        for (int j = i+1; j < h+w-1; ++j) {
            ans = min(ans, num[i]+num[j]+c*(j-i));
        }
    }
    cout << ans << endl;
    return 0;
}
