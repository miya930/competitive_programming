#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(void)
{
    ll N;
    cin >> N;

    int comma = 0;
    ll res = 0;
    ll l = 1, r = 10;
    for (int i = 0; i < 16; ++i) {
        if (r <= N) res += (r - l) * comma;
        else if (l <= N && r > N) res += (N - l + 1) * comma;

        l *= 10;
        r *= 10;
        if (i % 3 == 2) comma++;
    }
    cout << res << endl;
}
