#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main()
{
    int x; cin >> x;

    vec.assign(200000, 1);
    vec[0] = 0; vec[1] = 0;

    for (int i = 2; i < vec.size(); ++i) {
        for (int j = i*2; j < vec.size(); j += i) {
            vec[j] = 0;
        }
    }

    bool flg = false;
    int ans;
    for (int i = 2; i < vec.size(); ++i) {
        if (vec[i] == 1 && !flg && i >= x) {
            ans = i;
            flg = true;
        }
    }

    cout << ans << endl;
    return 0;
}
