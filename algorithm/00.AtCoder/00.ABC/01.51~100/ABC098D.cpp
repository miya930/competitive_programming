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

    int ans = 0;
    int sum = 0;
    int right = 0;
    for (int left = 0; left < N; left++) {
        while ((right < N) && (sum ^ a[right]) == (sum + a[right])) {
            sum += a[right];
            right++;
        }
        ans += right - left;
        if(left == right) right++;
        else sum -= a[left];
    }
    cout << ans << endl;
}
