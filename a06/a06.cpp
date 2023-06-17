#include <iostream>
using namespace std;
#define MAX_N 100001
int N, Q, A[MAX_N];
int ans;

void solve(int start, int end) {
    ans = A[end] - A[start - 1];
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int l;
        cin >> l;
        A[i] = l + A[i - 1];
    }
    for (int i = 0; i < Q; i++) {
        int s, e;
        cin >> s >> e;
        solve(s, e);
        cout << ans << endl;
    }
}