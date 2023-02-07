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

class LinkedList
{
    node* head;
    node* tail;


    node* searchById(int _id)
    {
        if(head)
        {
            node* tmp= new node;
            tmp=head;
            //  cout<<"ID" <<'\t'<< "Name"<<endl;

            while(tmp != NULL)
            {
                if (tmp->id == _id)
                {
                    return tmp;
                }
                tmp=tmp->next;
            }
            cout<<"user not found"<<endl;
            return NULL;

        }

        else
        {
            cout<<"there is no elements"<<endl;
            return NULL;
        }
    }

    node* searchByName(string _name)
    {

        node* tmp;//= new node;
        tmp=head;
        //  cout<<"ID" <<'\t'<< "Name"<<endl;

        while(tmp != NULL)
        {
            if ( tmp->name == _name)
            {
                return tmp;
            }
            tmp=tmp->next;
        }
        cout<<"user not found"<<endl;
        return NULL;




        //cout<<"there is no elements"<<endl;

    }


public:
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    LinkedList(node* _head,node* _tail)
    {
        head=_head;
        tail=_tail;
    }



    void append(int _id,string _name)
    {
        node* tmp= new node;
        tmp->id = _id;
        tmp->name=_name;
        tmp->next=NULL;
        tmp->prev=NULL;

        if(head)
        {
            tmp->prev = tail;
            tail->next=tmp;
            tail=tmp;
            cout<<"append Done"<<endl;
        }
        else
        {
            head=tail=tmp;
            cout<<"append Done"<<endl;
        }

    }

    void display()
    {
        if(head)
        {
            node* tmp= new node;
            tmp=head;
            cout<<"ID" <<'\t'<< "Name"<<endl;
            while(tmp != NULL)
            {
                cout<<tmp->id <<'\t'<< tmp->name<<endl;
                tmp=tmp->next;
            }
        }
    }

    int count ()
    {
        int n=0;
        if(head)
        {
            node* tmp= new node;
            tmp=head;
            //  cout<<"ID" <<'\t'<< "Name"<<endl;

            while(tmp != NULL)
            {
                n++;
                // cout<<tmp->id <<'\t'<< tmp->name<<endl;
                tmp=tmp->next;
            }
        }
        return n;
    }



    node searchById2(int id)
    {
        node* tmp = searchById(id);
        if(tmp != NULL)
        {
            node t = *tmp;
            t.next=t.prev= NULL;
            return t;
        }
        else
        {
            node t;
            t.id=-1;
            return t;
        }
    }
    node searchByName2(string name)
    {
        node* tmp = searchByName(name);
        if(tmp != NULL)
        {
            node t = *tmp;
            t.next=t.prev= NULL;
            return t;
        }
        else
        {
            node t;
            t.id=-1;
            return t;
        }
    }
    void insertion(int OldId, int id, string name)
    {
        node* tmp = searchById(OldId);
        if(tmp != NULL)
        {
            node* newNode = new node;
            newNode->id=id;
            newNode->name=name;

            newNode->prev= tmp;
            tmp->next->prev=newNode;
            newNode->next=tmp->next;
            tmp->next=newNode;
        }
    }

    void deletById(int id)
    {
        node* tmp = searchById(id);
        if(tmp != NULL)
        {
            if(tmp->prev == NULL && tmp->next != NULL )
            {
                head=tmp->next;
                tmp->next->prev= NULL;
                delete tmp;
                return;

            }
            else if(tmp->next == NULL && tmp->prev != NULL)
            {
                tmp->prev->next == NULL;
                tail = tmp->prev;
                delete tmp;
                return;
            }
            else if(tmp->next == NULL && tmp->prev == NULL)
            {
                head=tail=NULL;
                return;
            }
            else if(tmp->next != NULL && tmp->prev != NULL)
            {
                tmp->prev->next= tmp->next;
                tmp->next->prev= tmp->prev;
                delete tmp;
                return;
            }
        }
    }

    void deletByName(string name)
    {
        node* tmp = searchByName(name);
        if(tmp != NULL)
        {
            if(tmp->prev == NULL && tmp->next != NULL )
            {
                head=tmp->next;
                tmp->next->prev= NULL;

            }
            else if(tmp->next == NULL && tmp->prev != NULL)
            {
                tmp->prev->next == NULL;
                tail = tmp->prev;
            }
            else if(tmp->next == NULL && tmp->prev == NULL)
            {
                head=tail=NULL;
            }
            else if(tmp->next != NULL && tmp->prev != NULL)
            {
                tmp->prev->next= tmp->next;
                tmp->next->prev= tmp->prev;
            }

        }

    }
};

class Hybird
{
    LinkedList* arr[26];
public:
    Hybird()
    {
        for(int i=0; i<26; i++)
        {
            arr[i]==NULL;
        }
    }
    int getindex(string name)
    {
        int index= toupper(name[0])-65;
        if(index<0 || index>=26)
        {
            return -1;
        }
        else
        {
            return index;
        }
    }

    void append(int id, string name)
    {
      int index = getindex(name);
        if (index == -1)
            return;
        if (!arr[index])
            arr[index] = new LinkedList;
        arr[index]->append(id,name);
    }

    void display()
    {
        for(int i=0; i<26 ; i++)
        {
            if(arr[i]!= NULL)
            {
                cout<<"linked list of"<<char(i+65)<<endl;
                arr[i]->display();
            }
        }
    }

};


int main()
{

    Hybird h1;
    h1.append(1,"Manar");
    h1.append(2,"Asmaa");
    h1.append(3,"Habiba");
//h1.display();
// LinkedList l1;
//arr[0]->display();

    cout << "Hello world!" << endl;
    return 0;
}
