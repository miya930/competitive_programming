#include <iostream>
#include <algorithm>
using namespace std;

int counter(int x) {
    if(x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}

void solve(void);

int main(void)
{
    int N;
    int A[20], x[20][20], y[20][20];

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int j = 1; j <= A[i]; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    
    int ans = 0;
    for (int bits = 0; bits < (1<<N);bits++) {
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            if(!(bits & (1 << (i - 1)))) continue;
            for (int j = 1; j < A[i]; j++) {
                if(((bits >> (x[i][j] - 1)) & 1)^y[i][j]) ok = false;
            }
        }
        if(ok) ans = max(ans, counter(bits));
    }
    cout << ans << endl;
    return 0;
}
