#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];

    map<string, int> mp;

    for(int i = 0; i < N; i++) {
        if (mp[s[i]]) continue;
        mp[s[i]]++;
        cout << i+1 << endl;
    }
}
