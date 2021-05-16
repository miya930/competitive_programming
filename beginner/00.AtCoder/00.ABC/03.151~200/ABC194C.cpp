#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // �ݐϘa
    vector<ll> s(N+1, 0);
    for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];

    ll res = (N-1)*a[0]*a[0];
    for (int i = 1; i < N; ++i) {
        res += (N-1)*a[i]*a[i] - 2*a[i]*s[i]; 
    }
    cout << res << endl;
}
