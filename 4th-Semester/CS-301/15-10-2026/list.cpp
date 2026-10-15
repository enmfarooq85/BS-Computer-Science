// List Vs. Array
// https://www.geeksforgeeks.org/dsa/what-is-the-difference-between-lists-and-arrays
// List Operations(add, next, remove, find, length, get, update)
// Analysis of list using array
// Best, average and worst case

// Implementatin of list using array
#include "iostream"
using namespace std;

class List
{
private:
    int arr[10];
    int curr;

public:
    List()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = 0;
        };
        curr = 0;
    }

    // add
    string add(int val)
    {
        if (curr >= 10)
        {
            return "Unable to added!";
        }

        arr[curr] = val;
        curr++;
        return "Added successfully!";
    };

    // search
    string search(int val)
    {
        for (int i = 0; i < curr; i++)
        {
            if (arr[i] == val)
            {
                return "Found!";
            }
        }

        return "Not Found!";
    };

    // upate
    string update(int val, int idx)
    {
        if (idx < 0 || idx >= 10)
        {
            return "Unable to uodate!";
        };

        arr[idx] = val;
        return "Uodate successfully!";
    };

    // remove
    string remove(int val)
    {
        // Fixed: Only search through active elements up to curr
        for (int i = 0; i < curr; i++)
        {
            if (arr[i] == val)
            {
                for (int j = i; j < curr - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                curr--;
                arr[curr] = 0;
                return "Removed successfully!";
            }
        }

        return "Unable to remove!";
    }

    // size
    int size()
    {
        return curr;
    };
};

int main()
{
    List l1;

    l1.add(12);
    l1.add(13);
    l1.add(14);
    l1.add(15);
    cout << l1.size() << endl; // 4
    l1.remove(12);

    cout << l1.search(12) << endl;
    cout << l1.search(13) << endl;

    cout << l1.size() << endl; // 3

    return 0;
}