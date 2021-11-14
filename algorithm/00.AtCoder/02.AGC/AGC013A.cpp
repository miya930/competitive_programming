#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        while (i+1 < n && a[i] == a[i+1]) i++;
        
        if (i+1 < n && a[i] < a[i+1]) {
            while (i+1 < n && a[i] <= a[i+1]) i++;
        }
        else if (i+1 < n && a[i] > a[i+1]) {
            while (i+1 < n && a[i] >= a[i+1]) i++;
        }
        ans++;
    }

    cout << ans << endl;
    return 0;
}
