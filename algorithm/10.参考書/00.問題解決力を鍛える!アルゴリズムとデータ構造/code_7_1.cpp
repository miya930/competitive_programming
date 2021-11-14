#include <iostream>
#include <vector>
using namespace std;

const int value[6] = {500, 100, 50, 10, 5, 1};

int main(void)
{
    int x;
    vector<int> a(6);
    cin >> x;
    for (int i = 0; i < 6; i++) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < 6; ++i) {
        int add = x / value[i];
        
        if (add > a[i]) add = a[i];
        x -= value[i]*add;
        ans += add;
    } 
    cout << ans << endl;
}
