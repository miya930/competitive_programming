#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int p;
    cin >> p;

    int ans = 0;
    for (int i = 10; i >= 0; --i) {
        int tot = 1;
        for (int j = 1; j <= i; ++j) tot *= j;
        while (p >= tot) {
            p -= tot;
            ans++;
        }
    }

    cout << ans << endl;
}
