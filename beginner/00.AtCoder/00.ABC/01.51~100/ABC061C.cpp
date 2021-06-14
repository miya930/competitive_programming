#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n, k;
vector<pair<long long, long long> > A;

int main()
{
    cin >> n >> k;
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        A[i].first = a;
        A[i].second = b;
    }
    sort(A.begin(), A.end());

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        count += A[i].second;
        if (count >= k) {
            cout << A[i].first << endl;
            return 0;
        }
    }
    cout << A[n-1].first << endl;

}
