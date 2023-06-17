#include <algorithm>
#include <iostream>
using namespace std;
#define MAX_N 100001

int N, Q;
int A[MAX_N];
int X[MAX_N];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> X[i];
    }
    sort(A + 1, A + N + 1);

    for (int i = 1; i <= Q; i++) {
        int pos = lower_bound(A + 1, A + N + 1, X[i]) - A - 1;
        if (pos <= N) {
            cout << pos << endl;
        }
    }
}