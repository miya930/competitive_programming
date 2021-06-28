#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    map<int, int> mp_even, mp_odd;

    for (int i = 0; i < n; i += 2) mp_even[v[i]]++;
    for (int i = 1; i < n; i += 2) mp_odd[v[i]]++;

    int max_even = 0, max_odd = 0;
    for (auto x : mp_even) {
        if (max_even < x.second) {
            max_even
        }
    }
    for (auto x : mp_odd) {

    }
    
}
