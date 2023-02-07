#include <iostream>

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
        }
        else
        {
            cout << "ID Not Found" << endl;
        }
    }

    void insertAfterId(int id, string name, int _id)
    {
        node* res = searchById(_id);
        if(res != NULL)
        {
            if(res->next != NULL)
            {
                node* tmp = new node;
                tmp->id = id;
                tmp->name = name;
                tmp->next = res->next;
                tmp->prev = res;
                res->next = tmp;
                tmp->next->prev = tmp;
            }
            else
            {
                append(id, name);
            }
        }
        else
        {
            append(id, name);
        }
    }
};

class hybridList
{
    linkedList* alphaList[26];
public:
    hybridList()
    {
        for (int i = 0; i < 26; i++)
        {
            alphaList[i] = NULL;
        }
    }
    int getCharIndex(string name)
        {
            int index = tolower(name[0])-97;
            if (index >=26 || index < 0)
                return-1;
            return index;
        }
        void append(int id,string name)
        {
            int index = getCharIndex(name);
            if (index == -1)
                return;
            if (!alphaList[index])
                alphaList[index] = new linkedList;
            alphaList[index]->append(id,name);
        }
        void display()
        {
            for(int i=0; i<26; i++)
            {
                if(alphaList[i])
                {
                    cout<<"linked list for array start with ["<<(char)(i+97)<<"]"<<endl;
                    alphaList[i]->display();
                }
            }
        }
        node searchByName1(string name)
        {
            int index = getCharIndex(name);
            if (index == -1)
            {
                node temp;
                temp.id = -1;
                return temp;
            }
            else
            {
                return alphaList[index]->searchByName1(name);
            }
        }
};

int main()
{
    hybridList h1;
    h1.append(1,"Hossam");
    h1.append(2,"Ali");
        h1.append(2,"ahmed");
                h1.append(2,"zeyad");
        h1.append(2,"fayed");


    h1.display();

}
