#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(2*n+1,0);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        b[i] = b[i-1] + a[i-1];
    }

    for (int i = 1; i <= n; ++i) {
        b[n+i] = b[n+i-1] + a[i-1]; 
    }

    if (b[n]%10 != 0) {
        cout << "No" << endl;
        return 0;
    }

    for (int left = 0; left <= n; ++left) {
        long long obj = b[left] + b[n] / 10;
        long long iter = lower_bound(b.begin(), b.end(), obj) - b.begin();
        if (b[iter] == obj) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
