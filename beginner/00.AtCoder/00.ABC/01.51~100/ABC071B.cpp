#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string S;
    cin >> S;

    int Num[26] = {0};        // バケット

    for (int i = 0; i < S.length(); i++) {
        Num[S[i]-'a']++;        // a=>0, b=>1, c=>2, ・・・とする
    }

    int min_flag = 100;         // Sに現れない文字を表す

    for (int i = 0; i < 26; i++) {
        if(Num[i] == 0)
            min_flag = min(min_flag, i);

    }

    if (min_flag < 26)
        cout << "abcdefghijklmnopqrstuvwxyz"[min_flag] << endl;
    else
        cout << "None" << endl;
}
