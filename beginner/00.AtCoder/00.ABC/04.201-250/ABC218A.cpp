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

    if (s[n-1] == 'o') cout << "Yes" << endl;
    else cout << "No" << endl;
}
