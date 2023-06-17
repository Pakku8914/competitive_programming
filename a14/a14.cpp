#include <algorithm>
#include <iostream>
using namespace std;
#define MAX_N 1001
#define MAX_SUM 1000001

int N, K;
int a[MAX_N];
int b[MAX_N];
int c[MAX_N];
int d[MAX_N];

int sum_ab[MAX_SUM];
int sum_cd[MAX_SUM];

bool solve() {
    sort(sum_cd + 1, sum_cd + (N * N) + 1);
    for (int i = 1; i <= N * N; i++) {
        int ps = lower_bound(sum_cd + 1, sum_cd + 1 + (N * N), K - sum_ab[i]) - sum_cd;
        if (ps <= N * N && sum_cd[ps] == K - sum_ab[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++)cin >> a[i];
    for (int i = 1; i <= N; i++)cin >> b[i];
    for (int i = 1; i <= N; i++)cin >> c[i];
    for (int i = 1; i <= N; i++)cin >> d[i];

    int temp = 1;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) {
            sum_ab[temp] = a[i] + b[j];
            temp++;
        }
    temp = 1;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) {
            sum_cd[temp] = c[i] + d[j];
            temp++;
        }

    if (solve())cout << "Yes" << endl;
    else cout << "No" << endl;
}
