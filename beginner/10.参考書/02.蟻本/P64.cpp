#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> dp(n+1); // a[i]FÅŒã‚ªi€–Ú‚Å‚ ‚é‚æ‚¤‚È‘‰Á•”•ª—ñ‚Ì’·‚³
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                chmax(dp[i], dp[j]+1);
            }
        } 
    }
}
