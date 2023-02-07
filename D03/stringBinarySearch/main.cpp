#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int binarySearchString(string arr[], string data, int size)
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
            if(data == arr[mid])
            {
                return mid;
            }
            else if (data < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
}

int main()
{
    string arr[] = {"ali", "bobby", "dear", "test1", "catherine", "nomi"};
    int size_of_array = sizeof(arr) / sizeof(arr[0]);
    int res = binarySearchString(arr, "ali", size_of_array);
    if(res != -1) {
        cout << "Name Found at Index: " << res << endl;
    } else {
        cout << "Name was not Found" << endl;
    }
}
