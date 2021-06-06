#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> p(1000100, 0);

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) p[a[i]]++;

    for (int i = 0; i < n; ++i) {
        if (p[a[i]] > 0) {
            int c = a[i];
            if (p[a[i]] > 1) p[a[i]] = 0;
            for (int j = 2*c; j < 1000100; j += c) {
                if (p[j] > 0) p[j] = 0;
            }
        }
    }
    
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        if (p[a[i]] == 1) ans++;
    }
    cout << ans << endl;
}
