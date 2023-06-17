#include <iostream>
#include <vector>
using namespace std;

int A, B;
bool divi[101] = { false };
bool ans = false;

void create_divisors()
{
    for (int i = 1; i <= 100; i++)
    {
        if (100 % i == 0)
        {
            divi[i] = true;
        }
    }
}

void solve()
{
    for (int i = A; i <= B; i++)
    {
        if (divi[i])
        {
            ans = true;
        }
    }
}

int main()
{
    create_divisors();
    cin >> A >> B;

    solve();

    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}