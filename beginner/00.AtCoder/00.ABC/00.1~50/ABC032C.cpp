#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<ll> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        if (s[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }
    int right = 0;
    int ans = 0;
    ll sum = 1;
    for (int left = 0; left < N; left++) {
        while(right<N && sum<=K) {
            sum *= s[right];
            if (sum > K) {
                sum /= s[right];
                break;
            }
            right++;
        }
        if (left != right)
            sum /= s[left];
        ans = max(ans, right - left);
        if(left == right) right++;
    }
    cout << ans << endl;
}
