#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s;
    int Q;
    cin >> s >> Q;

    bool rev = false;
    string fo = "", ba = "";
    for (int q = 0; q < Q; ++q) {
        int t;
        cin >> t;
        if (t == 1) rev = !rev;
        if (t == 2) {
            int f; char c;
            cin >> f >> c;
            if ((!rev && (f == 2)) || (rev && (f == 1))) ba += c;
            else fo += c;
        }
    }
    
    if (!rev) {
        reverse(fo.begin(), fo.end());
        s = fo + s + ba;
    } else {
        reverse(s.begin(), s.end());
        reverse(ba.begin(), ba.end());
        s = ba + s + fo;
    }
    cout << s << endl;

}
