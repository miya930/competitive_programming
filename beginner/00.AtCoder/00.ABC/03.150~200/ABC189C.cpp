#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    int res = 0;
    for (int l = 0; l < N; ++l) {
        int x = a[l];
        for (int r = l; r < N; ++r) {
            x = min(x, a[r]);
            res = max(res, x*(r-l+1));
        }
    }
    cout << res << endl;
}
