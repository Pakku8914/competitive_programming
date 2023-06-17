#include <iostream>
using namespace std;

long long int N;
double x;

void solve() {
    double l = 0, r = N;
    while (l < r) {
        double mid = (l + r) / 2;
        double cul = mid * mid * mid + mid;
        double diff = N - cul;
        if (-0.001 <= diff && diff <= 0.001) {
            x = mid;
            break;
        }
        else if (0 < diff) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
}

int main() {
    cin >> N;
    solve();
    cout << x << endl;
}