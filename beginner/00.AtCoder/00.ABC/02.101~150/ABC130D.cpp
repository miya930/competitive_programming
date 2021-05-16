#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll res = 0;
    ll sum = 0;
    int right = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n && sum+a[right] < k) {
            sum += a[right];
            right++;
        }
        res += n-right;
        if (left == right) right++;
        else sum -= a[left];
    }
    cout << res << endl;
    return 0;
}
