#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
  
  	cout << max(a[0]+a[1]+a[2]-3*'0', b[0]+b[1]+b[2]-3*'0') << endl;
}