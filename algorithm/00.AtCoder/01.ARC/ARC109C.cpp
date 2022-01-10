#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    string copy = s + s;
    for (int i = 0; i < k; ++i) {
        string t = "";
        int ma = copy.size();
        for (int j = 0; j < ma; j += 2) {
            if (copy[j] == 'R' && copy[j+1] == 'S') t += 'R';
            else if (copy[j] == 'S' && copy[j+1] == 'R') t += 'R';
            else if (copy[j] == 'R' && copy[j+1] == 'P') t += 'P';
            else if (copy[j] == 'P' && copy[j+1] == 'R') t += 'P';
            else if (copy[j] == 'S' && copy[j+1] == 'P') t += 'S';
            else if (copy[j] == 'P' && copy[j+1] == 'S') t += 'S'; 
            else t += copy[j];
        }

        copy = t + t;
    }

    cout << copy[0] << endl;
    return 0;
}
