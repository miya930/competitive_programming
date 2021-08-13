#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n ; ++i) cin >> a[i];

    bool sign = false;
    for (int i = 0; i < n; ++i) {
        if (sign) b[0] -= a[i%n];
        else b[0] += a[i%n];
        sign = !sign; 
    }

    for (int i = 1; i < n; ++i) {
        b[i] = 2*a[i-1] - b[i-1];
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
