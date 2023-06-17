#include <iostream>
using namespace std;
#define MAX_N 100001

int N, X;
int A[MAX_N];
int ans;

int search(int x) {
    int pos = lower_bound(A + 1, A + N, x) - A;
    if (pos <= N && A[pos] == x) return pos;
    return -1;
}

int main() {
    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // “ñ•ª’Tõ‚ğs‚¤
    int Answer = search(X);
    cout << Answer << endl;
    return 0;
}