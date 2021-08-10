#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a[i] = make_pair(b, i);        
    }
    sort(a.rbegin(), a.rend());
    cout << a[1].second + 1<< endl;
}
