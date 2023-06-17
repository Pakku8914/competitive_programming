#include <iostream>
using namespace std;
#define MAX_N 100001

// “ü—Í
int N, D;
int A[MAX_N];
int F[MAX_N];
int B[MAX_N];

int main() {
    // ‰Šú’l“ü—Í
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    F[1] = A[1];
    for (int i = 1; i <= N; i++) {
        F[i] = max(A[i], F[i - 1]);
    }
    B[N] = A[N];
    for (int i = N - 1; 0 < i; i--) {
        B[i] = max(A[i], B[i + 1]);
    }

    cin >> D;
    for (int i = 0; i < D; i++) {
        int l, r;
        cin >> l >> r;
        cout << max(F[l - 1], B[r + 1]) << endl;
    }
}