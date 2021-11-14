#include <iostream>
using namespace std;

bool found (int n) {
    while (n > 0) {
        int mod = n % 10;
        if (mod == 7) return false;
        n /= 10;
    }
    return true;
}

int d2o(int n) {
    int res = 0;
    int keta = 1;
    while (n > 0) {
        int temp = n % 8;
        temp *= keta;
        keta *= 10;
        res += temp;
        if (n / 8 == 0) {
            res += (n / 8 * keta);
            return res;
        }
        n /= 8;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (found(i) && found(d2o(i))) ans++;
    }
    cout << ans << endl;
}
