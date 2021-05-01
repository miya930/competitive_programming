#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0;i < N;i++) cin >> L[i];

    int sum = 0;
    sort(L.rbegin(), L.rend());
    for (int i = 1; i < N; i++) {
        sum += L[i];
    }

    if (sum <= L[0]) cout << "No" << endl;
    else cout << "Yes" << endl;

}
