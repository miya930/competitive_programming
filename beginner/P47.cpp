#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    int ans = 0;
    int i = 0;
    while (i < n) {
        // まず中心の点を探す
        int s = x[i++];

        while (i < n && x[i] <= s+r) i++;

        // 次に右端の点を探す
        int p = x[i-1];

        while (i < n && x[i] <= p+r) i++;

        ans++;
    }


    cout << ans << endl;
}
