#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> x(M);
    for (int i = 0; i < M; ++i) cin >> x[i];

    if (N >= M) {
        cout << 0 << endl;
        return 0;
    }

    sort(x.begin(), x.end());

    vector<int> y(M,0);
    for (int i = 1; i < M; ++i) y[i] = x[i] - x[i-1];
    
    sort(y.begin(), y.end());

    int ans = 0;
    for (int i = 1; i <= M - N; ++i) ans += y[i];

    cout << ans << endl;
}
