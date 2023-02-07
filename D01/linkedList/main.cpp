#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    int id;
    string name;
    node* next;
    node* prev;
};

class linkedList
{
    node* head;
    node* tail;

    node* searchById(int _id)
    {
        node* tmp = head;
        while(tmp != NULL)
        {
            if(tmp->id == _id)
            {
                return tmp;
            }
            else
            {
                tmp = tmp->next;
            }
        }
        return NULL;
    }

    node* searchByName(string _name)
    {
        node* tmp = head;
        while(tmp != NULL)
        {
            if(tmp->name == _name)
            {
                return tmp;
            }
            else
            {
                tmp = tmp->next;
            }
        }
        return NULL;
    }

public:
    linkedList()
    {
        head = tail = NULL;
    }

    void append(int _id, string _name)
    {
        node* tmp = new node;
        tmp->id = _id;
        tmp->name = _name;
        tmp->next = NULL;
        tmp->prev = NULL;
        if(head == NULL)
        {
            head = tail = tmp;
        }
        else
        {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
        }
    }

    void display()
    {
        node* tmp= head;
        while (tmp != NULL)
        {
            cout << "id: " << tmp->id << " " << "Name: " << tmp->name << endl;
            tmp = tmp->next;
        }
    }

    int nodeCount()
    {
        int num = 0;
        node* tmp = head;
        while(tmp != NULL)
        {
            num++;
            tmp = tmp->next;
        }
        return num;
    }

    node searchById1(int _id)
    {
        node* tmp = searchById(_id);
        if(tmp != NULL)
        {
            node res = *tmp;
            res.next = NULL;
            res.prev = NULL;
            return res;
        }
        node res;
        res.id = -1;
        res.name = "";
        return res;
    }

    node searchByName1(string _name)
    {
        node* tmp = searchByName(_name);
        if(tmp != NULL)
        {
            node res = *tmp;
            res.next = NULL;
            res.prev = NULL;
            return res;
        }
        node res;
        res.id = -1;
        res.name = "";
        return res;
    }

    void deleteById(int _id)
    {
        node* tmp = searchById(_id);
        if (tmp != NULL)
        {
            if(tmp->prev == NULL)
            {
                tmp->next->prev == NULL;
                head = tmp->next;
            }
            else if (tmp->next == NULL)
            {
                tmp->prev->next = NULL;
                tail = tmp->prev;
            }
            else if (tmp->next == NULL && tmp->prev == NULL)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
            }
        delete tmp;
        } else {
            cout << "ID Not Found" << endl;
        }
    }

    void insertAfterId(int id, string name, int _id) {
        node* res = searchById(_id);
        if(res != NULL) {
            if(res->next != NULL) {
                node* tmp = new node;
                tmp->id = id;
                tmp->name = name;
                tmp->next = res->next;
                tmp->prev = res;
                res->next = tmp;
                tmp->next->prev = tmp;
            } else {
                append(id, name);
            }
        } else {
            append(id, name);
        }
    }
};

int main()
{
    linkedList l1;
    l1.append(10, "HOssam");
    l1.append(20, "Hossam");
    l1.append(30, "Hossam");
    l1.display();
    cout << l1.nodeCount() << endl;
    node tmp = l1.searchById1(25);
    if(tmp.id > -1)
    {
        cout << "Data Found" << endl;
        cout << "ID: " << tmp.id << " Name:" << tmp.name << endl;
    }
    else
    {
        cout << "Id Not Found" << endl;
    }
    node tmp1 = l1.searchByName1("HOssam");
    if(tmp1.id > -1)
    {
        cout << "Data Found" << endl;
        cout << "ID: " << tmp1.id << " Name:" << tmp1.name << endl;
    }
    else
    {
        cout << "Name Not Found" << endl;
    }
    l1.deleteById(20);
    cout << "After Delete" << endl;
    l1.display();
     l1.deleteById(45);
    cout << "After Delete" << endl;
    cout << "Before Insert" << endl;
    l1.display();
    l1.insertAfterId(25, "Hossam", 10);
    cout << "After insert" << endl;
    l1.display();
}
