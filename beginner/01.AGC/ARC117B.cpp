#include <iostream>
#include <algorithm>
using namespace std;
long long mod = 1000000007;
long long N, A[1<<18], Q[1<<18];
long long answer = 1;

int main(void)
{
    long long N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> A[i];
    sort(A+1, A+N+1);
    for (int i = 1; i <= N; i++) Q[i] = A[i] - A[i-1];

    // Get Answer
    for (int i = 1; i <= N; i++) {
        answer *= (Q[i] + 1LL);
        answer %= mod;
    }
    cout << answer << endl;
    return 0;
}
