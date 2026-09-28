#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (int j = 1; j <= n; j++)
        {
            cout << ch << " ";
            ch++; // Here ASCII value is incremented internally.
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    // APPROACH-1
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }

    // APPROACH-2
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
}
void pattern4(int n, char ch)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A' + i; ch >= 'A'; ch--)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        for (int j = n - i; j >= 1; j--)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }

    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j >= 1; j--)
        {
            cout << ch << " ";
        }
        cout << endl;
        ch++;
    }
}
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }

    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << ch;
        }
        ch++;
        cout << endl;
    }
}
void pattern8(int n)
{

    // APPROACH-1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            cout << " ";
        }

        char ch = 'A';
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch;
            ch++;
        }

        for (char ch = 'A' + i - 1; ch >= 'A'; ch--)
        {
            cout << ch;
        }
        cout << endl;
    }

    // APPROACH-2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            cout << " ";
        }

        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }
        cout << endl;
    }
}
void pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch >= 'A'; ch--)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void pattern10(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch;
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
    pattern4(5, 'A');
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
    
    return 0;
}
