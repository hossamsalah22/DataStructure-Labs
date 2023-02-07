#include <iostream>

using namespace std;

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}


int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = (start - 1);
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int i = partition(arr, start, end);
        quickSort(arr, start, i - 1);
        quickSort(arr, i + 1, end);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {8, 7, 6, 1, 0, 9, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted arr: \n";
    printArray(arr, arr_size);
    quickSort(arr, 0, arr_size - 1);
    cout << "Sorted arr in ascending order: \n";
    printArray(arr, arr_size);
}
