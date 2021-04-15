#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int K, N;
    cin >> N >> K;

    vector<int> l(N);
    for (int i = 0; i < N; i++)
        cin >> l[i];

    sort(l.rbegin(), l.rend());

    int sum = 0;
    for (int i = 0; i < K; i++)
        sum += l[i];

    cout << sum << endl;
}
