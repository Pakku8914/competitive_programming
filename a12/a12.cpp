#include <iostream>
using namespace std;
#define MAX_N 100001

long long int N, K;
long long int A[MAX_N];
long long int ans = 0;

void solve() {
    long long int f, e;
    f = 1;
    e = 1000000000;
    while (f < e) {
        int m = (f + e) / 2;
        long long int sum = 0;
        for (int i = 1; i <= N; i++) {
            sum += m / A[i];
        }
        if (K <= sum) {
            e = m;
        }
        else {
            f = m + 1;
        }
    }
    ans = f;
}

int main() {
    // “ü—Í
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    solve();
    cout << ans << endl;
}