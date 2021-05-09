#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    char temp = s[0];
    for (int i = 0; i < s.size()-1; ++i) 
        s[i] = s[i+1]; 
    s[s.size()-1] = temp;

    cout << s << endl;
}
