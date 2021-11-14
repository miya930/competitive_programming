#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    long long ans = 1;

    for (int i = N; i > 0; i--) {
        if (i == N)
            ans *= K;
        else
            ans *= K-1;
    }

    cout << ans << endl;

}
