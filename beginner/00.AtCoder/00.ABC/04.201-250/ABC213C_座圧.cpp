#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    
    vector<int> veca, vecb;
    for (int i = 0; i < n; ++i) {
        veca.push_back(a[i]);
        vecb.push_back(b[i]);
    }

    sort(veca.begin(), veca.end());
    sort(vecb.begin(), vecb.end());
    veca.erase(unique(veca.begin(), veca.end()), veca.end());
    vecb.erase(unique(vecb.begin(), vecb.end()), vecb.end());

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(veca.begin(), veca.end(), a[i]) - veca.begin();
        b[i] = lower_bound(vecb.begin(), vecb.end(), b[i]) - vecb.begin();
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] + 1 << " " << b[i] + 1 << endl;
    }
}
