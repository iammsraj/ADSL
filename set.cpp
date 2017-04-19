#include <iostream>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    set<int> st;
    set<int>::iterator it;
    int choice, item, ch;
    while (1) {
        cout << "\n---------------------" << endl;
        cout << "Set Implementation in Stl" << endl;
        cout << "\n---------------------" << endl;
        cout << "1.Insert Element into the Set" << endl;
        cout << "2.Delete Element of the Set" << endl;
        cout << "3.Size of the Set" << endl;
        cout << "4.Find Element in a Set" << endl;
        cout << "5.Display by Iterator" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            do {
                cout << "Enter value to be inserted: ";
                cin >> item;
                st.insert(item);
                cout <<"\n Do you want to add more";
                cin >> ch;
            } while (ch == 1);
            break;
        case 2:
            cout << "Enter the element to be deleted: ";
            cin >> item;
            st.erase(item);
            break;
        case 3:
            cout << "Size of the Set: ";
            cout << st.size() << endl;
            break;
        case 4:
            cout << "Enter the element to be found: ";
            cin >> item;
            it = st.find(item);
            if (it != st.end())
                cout << "Element " << *it << " found in the set" << endl;
            else
                cout << "No Element Found" << endl;
            break;
        case 5:
            cout << "Displaying Map by Iterator: ";
            for (it = st.begin(); it != st.end(); it++) {
                cout << (*it) << " ";
            }
            cout << endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int first[] = { 5, 10, 15, 20, 25 };
    int second[] = { 50, 40, 30, 20, 10 };
    vector<int> v(10);
    vector<int>::iterator it;
    sort(first, first + 5);
    sort(second, second + 5);
    it = set_intersection(first, first + 5, second, second + 5, v.begin());
    v.resize(it - v.begin());
    cout << "The intersection has " << (v.size()) << " elements: " << endl;
    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << "  ";
    cout << endl;
    it = set_union(first, first + 5, second, second + 5, v.begin());
    v.resize(it - v.begin());
    cout << "The union has " << (v.size()) << " elements: " << endl;
    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << "  ";
    cout << endl;
    it = set_difference(first, first + 5, second, second + 5, v.begin());
    v.resize(it - v.begin());
    cout << "The difference has " << (v.size()) << " elements: " << endl;
    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << "  ";
    cout << endl;
    return 0;
}


