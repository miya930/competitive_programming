#include <iostream>
#include <vector>
using namespace std;

int main (void)
{
    int N;
    cin >> N;
    vector<int> h(N+1, 0);
    for (int i = 0;i <N;i++) cin >> h[i];

    int zero_cnt = 0;
    int ans = 0;
    while (true) {
        int l = 0;
        int r = 0;
        int zero_cnt = 0;
        for (int i = 0; i <= N; i++) {
            if (h[i] != 0) {
                r++;
            } else {
                for (int j = l; j < r; j++) {  
                    if (h[j] > 0) h[j]--;
                }
                if (l != r)
                    ans++;
                l = i + 1;
                r = i + 1;
            }
        }
        for (int i = 0; i < N;i++) {
            if (h[i] == 0) zero_cnt++;   
        }
        if (zero_cnt == N) break;
    }
    cout << ans << endl;
}
