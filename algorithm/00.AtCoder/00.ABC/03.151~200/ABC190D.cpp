#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll; 

int main()
{
    ll N;
    cin >> N;

    while(N % 2== 0) N /= 2;
    ll sq = sqrt(N), ans = 0;
    for (int i = 1; i <= sq; ++i) {
        if (N % i == 0) ans += 2;
    }
    if (sq*sq == N) ans--;
    cout << ans * 2 << endl;
}
