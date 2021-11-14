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

    vector<int> comp = a;
    sort(comp.begin(), comp.end());

    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    }

    for (int i = 0; i < n; ++i) cout << a[i] << endl;
    return 0;
}
