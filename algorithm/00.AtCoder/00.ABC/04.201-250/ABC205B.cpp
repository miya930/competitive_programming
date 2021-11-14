#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    bool ans = true;
    for (int i = 0; i< n;++i) {
        if (i+1 != a[i]) ans = false;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
