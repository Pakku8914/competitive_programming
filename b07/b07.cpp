#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_T 500001

int T, N;
int ans[MAX_T];

void solve(int l, int r) {
    ans[l]++;
    ans[r]--;
}

int main() {
    cin >> T >> N;
    for (int i = 0; i < N; i++) {
        int L, R;
        cin >> L >> R;
        solve(L, R);
    }
    int temp = 0;
    for (int i = 0; i < T; i++) {
        temp += ans[i];
        cout << temp << endl;
    }

    return 0;
}