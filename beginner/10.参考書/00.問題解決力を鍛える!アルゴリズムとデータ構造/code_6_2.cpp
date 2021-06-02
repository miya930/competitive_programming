#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    cout << "数当てゲームスタート" << endl;

    int left = 20, right = 36;

    while (right - left > 1) {
        int mid = (right+left)/2;
        cout << "Is the age less than" << mid << "? (Yes / No)" << endl;
        string ans;
        cin >> ans;
        if (ans == "Yes") right = mid;
        else if (ans == "No") left = mid;
    }

    cout << "The age is " << left << "!" << endl;
}
