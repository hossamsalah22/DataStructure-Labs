#include <iostream>

using namespace std;

class LinkedQueue
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* front;
    Node* back;
    int elementCount;
public:
    LinkedQueue()
    {
        front = back = NULL;
        elementCount = 0;
    }

    bool isEmpty()
    {
        return elementCount == 0;
    }

    void enQueue(int _data)
    {
        Node* tmp = new Node;
        tmp->data = _data;
        tmp->next = NULL;
        if(isEmpty())
        {
            back = front = tmp;
        }
        else
        {
            back->next = tmp;
            back = tmp;
        }
        elementCount++;
    }

    int deQuoue(int& num)
    {
        if(isEmpty())
        {
            num = NULL;
        }
        else
        {
            Node* tmp = front;
            if (elementCount == 1)
            {
                front = back = NULL;
            }
            else
            {
                front = front->next;
            }
            tmp->next = NULL;
            num = tmp->data;
            delete tmp;
        }
        elementCount--;
        return num;
    }

    void display()
    {
        Node* current = front;
        if(isEmpty())
        {
            cout << "Queue Is Empty" << endl;
        }
        else
        {
            cout << "{ ";
            while(current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << "}" << endl;
        }
    }
};

int main()
{
    LinkedQueue q1;
    int ch, val;
    int res = 0;
    cout<<"1) Enqueue"<<endl;
    cout<<"2) Dequeue"<<endl;
    cout<<"3) Display Queue"<<endl;
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
            q1.enQueue(val);
            break;
        }
        case 2:
        {
            res = q1.deQuoue(res);
            if(res == NULL)
                cout << "Queue is Empty" << endl;
            else
                cout << "Popped Item = " << res << endl;
            break;
        }
        case 3:
        {
            cout << "Items in Queue = ";
            q1.display();
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
