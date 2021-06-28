#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = n-1; i >= 0; i -= 2) b.push_back(a[i]);
    int cnt = 0;
    if (n%2==1) cnt++;
    for (int i = cnt; i < n-1; i += 2) b.push_back(a[i]);

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
