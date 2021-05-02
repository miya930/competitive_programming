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

        rep(i, N) t[i] = x/a[i];                                                // t[i](0<=i<N)�ȉ��ƂȂ�b�����ׂđ����グ�邽��
        int tmp = 0;                                                            // �� ���̂悤��b�����߂邽�߂ɓ񕪒T����p����
        rep(i, N) tmp += upper_bound(b.begin(), b.end(), t[i]) - b.begin();     // a*b <= X�𖞂���b�̌�tmp���v�Z
        if (tmp >= K) right = x;                                                // tmp >= K�𖞂����ŏ���tmp�����܂�܂ő���
        else left = x;
    }
    cout << right << endl;
}
