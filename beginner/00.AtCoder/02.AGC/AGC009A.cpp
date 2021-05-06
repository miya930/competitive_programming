#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];

    ll ans = 0;

    for (int i = 0; i < N; ++i) {
        if (A[N-i-1]%B[N-i-1])
            ans += B[N-i-1] - (A[N-i-1] % B[N-i-1]);
        if (i != N-1) A[N-i-2] += ans;
    }
    cout << ans << endl;
}
