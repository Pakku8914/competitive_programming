// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp

#include <iostream>
using namespace std;
#define MAX_N 100001
#define MAX_Q 500

int N, Q;
long long int a[MAX_N];
long long int x[MAX_Q];
long long int s[MAX_N];
int r[MAX_N];

long long int ans[MAX_Q];

long long int culc(int l, int r) {
    long long int c = 0;
    for (int i = l; i <= r; i++) {
        c += a[i];
    }
    return c;
}

void solve() {
    for (int i = 0; i < Q; i++) {
        for (int j = 1; j <= N; j++) {
            if (j == 1)r[j] = 1;
            else r[j] = r[j - 1];

            while (r[j] <= N && s[r[j]] - s[j - 1] <= x[i]) {
                r[j]++;
            }
        }

        for (int j = 1; j <= N; j++) {
            ans[i] += r[j] - j;
        }
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)cin >> a[i];
    for (int i = 0; i < Q; i++)cin >> x[i];

    for (int i = 1; i <= N; i++)s[i] = s[i - 1] + a[i];
    
    solve();

    for (int i = 0; i < Q; i++)cout << ans[i] << endl;

}
