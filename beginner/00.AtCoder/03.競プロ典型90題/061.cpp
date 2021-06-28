#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int q; 
    cin >> q;
    vector<int> vec;

    for (int i = 0; i < q; ++i) {
        int t, x; cin >> t >> x;
        if (t == 2) {
            vec.push_back(x);
        } else if (t == 1) {
            vec.insert(vec.begin(),1,x);
        } else {
            cout << vec[x-1] << endl;
        }
    }
    return 0;
}
