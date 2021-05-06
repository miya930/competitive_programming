#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];

    for (int i = 0; i < N; i++) {
        if (s[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }

    int right = 0;
    int ans = 0;
    long long sum = 1;
    for (int left = 0; left < N; left++) {
        while(right < N && sum*s[right] <= K) {
            sum *= s[right];
            right++;
        }
        ans = max(ans, right - left);
        if (left == right) right++;
        else sum /= s[left];
    }
    cout << ans << endl;
}
