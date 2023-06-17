#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_D 100001

int D, N;
int diff[MAX_D];

void solve(int start, int end) {
    diff[start]++;
    diff[end + 1]--;
}

int main() {
    cin >> D >> N;
    for (int i = 1; i <= N; i++) {
        int start, end;
        cin >> start >> end;
        solve(start, end);
    }

    int temp = 0;
    for (int i = 1; i <= D; i++) {
        temp += diff[i];
        cout << temp << endl;
    }

    return 0;
}