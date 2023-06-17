#include <iostream>
using namespace std;
#define MAX_N 100001

int N, K;
long long int A[MAX_N] = { 0 };
long long int S[MAX_N];
long long int ans = 0;

void solve() {
    long long int R[MAX_N] = { 0 };
    for (int i = 1; i <= N; i++) {
        // start address
        if (i == 1) R[i] = 0;
        else R[i] = R[i - 1];

        while (R[i] < N && S[R[i] + 1] - S[i-1] <= K) {
            R[i]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        ans += (R[i] - i + 1);
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        S[i] += S[i - 1] + A[i];
    }

    solve();

    return 0;
}
