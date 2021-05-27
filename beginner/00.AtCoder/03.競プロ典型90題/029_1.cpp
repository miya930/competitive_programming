#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[524288];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        l--;
        int height = *max_element(a + l, a + r) + 1;
        fill(a + l, a + r, height);
        cout << height << endl;
    }
    return 0;
}
