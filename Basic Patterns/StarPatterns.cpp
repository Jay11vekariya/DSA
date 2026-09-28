#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            cout << " ";
        }
        for (int j = 0; j < (2 * i + 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Print spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // Print stars
        for (int j = 0; j < (2 * (n - i) - 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern6(int n)
{
    if (n % 2 != 0)
    {
        cout << "Enter Even Number";
    }
    else
    {
        int m = n / 2;
        // Upper half of pattern
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < (m - i - 1); j++)
            {
                cout << " ";
            }

            for (int j = 0; j < (2 * i + 1); j++)
            {
                cout << "*";
            }
            cout << endl;
        }

        // lower half of pattern
        for (int i = 1; i < m; i++) // Here "i=1" not "i=0"
        {
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }

            for (int j = 0; j < (2 * (m - i) - 1); j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
}
void pattern7(int n)
{
    // Approach - 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // Approach - 2
    for (int i = 1; i <= (2 * n - 1); i++)
    {
        if (i <= n)
        {
            for (int j = 0; j < i; j++)
            {
                cout << "*";
            }
        }
        else
        {
            for (int j = 0; j < (2 * n - i); j++)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}
void pattern8(int n)
{
    // UPPER PORTION
    for (int i = 0; i < n; i++)
    {
        // UPPER LEFT TRIANGLE
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        // INSIDE SPACE
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        // UPPER RIGHT TRIANGLE
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // LOWER PORTION
    for (int i = 0; i < n; i++)
    {
        // LOWER LEFT TRIANGLE
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        // INSIDE SPACE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        // LOWER RIGHT TRIANGLE
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern9(int n)
{

    // UPPER PORTION
    for (int i = 0; i < n; i++)
    {
        // UPPER LEFT TRIANGLE
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        // INSIDE SPACE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        // UPPER RIGHT TRIANGLE
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // LOWER PORTION
    for (int i = 0; i < n; i++)
    {
        // LOWER LEFT TRIANGLE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "*";
        }
        // INSIDE SPACE
        for (int j = 0; j < i + 1; j++)
        {
            cout << "  ";
        }
        // LOWER RIGHT TRIANGLE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern10(int n)
{
    // Upper half
    for (int i = 0; i < n; i++)
    {
        // Leading spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // First star
        cout << "*";

        // Middle spaces + second star
        if (i > 0)
        {
            for (int j = 0; j < 2 * i - 1; j++)
            {
                cout << " ";
            }

            cout << "*";
        }

        cout << endl;
    }

    // Lower half
    for (int i = 1; i < n; i++)
    {
        // Leading spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // First star
        cout << "*";

        // Middle spaces + second star
        if (i < n - 1)
        {
            for (int j = 0; j < 2 * (n - i) - 3; j++)
            {
                cout << " ";
            }

            cout << "*";
        }

        cout << endl;
    }
}
void pattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void pattern12(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void pattern13(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                cout << "*";
            else
                cout << " ";
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
    pattern6(10);
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
    pattern12(5);
    cout << endl
         << "13." << endl;
    pattern13(5);
    return 0;
}
