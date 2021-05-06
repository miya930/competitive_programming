#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll sum = A[0];
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        ans += sum*A[i]; ans %= MOD; 
        sum += A[i]; sum %= MOD;
    }
    cout << ans << endl;
}
