#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int s, t;
    cin >> s >> t;

    int ans = 0;

    for (int i = 0;i <= 100; ++i) {
        for (int j = i; j <= 100; ++j) {
            for (int k = j; k <= 10000; ++k) {
                int temp = i + j + k;
                int temp2 = i * j * k;
                if (temp > s) continue;
                if (temp2 > t) continue;
                if (i == j && j == k) {
                    ans++;
                } else if (i == j || j == k || k == i) {
                    ans += 3;
                } else {
                    ans += 6;
                }
            }
        }
    }    
    cout << ans << endl;
}
