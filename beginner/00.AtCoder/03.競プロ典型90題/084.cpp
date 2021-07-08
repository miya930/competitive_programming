#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    string s;
    cin >> n >> s;

    vector<long long> mp;

    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt++;
        if (i == n - 1 || s[i] != s[i + 1]) {
            mp.push_back(cnt);
            cnt = 0;
        }
    }

    long long sum = 0;
    for (int i = 0; i < mp.size(); ++i) {
        long long temp = mp[i];
        sum += temp * (temp + 1LL) / 2LL;
    }

    long long ans = n * (n+1) / 2LL - sum;

    cout << ans << endl;
}
