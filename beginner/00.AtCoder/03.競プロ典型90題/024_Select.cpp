#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    ll res = 0;

    for (int i = 0; i < N; ++i) 
        res += abs(A[i]-B[i]);

    if ((res > K) || (res%2 != K%2))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
