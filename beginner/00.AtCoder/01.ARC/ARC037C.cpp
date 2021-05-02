#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    sort(b.begin(), b.end());
    vector<ll> t(N, 0);

    ll left = 0, right = INF;
    while(right - left > 1) {
        ll x = (right+left)/2;

        rep(i, N) t[i] = x/a[i];                                                // t[i](0<=i<N)ˆÈ‰º‚Æ‚È‚éb‚ğ‚·‚×‚Ä‘«‚µã‚°‚é‚½‚ß
        int tmp = 0;                                                            // ¨ ‚±‚Ì‚æ‚¤‚Èb‚ğ‹‚ß‚é‚½‚ß‚É“ñ•ª’Tõ‚ğ—p‚¢‚é
        rep(i, N) tmp += upper_bound(b.begin(), b.end(), t[i]) - b.begin();     // a*b <= X‚ğ–‚½‚·b‚ÌŒÂ”tmp‚ğŒvZ
        if (tmp >= K) right = x;                                                // tmp >= K‚ğ–‚½‚·Å¬‚Ìtmp‚ª‹‚Ü‚é‚Ü‚Å‘±‚­
        else left = x;
    }
    cout << right << endl;
}
