#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print_setbit(vector<int> a) {
    for (int i = 0; i < (1 << a.size()); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i & (1 << j))cout << a[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> a = { 1,2,3,4 };
    print_setbit(a);

    return 0;
}
