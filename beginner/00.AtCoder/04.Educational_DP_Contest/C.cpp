#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;}

int main(void)
{
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; ++i) cin >> a[i] >> b[i] >> c[i];

    vector<int> dp_a(N+1, 0), dp_b(N+1, 0), dp_c(N+1, 0);
    for (int i = 0; i < N; ++i) {
        chmax(dp_a[i+1], dp_b[i]+a[i]);
        chmax(dp_a[i+1], dp_c[i]+a[i]);
        chmax(dp_b[i+1], dp_a[i]+b[i]);
        chmax(dp_b[i+1], dp_c[i]+b[i]);
        chmax(dp_c[i+1], dp_a[i]+c[i]);
        chmax(dp_c[i+1], dp_b[i]+c[i]);
    }
    cout << max(dp_a[N], max(dp_b[N], dp_c[N])) << endl;
}
