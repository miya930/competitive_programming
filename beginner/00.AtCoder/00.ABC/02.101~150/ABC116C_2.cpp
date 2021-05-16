#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> h(N+1, 0);
    for (int i = 0; i < N; i++) cin >> h[i];

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (h[i] > h[i+1]) res += h[i] - h[i+1];
    }
    cout << res << endl;
}
