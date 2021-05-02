#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000010;

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> s(N);
    bool zero_flag = false;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        if (s[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }

    int max_len = 0;
    int left = 0, right = 0;
    long long sum = 1;
    while(left < N) {
        sum = 1;
        for(int j = left; j <= right; j++) sum *= s[j]; // –ˆ‰ñ j = left‚©‚çŒvŽZ‚·‚é‚©‚çŒø—¦‚ªˆ«‚¢B
        if (sum <= K) {
            max_len = max(max_len, right - left + 1);
            right++;
            if(right == N) {
                left++;
                right = left;
            }
        } else {
            left++;
            right = left;
        }
    }
    cout << max_len << endl;
}