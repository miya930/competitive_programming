#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int shift = 0;

    for (int q = 0; q < Q; ++q) {
        int t, x, y;
        cin >> t >> x >> y;
        x--; y--;
        if (t==1) {
            swap(a[(x+shift)%n], a[(y+shift)%n]);
        }
        else if (t==2) shift = (shift + n - 1) % n;
        else cout << a[(x+shift)%n] << endl;
    }
    return 0;
}
