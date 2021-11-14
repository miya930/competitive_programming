#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bina(int k, vector<int> a) {
    int right = a.size();
    int left = -1;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (k <= a[mid]) right = mid;
        else left = mid; 
    }
    return right;
}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int k; cin >> k;

    int ans = bina(k, a);
    cout << ans << endl;
}
