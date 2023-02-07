#include <iostream>
using namespace std;
class Stack
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* top;
    Node* current;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int _data)
    {
        Node* newNode = new Node;
        if(newNode == NULL) {
            cout << "Memory OverFlow" << endl;
        }else {
        newNode->data = _data;
        newNode->next = top;
        top = newNode;
        }
    }
    bool isEmpty(){
        return top == NULL;
    }
    int pop(int& _data)
    {
        if(isEmpty())
            _data = NULL;
        else
        {
            _data = top->data;
            Node* tmp = top;
            top = top->next;
            tmp = tmp->next = NULL;
            delete tmp;
        }
        return _data;
    }
    void display()
    {
        current = top;
        cout << "[ ";
        while(current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << " ]" << endl;
    }
};
int main()
{
    Stack s1;
    int ch, val;
    int res = 0;
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
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
            s1.push(val);
            break;
        }
        case 2:
        {
            res = s1.pop(res);
            if(res == NULL)
                cout << "Stack is Empty" << endl;
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
