#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if (s[n-1] == 's') cout << s + "es" << endl;
    else cout << s + "s"  << endl;
}
