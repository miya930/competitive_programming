#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    // バケット
    vector<int> b(100010, 0);

    int ans = 0;
    int right = 0;
    for (int left = 0; left < N; left++) {
        while(right<N && b[a[right]] == 0) {
            b[a[right]] = 1;
            right++;
        }
        ans = max(ans, right - left);
        b[a[left]] = 0;
        if (left == right) right++;
    }
    cout << ans << endl;
}
