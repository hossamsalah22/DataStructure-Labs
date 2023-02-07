#include <iostream>

using namespace std;

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int arr[]= {10,67,50,60,44,80,90,100};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 1; i < arr_size; i++)
    {
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

}
