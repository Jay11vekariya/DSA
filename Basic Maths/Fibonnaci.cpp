#include <bits/stdc++.h>
using namespace std;

void print_N_fibonacci(int n)
{
    int a = 0;
    int b = 1;

    for (int i = 0; i < n; i++)
    {
        cout << a << " ";

        int next = a + b;
        a = b;
        b = next;
    }
}

int main()
{
    print_N_fibonacci(5);
    return 0;
}
