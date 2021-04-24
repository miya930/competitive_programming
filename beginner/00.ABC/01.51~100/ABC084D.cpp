#include <iostream>
#include <vector>
using namespace std;
const int MAX = 101010;

int main(void)
{  
    // エラトステネスのふるい
    vector<int> is_prime(MAX,1);
    is_prime[0] = 0; is_prime[1] = 0;

    for (int i = 2; i < MAX; i++) {
        if (!is_prime[i]) continue;
        for (int j = i*2; j <= MAX; j += i)  is_prime[j] = 0;
    }

    // 2017-likeか調べる
    vector<int> a(MAX, 0);
    for (int i = 0; i < MAX; i++) {
        if (i%2 == 0) continue;
        if (is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
    }

    // 累積和
    vector<int> s(MAX+1,0);
    for (int i = 0; i < MAX; i++) s[i+1] = s[i] + a[i];

    // クエリの処理
    int Q; cin >> Q;
    vector<int> l(Q), r(Q);
    for (int q = 0; q < Q; q++) {
        cin >> l[q] >> r[q];
    }

    for (int i = 0 ; i < Q; i++) {
        cout << s[r[i]+1] - s[l[i]] << endl;
    }
}
