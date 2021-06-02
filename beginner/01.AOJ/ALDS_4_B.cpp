#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    int n; cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; ++i) cin >> S[i];
    int q; cin >> q;
    vector<int> T(n);
    for (int i = 0; i < q; ++i) cin >> T[i];

    long long ans = 0;

    for (int i = 0; i < q; ++i) {
        int left = 0;
        int right = S.size();
        int key = T[i];
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (S[mid] > key) right = mid;
            else left = mid; 
        }
        if (S[left] == key) ans++;
    }
    cout << ans << endl;
}
