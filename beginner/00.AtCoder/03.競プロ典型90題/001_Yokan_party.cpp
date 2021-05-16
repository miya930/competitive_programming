#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // 2•ª’Tõ
    int right = l; int left = 0;
    int res = 0;
    while (right - left > 1) {
        int mid = (right+left)/2;
        int cnt = 0;  // midˆÈã‚Ì‹æŠÔ‚ğ‚¢‚­‚Âì‚ê‚é‚©”‚¦ã‚°‚é
        int pre = 0; // 

        for (int i = 0; i < n; ++i) {
            if (a[i]-pre >= mid && l - a[i] >= mid) {
                cnt++;
                pre = a[i];
            }
        }
        if (cnt >= k) left = mid;
        else right = mid;
    }

    cout << left << endl;
}
