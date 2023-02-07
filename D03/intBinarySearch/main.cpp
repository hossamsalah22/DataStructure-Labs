#include <iostream>
#include <algorithm>

using namespace std;

int binarySearchInt(int arr[], int data, int size)
{
    int start = 0;
    int end = size - 1;
    sort(arr, arr + size);
    if(data < arr[start] || data > arr[end])
    {
        return -1;
    }
    else
    {
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(data == arr[mid]) {
                return mid;
            }else if (data < arr[mid]) {
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        return -1;
    }
}

int main()
{
    int arr[] = {10,15,5,100,90,85,64,7,8,9,6};
    int size_of_array = sizeof(arr) / sizeof(arr[0]);
    int res = binarySearchInt(arr, 15, size_of_array);
    //cout << res;
    if(res != -1) {
        cout << "Number Found at Index: " << res << endl;
    } else {
        cout << "Number was not Found" << endl;
    }
}
