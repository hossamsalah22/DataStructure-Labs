#include <iostream>
#include <algorithm>

using namespace std;

int binarySearchRecursive(int arr[], int start,int end, int data)
{
    sort(arr, arr + (end + 1));
    if(data < arr[start] || data > arr[end] || start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if(data == arr[mid])
    {
        return mid;
    }
    else if (data < arr[mid])
    {
        binarySearchRecursive(arr, start, mid - 1, data);
    }
    else
    {
        binarySearchRecursive(arr, mid + 1, end, data);
    }
}

int main()
{
    int arr[] = {10,15,5,100,90,85,64,7,8,9,6};
    int size_of_array = sizeof(arr) / sizeof(arr[0]);
    int res = binarySearchRecursive(arr, 0, size_of_array - 1, 15);
    //cout << res;
    if(res != -1)
    {
        cout << "Number Found at Index: " << res << endl;
    }
    else
    {
        cout << "Number was not Found" << endl;
    }
}
