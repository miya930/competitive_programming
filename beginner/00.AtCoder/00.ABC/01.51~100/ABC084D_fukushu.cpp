#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100020;

int main(void)
{
    int Q;
    cin >> Q;
    vector<int> l(Q), r(Q);
    for (int i = 0; i < Q; i++) cin >> l[i] >> r[i];

    // エラトステネスのふるい
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0; is_prime[1] = 0;
    for (int i = 2; i < is_prime.size(); i++) {
        if (is_prime[i] == 0) continue;
        else {
            for (int j = 2*i; j < is_prime.size(); j += i) {
                is_prime[j] = 0;
            }
        }
    }

    // 2017数の判定
    vector<int> a(MAX, 0);
    for (int i = 0; i < MAX; i++) {
        if (i%2 == 0) continue;
        if (is_prime[i] == 1 && is_prime[(i+1)/2] == 1) {
            a[i] = 1;
        }
    }

    // 累積和
    vector<int> s(MAX+1, 0);
    for (int i = 0; i < MAX; i++) s[i+1] = s[i] + a[i];

    // クエリに対する答えを出力
    for (int i = 0; i < Q; i++) {
        cout << s[r[i]+1] - s[l[i]] << endl;
    }

    return 0;
}
