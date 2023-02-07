#include <iostream>

using namespace std;

class ShiftQueue
{
    int *data;
    int size;
    int back;
    int elementCount;
public:
    ShiftQueue(int _size)
    {
        if(_size < 0)
        {
            _size = 5;
        }
        size = _size;
        data = new int[size];
        back = -1;
        elementCount = 0;
    }

    bool isEmpty()
    {
        return elementCount == 0;
    }

    bool isFull()
    {
        return elementCount == size;
    }

    void enQuoue(int _data)
    {
        if (isFull())
        {
            cout << "Shift Queue is full" << endl;
        }
        else
        {
            back++;
            data[back] = _data;
        }
        elementCount++;
    }

    int deQuoue(int& num)
    {
        if (isEmpty())
        {
            num = NULL;
        }
        else
        {
            num = data[0];
            for (int i = 0; i < size - 1; i++)
            {
                data[i]=data[i+1];
            }
            back--;
        }
        elementCount--;
        return num;
    }

    void display()
    {
        if (isEmpty())
        {
            cout<<"ShiftQueue is empty"<<endl;
        }
        for (int i = 0; i < back + 1; i++)
        {
            cout<< data[i] <<endl;
        }
    }
};

int main()
{
    ShiftQueue s1(10);
    int ch, val;
    int res = 0;
    cout<<"1) Push in ShiftQueue"<<endl;
    cout<<"2) Pop from ShiftQueue"<<endl;
    cout<<"3) Display ShiftQueue"<<endl;
    cout<<"4) Exit"<<endl;
    do
    {
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            s1.enQuoue(val);
            break;
        }
        case 2:
        {
            res = s1.deQuoue(res);
            if(res == NULL)
                cout << "ShiftQueue is Empty" << endl;
            else
                cout << "Popped Item = " << res << endl;
            break;
        }
        case 3:
        {
            s1.display();
            break;
        }
        case 4:
        {
            cout<<"Exit"<<endl;
            break;
        }
        default:
        {
            cout<<"Invalid Choice"<<endl;
        }
        }
    }
    while(ch!=4);
    return 0;
}
