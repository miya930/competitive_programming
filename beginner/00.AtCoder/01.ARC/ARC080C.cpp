#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int, int> mp;

    for (int i = 0; i < n; ++i) {
        if (a[i]%4 == 0) {
            mp[4]++;
        } else if (a[i]%2==0) {
            mp[2]++;
        }
    }

    int cnt = mp[4] + mp[2]/2;

    if (n/2 <= cnt) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;

}