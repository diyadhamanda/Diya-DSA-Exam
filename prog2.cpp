#include <iostream>
#include <vector>
using namespace std;

class MergeSort
{
public:
    void merge(vector<int> &arr, int start, int mid, int end)
    {
        vector<int> temp;
        int i = start, j = mid + 1;

        while (i <= mid && j <= end)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid)
        {
            temp.push_back(arr[i++]);
        }

        while (j <= end)

        {
            temp.push_back(arr[j++]);
        }

        for (int k = 0; k < temp.size(); k++)
        {
            arr[start + k] = temp[k];
        }
    }

    void mergeSort(vector<int> &arr, int start, int end)
    {
        if (start >= end)
        {
            return;
        }

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
};

class QuickSort
{
public:
    void quickSort(vector<int> &arr, int start, int end)
    {
        if (start >= end)
        {
            return;
        }
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }

    int partition(vector<int> &arr, int start, int end)
    {
        int pivot = arr[end];
        int i = start - 1;

        for (int j = start; j < end; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
                
            }
        }
        swap(arr[++i], arr[end]);
        return i ;
    }
};

void DisplaySort(const vector<int> &arr)
{
    cout << "Array is ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    MergeSort merge;
    QuickSort quick;

    int n, choice;

    cout << "Enter the size of the array ";
    cin >> n;

    vector<int> arr(n);

    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements ";
        cin >> arr[i];
    }

    do
    {
        cout << endl
             << "**** Sorting Menu ***** " << endl;
        cout << endl;
        cout << " Enter 1 for Merge Sort" << endl;
        cout << " Enter 2 for Quick Sort" << endl;
        cout << " Enter 3 for Display Array" << endl;
        cout << " Enter 0 for Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            merge.mergeSort(arr, 0, n - 1);
            cout << " Merge Sort " << endl;
            DisplaySort(arr);
            break;

        case 2:
            quick.quickSort(arr, 0, n - 1);
            cout << " Quick Sort " << endl;
            DisplaySort(arr);
            break;

        case 3:
            DisplaySort(arr);
            break;

        case 0:
            cout << "Exiting program successfully!" << endl;
            break;

        default:
            cout << "Wrong choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
