#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };

vector<int> eratosthenes(int n) {
   vector<int> ret(n+1, 0);
   for (int i = 2; i <= n; i++) {
      if (ret[i] != 0) continue;
      for (int j = i; j <= n; j+=i) {
         ret[j]++;
      }
   }
   return ret;
}

int main()
{
    int Q;
    cin >> Q;
    vector<ll> vec;
    vector<int> is_prime = eratosthenes(1000100);

    for (ll i = 6; i <= 1000000; i++) {
        if (is_prime[i] != 2) continue;
        vec.push_back(i*i);
    }
    int n = vec.size();
    rep(q, 0, Q) {
        ll a; cin >> a;
        cout << *prev(upper_bound(vec.begin(), vec.end(), a)) << endl;
    }

    return 0;
}
