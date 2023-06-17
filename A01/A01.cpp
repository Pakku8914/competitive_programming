#include <cmath>
#include <iostream>
using namespace std;

int N;
int ans;

void solve() {
    ans = pow(N, 2);
}

int main() {
    cin >> N;
    solve();
    cout << ans << endl;

    return 0;
}