#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int A, B, K;
    cin >> A >> B >> K;

    int cnt = 0;
    vector<int> ans(200,0);

    for (int i = min(A,B); i > 0;i--) {
        if ((A%i==0) && (B%i==0)) {
            cnt++;
            ans[cnt] = i;
            if (cnt == K) {
                cout << ans[K] << endl;
                return 0;
            }
        }
    }
}
