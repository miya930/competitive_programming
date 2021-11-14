#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> a(n), b(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 1; i < n; ++i) {
        b[i] = (a[i] - a[i-1]);
    }
    b[0] = k - a[a.size()-1] + a[0];
    sort(b.rbegin(), b.rend());

    cout << k - b[0] << endl;
}
