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
    int pivot = arr[start];
    int j = end;
    for (int i = end; i > start; i--)
    {
        if (arr[i] > pivot)
            swap(arr[i], arr[j--]);
    }
    swap(arr[start], arr[j]);
    return j;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int idx = partition(arr, start, end);
        quickSort(arr, start, idx - 1);
        quickSort(arr, idx + 1, end);
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
    int arr[] = { 7, 6, 10, 5, 9, 2, 1, 15, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted arr: \n";
    printArray(arr, arr_size);
    quickSort(arr, 0, arr_size - 1);
    cout << "Sorted array: \n";
    printArray(arr, arr_size);
    return 0;
}

