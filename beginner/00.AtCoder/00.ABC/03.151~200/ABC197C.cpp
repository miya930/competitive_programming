#include <iostream>
#include <vector>
using namespace std;
const int INF = 2000000000;

template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main(void)
{
    int N; 
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    int res = INF;
    for (int bits = 0; bits < (1 << N-1); ++bits) {
        int or_ = a[0];
        int xor_ = 0;
        for (int i = 0; i < N-1; ++i) {
            if (bits & (1<<i)) {
                xor_ ^= or_;
                or_ = 0;
            }
            or_ |= a[i+1];
        }
        xor_ ^= or_;
        chmin(res, xor_);
    }
    cout << res << endl;
}
