#include <iostream>
using namespace std;

class CircualQueue
{
    int back, front, elementCount;
    int* data;
    int arrSize;
public:
    CircualQueue(int size)
    {
        if(size <= 0)
        {
            size = 10;
        }
        data = new int[size];
        arrSize = size;
        elementCount = front = 0;
        back = size - 1;
    }
    bool isEmpty()
    {
        return elementCount == 0;
    }

    bool isFull()
    {
        return elementCount == arrSize;
    }

    void enQueue(int _data)
    {
        if(isFull())
        {
            cout << "Queue Is Full" << endl;
        }
        else
        {
            back = (back + 1) % arrSize;
            data[back] = _data;
            elementCount++;
        }
    }

    int deQueue(int& _data)
    {
        if(isEmpty())
        {
            _data = NULL;
        }
        else
        {
            _data = data[front];
            front = (front + 1) % arrSize;
            elementCount--;
        }
        return _data;
    }

    void display()
    {
        if(isEmpty())
        {
            cout << "Queue Is Empty" << endl;
        }
        else
        {
            int i = front - 1;
            cout << "{ ";
            while(i != back)
            {
                i = (i + 1) % arrSize;
                cout << data[i] << " ";
            }
            cout << "}" << endl;
        }
    }

    int searchQueue(int num) {
        int pos = -1;
        if(isEmpty()) {
            pos = -2;
        }else {
            for (int i = front; i != back + 1; i=(i+1)%arrSize) {
                if(data[i] == num) {
                    pos = i;
                    break;
                } else {
                    pos = -1;
                }
            }
        }
        return pos;
    }

};

int main()
{
    CircualQueue c1(4);
    int ch, val;
    int res = 0;
    cout<<"1) Enqueue"<<endl;
    cout<<"2) Dequeue"<<endl;
    cout<<"3) Display Queue"<<endl;
    cout<<"4) Search For Number"<<endl;
    cout<<"5) Exit"<<endl;
    do
    {
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            cout<<"Enter value to be EnQueued: "<<endl;
            cin>>val;
            c1.enQueue(val);
            break;
        }
        case 2:
        {
            res = c1.deQueue(res);
            if(res == NULL)
                cout << "Queue is Empty" << endl;
            else
                cout << "Popped Item = " << res << endl;
            break;
        }
        case 3:
        {
            c1.display();
            break;
        }
        case 4:
        {
            cout<<"Enter value to Search: "<<endl;
            cin>>val;
            res = c1.searchQueue(val);
            if(res == -2)
                cout << "Queue is Empty" << endl;
            else if (res == -1)
                cout << "Number Not Found" << endl;
            else
                cout << "Item Found at Index = " << res << endl;
            break;
        }
        case 5:
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
    while(ch!=5);
    return 0;
}
