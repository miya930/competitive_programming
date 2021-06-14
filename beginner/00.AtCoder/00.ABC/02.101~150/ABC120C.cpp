#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int cnt_z = 0, cnt_o = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') cnt_z++;
        else cnt_o++;
    }

    cout << 2*min(cnt_z, cnt_o) << endl;
}
