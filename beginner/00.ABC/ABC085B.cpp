#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> d(N);
    for(int i = 0; i < N; i++)
        cin >> d[i];
    
    sort(d.rbegin(), d.rend());

    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (d[i] > d[i+1])
            cnt++;
    }
    cout << cnt + 1 << endl;
}
