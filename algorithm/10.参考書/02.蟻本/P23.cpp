#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int inf = 1000000007;

int main()
{
    int l, n;
    cin >> l >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    // ç≈ëÂ
    int ans_max = -1;
    sort(x.begin(), x.end());
    for (int i = 0; i < n; ++i) {
        ans_max = max(ans_max, x[i]);       // ans_max = max(ans_max, max(x[i], l-x[i]))Ç∆Ç‹Ç∆ÇﬂÇƒÇµÇ‹Ç¡ÇƒÇÊÇ¢
        ans_max = max(ans_max, l-x[i]);
    }

    // ç≈è¨
    int ans_min = inf;
    for (int i = 0; i < n; ++i) {
        ans_min = min(ans_min, x[i]);
        ans_min = min(ans_min, l-x[i]);
    }
    
    cout << ans_min << endl;
    cout << ans_max << endl;
    return 0;

}
