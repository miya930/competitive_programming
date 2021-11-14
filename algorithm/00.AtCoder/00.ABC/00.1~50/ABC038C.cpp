#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kaijo(int n) {
    int tmp = 1;
    for (int i = 1; i < n; i++)
        tmp *= i;
    return tmp;
}

int main(void)
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int ans = 0;
    int right = 1;
    for (int left = 0; left < N; left++) {
        while (right < N && (right <= left || a[right - 1] < a[right])) {
            ++right;
        }
        ans += right - left;
        if (left == right) ++right;
    }
    
    cout << ans << endl;
}
