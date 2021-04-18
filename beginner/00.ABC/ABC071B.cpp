#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string S;
    cin >> S;

    int Num[26] = {0};        // �o�P�b�g

    for (int i = 0; i < S.length(); i++) {
        Num[S[i]-'a']++;        // a=>0, b=>1, c=>2, �E�E�E�Ƃ���
    }

    int min_flag = 100;         // S�Ɍ���Ȃ�������\��

    for (int i = 0; i < 26; i++) {
        if(Num[i] == 0)
            min_flag = min(min_flag, i);

    }

    if (min_flag < 26)
        cout << "abcdefghijklmnopqrstuvwxyz"[min_flag] << endl;
    else
        cout << "None" << endl;
}
