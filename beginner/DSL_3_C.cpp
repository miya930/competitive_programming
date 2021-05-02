#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,start, end) for(int i = (start); i < (end); i++)

int main(void)
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N), x(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < Q; i++) cin >> x[i];

    ll cnt = 0;

    for (int i = 0; i < Q; i++) {
        int left = 0, right = 0;
        cnt = 0;
        while(left < a.size()) {
            ll sum = 0;
            for(int j = left; j <= right; j++) sum += a[j];
            if (sum <= x[i]) {
                cnt++;
                right++;
                if (right == a.size()) {
                    left++;
                    right = left;
                }
            } else {
                left++;
                right = left;
            }
        }
        cout << cnt << endl;
    }
}
