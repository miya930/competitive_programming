#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= 10) continue;
        ans += a[i] - 10; 
    }
    cout << ans << endl;
}
