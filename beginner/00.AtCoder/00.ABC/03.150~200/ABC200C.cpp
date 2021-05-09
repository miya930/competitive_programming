#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    for (int i = 0; i < N; ++i) {
        a[i] %= 200;
    }

    map<int, int> mp;

    for (int i = 0; i < N; ++i) {
        mp[a[i]]++;
    }

    long long ans = 0;
    for (auto itr : mp) {
        long long n = itr.second;
        if (n != 1) 
            ans += n*(n-1)/2;
    }
    cout << ans << endl;
}
