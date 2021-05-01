#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{  
    int N;
    cin >> N;

    vector<double> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    double maximum = 0;

    for (int i = 0; i < N ; i++) {
        for (int j = i; j < N; j++) {
        maximum = max(maximum, sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
        }
    }

    cout << maximum << endl;
    
}
