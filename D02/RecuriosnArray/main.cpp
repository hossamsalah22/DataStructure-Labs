#include <iostream>

using namespace std;

int sum(int array[], int i)
{
   if ( i <= 0 )
   {
      return 0;
   }
   return sum(array, i-1) + array[i-1];
}

void print(int arr[],int size)
{
   if(size==1)
   cout << arr[0] << " ";
   else
   {
      print(arr,size-1);
      cout << arr[size-1] << " ";
   }
}

int main()
{
    int arr[]={10,20,50,60,70,80,90,100};
    //cout << sizeof(arr) << endl;
    //cout << sizeof(arr[0]) << endl
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    print(arr,arr_size);
    cout << endl << "Sum Of Elements: " << sum(arr, arr_size) << endl;
}
