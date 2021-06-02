#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i]*b[i];
    }
    if (ans == 0) cout << "Yes" << endl;
    else cout << "No" << endl; 
}
