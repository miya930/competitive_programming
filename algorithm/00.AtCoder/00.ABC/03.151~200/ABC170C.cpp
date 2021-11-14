#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000100;

int main()
{
    int x, n; cin >> x >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<bool> vec(201);
    for (int i = 0; i < n; ++i) vec[p[i]] = true;

    int ans;
    int temp = INF;
    for (int i = 0; i <= 200; ++i) {
        if (vec[i] == false &&(temp > abs(x-i))) {
            temp = abs(x-i);
            ans = i;
        }
    }
    cout << ans << endl;
}
