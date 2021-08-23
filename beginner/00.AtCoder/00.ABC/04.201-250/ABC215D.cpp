#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int MAX_N = 100100;
vector<bool> is_prime(MAX_N, true);

vector<int> prime(vector<int> a) {
    vector<int> res;
    int m = a.size();
    for (int i = 0; i < m; ++i) {
        int n = a[i];
        for (int j = 2; j*j <= n; ++j) {
            if (n%j!=0) continue;
            res.push_back(j);
            while (n%j == 0) {
                n /= j;
            }
        }
        if (n != 1) res.push_back(n);
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> prim = prime(a);

    is_prime[0] = false;
    is_prime[1] = true;
    for (int i = 0; i < prim.size(); ++i) {
        int temp = prim[i];
        is_prime[temp] = false;
        for (int j = temp*2; j < MAX_N; j += temp) {
            is_prime[j] = false;
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        if (is_prime[i]) cnt++;
    }
    cout << cnt << endl;

    for (int i = 1; i <= m; ++i) {
        if(is_prime[i]) cout << i << endl;
    }
    return 0;

}



/***
 * ↓改めて解いた方法
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> enumPrime(int a) {
    vector<int> res;
    for (int i = 2; i * i <= a; ++i) {
        if (a % i != 0) continue;
        while (a % i == 0) a /= i;
        res.push_back(i);
    }
    if (a != 1) res.push_back(a);
    return res;
}

const int MAX_N = 100100;
vector<bool> isprime(MAX_N, true);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        vector<int> vec = enumPrime(a[i]);
        for (int k = 0; k < vec.size(); ++k) {
            isprime[vec[k]] = false;
        }
    }

    for (int i = 2; i < MAX_N; ++i) {
        if (isprime[i] == false) {
            for (int j = i*2; j < MAX_N; j += i) isprime[j] = false;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        if (isprime[i]) cnt++;
    }
    cout << cnt << endl;

    for (int i = 1; i <= m; ++i) {
        if (isprime[i]) cout << i << endl;
    }
    return 0;

}
