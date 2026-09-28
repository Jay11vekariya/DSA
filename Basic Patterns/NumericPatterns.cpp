#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < n - i; j++)
        {
            cout << i + 1;
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << i+1;
        }
        cout << endl;
    }
}
void pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (i + 1); j++)
        {
            cout << j;
        }
        for (int j = i; j > 0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pattern10(int n)
{
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            start = 0;
        else
            start = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}
void pattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Left numbers
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }

        // Middle spaces
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " ";
        }

        // Right numbers
        for (int j = i + 1; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;
    }
}
void pattern12(int n, int num)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

int main()
{
    cout << endl
         << "1." << endl;
    pattern1(5);
    cout << endl
         << "2." << endl;
    pattern2(5);
    cout << endl
         << "3." << endl;
    pattern3(5);
    cout << endl
         << "4." << endl;
    pattern4(5);
    cout << endl
         << "5." << endl;
    pattern5(5);
    cout << endl
         << "6." << endl;
    pattern6(5);
    cout << endl
         << "7." << endl;
    pattern7(5);
    cout << endl
         << "8." << endl;
    pattern8(5);
    cout << endl
         << "9." << endl;
    pattern9(5);
    cout << endl
         << "10." << endl;
    pattern10(5);
    cout << endl
         << "11." << endl;
    pattern11(5);
    cout << endl
         << "12." << endl;
    pattern12(5, 1);
    return 0;
}
