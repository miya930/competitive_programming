#include <iostream>
#include <vector>
using namespace std;
const int N = 8;
vector<int> a(N);

// –Ú“I‚Ì’l key ‚Ì“Y‚¦š‚ğ•Ô‚· (‘¶İ‚µ‚È‚¢ê‡‚Í-1)
int binary_search(int key) {
    int left = 0, right = (int)a.size()-1;
    while (left <= right) {
        int mid = (left+right)/2;
        if(a[mid] == key) return mid;
        else if (a[mid] > key) right = mid - 1;
        else if (a[mid] < key) left = mid + 1;
    }
    return -1;
}

int main(void)
{
    for (int i = 0; i < 8; i++) cin >> a[i];

    cout << binary_search(10) << endl;
    cout << binary_search(3) << endl;
    cout << binary_search(39) << endl;
    
    cout << binary_search(-100) << endl;
    cout << binary_search(9) << endl;
    cout << binary_search(100) << endl;
}
