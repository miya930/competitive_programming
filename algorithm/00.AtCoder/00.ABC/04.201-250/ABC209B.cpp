#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0 ; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n ;++i) {
        if (i%2 == 1) a[i]--;
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];

    if (sum <= x) cout << "Yes" << endl;
    else cout << "No" << endl;
}
