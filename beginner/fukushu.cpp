#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) cin >> p[i], p[i]--;
    for (int i = 0; i < n; ++i) cin >> q[i], q[i]--;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) vec[i] = i;

    int cnt = 0;
    int a, b;
    do {
        bool p_flag = true, q_flag = true;
        for (int i = 0; i < n; ++i) {
            if (p[i] != vec[i]) p_flag = false;
        }
        for (int i = 0; i < n; ++i) {
            if (q[i] != vec[i]) q_flag = false;
        }
        if (p_flag) a = cnt;
        if (q_flag) b = cnt;

        cnt++;
    } while(next_permutation(vec.begin(), vec.end()));

    cout << abs(a-b) << endl;

}
