#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' && i%2 == 0) {
            cout << "Takahashi" << endl;
            return 0;
        } else if (s[i] == '1' && i%2 == 1) {
            cout << "Aoki" << endl;
            return 0;
        } 
    }

}
