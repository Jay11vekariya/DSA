#include <iostream>
using namespace std;

// ============================================================
// PASS BY REFERENCE USING POINTER
// ============================================================

void changeByPointer(int *ptr)
{
    // ptr contains the address of the original variable.
    // *ptr accesses the original value stored at that address.
    *ptr = 100;
}

// ============================================================
// PASS BY REFERENCE USING ALIAS / REFERENCE VARIABLE
// ============================================================

void changeByAlias(int &ref)
{
    // ref is another name (alias) for the original variable.
    // No dereferencing (*) is required.
    ref = 200;
}

int main()
{
    // ========================================================
    // 1. BASIC POINTER
    // ========================================================

    int a = 10;

    // &a gives the memory address of a.
    // ptr stores that address.
    int *ptr = &a;

    cout << "===== BASIC POINTER =====\n";

    cout << "Value of a       : " << a << endl;
    cout << "Address of a     : " << &a << endl;
    cout << "Value of ptr     : " << ptr << endl;

    // &ptr gives the address where the pointer itself is stored.
    cout << "Address of ptr   : " << &ptr << endl;


    // ========================================================
    // 2. DEREFERENCING OPERATOR (*)
    // ========================================================

    cout << "\n===== DEREFERENCING =====\n";

    // *ptr means:
    // "Go to the address stored inside ptr and get its value."
    cout << "Value using *ptr : " << *ptr << endl;

    // Changing *ptr changes the original variable a.
    *ptr = 20;

    cout << "After *ptr = 20\n";
    cout << "a                : " << a << endl;
    cout << "*ptr             : " << *ptr << endl;


    // ========================================================
    // 3. POINTER TO POINTER
    // ========================================================

    cout << "\n===== POINTER TO POINTER =====\n";

    // ptr stores the address of a.
    // ptr2 stores the address of ptr.
    int **ptr2 = &ptr;

    cout << "a                : " << a << endl;

    // ptr contains address of a.
    cout << "ptr              : " << ptr << endl;

    // *ptr gives value of a.
    cout << "*ptr             : " << *ptr << endl;

    // ptr2 contains address of ptr.
    cout << "ptr2             : " << ptr2 << endl;

    // *ptr2 gives the value stored in ptr,
    // which is the address of a.
    cout << "*ptr2            : " << *ptr2 << endl;

    // **ptr2 finally reaches the value of a.
    cout << "**ptr2           : " << **ptr2 << endl;

    /*
        Memory relationship:

        ptr2
          |
          v
        [ptr] -------> [a]
                       20

        ptr  = address of a
        *ptr = value of a

        ptr2   = address of ptr
        *ptr2  = address of a
        **ptr2 = value of a
    */


    // ========================================================
    // 4. NULL POINTER
    // ========================================================

    cout << "\n===== NULL POINTER =====\n";

    // nullptr means the pointer currently points to no valid object.
    int *nullPtr = nullptr;

    if (nullPtr == nullptr)
    {
        cout << "nullPtr is not pointing to any object.\n";
    }

    // NEVER do this:
    //
    // cout << *nullPtr;
    //
    // Dereferencing nullptr causes undefined behavior.


    // ========================================================
    // 5. PASS BY REFERENCE USING POINTER
    // ========================================================

    cout << "\n===== PASS BY POINTER =====\n";

    int x = 50;

    cout << "Before function : " << x << endl;

    // Pass the address of x.
    changeByPointer(&x);

    cout << "After function  : " << x << endl;


    // ========================================================
    // 6. PASS BY REFERENCE USING ALIAS
    // ========================================================

    cout << "\n===== PASS BY ALIAS =====\n";

    int y = 60;

    cout << "Before function : " << y << endl;

    // y is passed directly.
    // The function parameter int &ref becomes an alias for y.
    changeByAlias(y);

    cout << "After function  : " << y << endl;


    // ========================================================
    // 7. ARRAY POINTER
    // ========================================================

    cout << "\n===== ARRAY POINTER =====\n";

    int arr[] = {10, 20, 30, 40, 50};

    // In most expressions, arr converts to a pointer
    // to its first element.
    int *arrPtr = arr;

    cout << "arr              : " << arr << endl;
    cout << "&arr[0]          : " << &arr[0] << endl;
    cout << "arrPtr           : " << arrPtr << endl;

    // All of these access the first element.
    cout << "arr[0]           : " << arr[0] << endl;
    cout << "*arr             : " << *arr << endl;
    cout << "*arrPtr          : " << *arrPtr << endl;

    // Array indexing can also be written using pointer arithmetic.
    cout << "\nAccessing array using pointer:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "arr[" << i << "] = "
             << *(arrPtr + i) << endl;
    }

    /*
        Important relationship:

        arr[i]  ==  *(arr + i)

        Example:

        arr[2]
          ==
        *(arr + 2)
          ==
        30
    */


    // ========================================================
    // 8. POINTER ARITHMETIC - INCREMENT
    // ========================================================

    cout << "\n===== POINTER INCREMENT =====\n";

    int *p = arr;

    cout << "*p before p++ : " << *p << endl;  // 10

    // Move pointer to the next array element.
    p++;

    cout << "*p after p++  : " << *p << endl;  // 20

    /*
        If int occupies 4 bytes:

        Suppose:
        &arr[0] = 1000

        p++ moves:

        1000 -> 1004

        It moves by sizeof(int), not by one byte.
    */


    // ========================================================
    // 9. POINTER ARITHMETIC - DECREMENT
    // ========================================================

    cout << "\n===== POINTER DECREMENT =====\n";

    cout << "*p before p-- : " << *p << endl;  // 20

    // Move back to previous array element.
    p--;

    cout << "*p after p--  : " << *p << endl;  // 10


    // ========================================================
    // 10. POINTER ARITHMETIC - ADDITION
    // ========================================================

    cout << "\n===== POINTER ADDITION =====\n";

    p = arr;

    cout << "*(p + 0) : " << *(p + 0) << endl; // 10
    cout << "*(p + 1) : " << *(p + 1) << endl; // 20
    cout << "*(p + 2) : " << *(p + 2) << endl; // 30
    cout << "*(p + 3) : " << *(p + 3) << endl; // 40
    cout << "*(p + 4) : " << *(p + 4) << endl; // 50

    /*
        p + i moves i ELEMENTS forward.

        If p points to arr[0]:

        p + 0 -> arr[0]
        p + 1 -> arr[1]
        p + 2 -> arr[2]
        p + 3 -> arr[3]
    */


    // ========================================================
    // 11. POINTER ARITHMETIC - SUBTRACTION
    // ========================================================

    cout << "\n===== POINTER SUBTRACTION =====\n";

    // Point to arr[4].
    p = arr + 4;

    cout << "*p       : " << *p << endl;       // 50
    cout << "*(p - 1) : " << *(p - 1) << endl; // 40
    cout << "*(p - 2) : " << *(p - 2) << endl; // 30
    cout << "*(p - 3) : " << *(p - 3) << endl; // 20
    cout << "*(p - 4) : " << *(p - 4) << endl; // 10


    // ========================================================
    // 12. SUBTRACTING TWO POINTERS
    // ========================================================

    cout << "\n===== POINTER DIFFERENCE =====\n";

    int *p1 = &arr[1];
    int *p2 = &arr[4];

    // Subtracting pointers within the same array gives
    // the number of ELEMENTS between them.
    cout << "p2 - p1 : " << p2 - p1 << endl; // 3

    /*
        p1 -> arr[1]
        p2 -> arr[4]

        Index difference:

        4 - 1 = 3

        Therefore:

        p2 - p1 = 3
    */


    // ========================================================
    // 13. POINTER RELATIONAL OPERATORS
    // ========================================================

    cout << "\n===== POINTER COMPARISON =====\n";

    p1 = &arr[1];
    p2 = &arr[3];

    // These comparisons are meaningful here because both pointers
    // point inside the same array.
    if (p1 < p2)
    {
        cout << "p1 comes before p2 in the array.\n";
    }

    if (p2 > p1)
    {
        cout << "p2 comes after p1 in the array.\n";
    }

    if (p1 != p2)
    {
        cout << "p1 and p2 point to different elements.\n";
    }

    // Two pointers pointing to the same element.
    int *p3 = &arr[1];

    if (p1 == p3)
    {
        cout << "p1 and p3 point to the same element.\n";
    }


    // ========================================================
    // SUMMARY
    // ========================================================

    /*
        POINTER SUMMARY:

        int a = 10;

        int *p = &a;

        &a      -> address of a
        p       -> stores address of a
        *p      -> value stored at that address

        -------------------------------------

        Pointer to Pointer:

        int **pp = &p;

        pp      -> address of p
        *pp     -> address of a
        **pp    -> value of a

        -------------------------------------

        Null Pointer:

        int *p = nullptr;

        -------------------------------------

        Pass by Pointer:

        void fun(int *p)

        Call:
        fun(&a);

        -------------------------------------

        Pass by Alias:

        void fun(int &x)

        Call:
        fun(a);

        -------------------------------------

        Array and Pointer:

        arr[i] == *(arr + i)

        -------------------------------------

        Pointer Arithmetic:

        p++       -> next element
        p--       -> previous element

        p + n     -> move n elements forward
        p - n     -> move n elements backward

        p2 - p1   -> distance between two pointers
                     within the same array

        -------------------------------------

        Pointer Comparisons:

        p1 == p2
        p1 != p2

        For positions within the same array:

        p1 < p2
        p1 > p2
        p1 <= p2
        p1 >= p2

        -------------------------------------

        IMPORTANT:

        Pointer arithmetic depends on the pointer's data type.

        For an int*:

            p + 1 moves by sizeof(int)

        For a double*:

            p + 1 moves by sizeof(double)

        So pointer arithmetic moves by ELEMENTS,
        not simply by individual bytes.
    */

    return 0;
}