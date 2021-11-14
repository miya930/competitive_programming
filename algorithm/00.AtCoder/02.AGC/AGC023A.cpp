#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
typedef long long ll;

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> sum(N+1, 0);
    map<ll, ll> nums;
    for (int i = 0; i < N; i++) sum[i+1] = sum[i] + A[i];
    for (int i = 0; i < N; i++) nums[A[i]]++;

    // WŒvˆ—
    ll ans = 0;
    for (auto it: nums) {
        ll num = it.second;
        ans += num * (num - 1) / 2;
    }

    cout << ans << endl;
}