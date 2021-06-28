#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), a(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) a[i] = x[i];
    sort(a.begin(), a.end());

    map<int,int> mp;
    for (int i = 0; i < n; ++i) mp[a[i]] = i;
    
    for (int i = 0; i < n; ++i) {
        int j = mp[x[i]];
        if (j < n/2) cout << a[n/2] << endl;
        else cout << a[(n/2-1)] << endl;
    }

    return 0;
}
