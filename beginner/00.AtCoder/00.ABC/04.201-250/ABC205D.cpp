#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<ll> low(N);
    for (int i = 0; i < N; ++i) {
        low[i] = A[i] - (i+1);
    }
    while(Q--) {
        ll k;
        cin >> k;
        const int idx = lower_bound(low.begin(), low.end(), k) - low.begin();
        if (idx == N) {
            cout << A[N-1] + (k - low[N-1]) << endl;
        } else {
            cout << A[idx] - (low[idx] - k + 1) << endl;
        }
    }
    return 0;
}
