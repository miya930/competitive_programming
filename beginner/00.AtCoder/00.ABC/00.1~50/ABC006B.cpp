#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 10007;
vector<int> memo;

int tribo(int n) {
    if (n == 1) return 0;
    if (n == 2) return 0;
    if (n == 3) return 1;

    if (memo[n] != -1) return memo[n];

    memo[n] = (tribo(n - 1) + tribo(n - 2) + tribo(n - 3)) % MOD;
    return memo[n];
}

int main()
{
    int n; cin >> n;
    memo.assign(n + 1, -1);

    cout << tribo(n) << endl;
}
