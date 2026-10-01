#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Intialization

    vector<int> vec1 = {10, 20, 30, 40, 50};
    vector<int> vec2(5, 0);

    // Accessing Elements
    cout << vec1[1] << endl;    // 20
    cout << vec1.at(1) << endl; // 20
    // both access the element at index 1, but at() performs bounds checking.

    // Traversing

    for (int i = 0; i < vec1.size(); i++) // For Loop
    {
        cout << vec1[i] << " ";
    }

    cout << endl;

    for (int val : vec2) // For-each loop
    {
        cout << val << " ";
    }

    // Methods

    // 1] push_back() : Every push_back() adds an element at the end.
    vec2.push_back(10);
    vec2.push_back(20);
    vec2.push_back(30);
    // vec2 = [0,0,0,0,0,10,20,30]

    // 2] pop_back():  removes the last element.
    vec2.pop_back(); // 30 -> removed

    // 3] front()	Returns first element
    cout << vec1.front() << endl;

    // 4] back()	Returns last element
    cout << vec1.back() << endl;

    // 5] size():	Returns number of elements
    // 6] empty()	Checks whether vector is empty
    // 7] clear()	Removes all elements
    // 8] at()	Access element with bounds checking
    // 9] begin()	Iterator to first element
    // 10] end()	Iterator past the last element
    // 11] capacity()	Returns allocated storage capacity

    return 0;
}
