#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> a(3*N);
    for (int i = 0; i < 3*N; i++)
        cin >> a[i];
    
    sort(a.begin(), a.end());

    long long sum = 0;

    for (int i = N; i < 3*N;i+=2)
        sum += a[i];

    cout << sum << endl;
}
