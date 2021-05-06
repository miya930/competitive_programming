#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    ll temp = 0;
    ll ans = 0;
    int right = 0;
    for (int left = 0; left < N; ++left) {
        while (right < N && ((temp ^ A[right]) == (temp + A[right]))) {
            temp += A[right];
            right++;
        }
        ans += right - left;
        if (left == right) right++;
        else temp -= A[left];
    }
    cout << ans << endl;
}
