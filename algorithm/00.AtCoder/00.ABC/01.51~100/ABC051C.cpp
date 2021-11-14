#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string ans = "";
    
    // first
    rep(i, abs(ty-sy)) ans += 'U';
    rep(i, abs(tx-sx)) ans += 'R';
    rep(i, abs(ty-sy)) ans += 'D';
    rep(i, abs(tx-sx)) ans += 'L';

    // second
    ans += 'L';
    rep(i, abs(ty-sy)+1) ans += 'U';
    rep(i, abs(tx-sx)+1) ans += 'R';
    ans += 'D';
    ans += 'R';
    rep(i, abs(ty-sy)+1) ans += 'D';
    rep(i, abs(tx-sx)+1) ans += 'L';
    ans += 'U';

    cout << ans << endl;

}
