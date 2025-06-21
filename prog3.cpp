#include <iostream>
#include <vector>
using namespace std;

int Binary(vector<int> &arr, int key)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr;
    int n, element, result, key;

    cout << "Enter the size of vector ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element ";
        cin >> element;
        arr.push_back(element);
    }

    cout << " Array is ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the element for search ";
    cin >> key;

    result = Binary(arr, key);

    if (result != -1)
    {
        cout << "Element in index is " << result << endl;
    }
    else
    {
        cout << "Element not found " << endl;
    }
    return 0;
}
