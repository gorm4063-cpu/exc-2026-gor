#include <iostream>
using namespace std;

class list
{
public:
    list();
    ~list();
    int size = 0;
    int getsize()
    {
        return size;
    }
    void push_back(int data);
    int &operator[](const int index);

private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data, Node *next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
    Node *head = nullptr;
};

list::list()
{
    size = 0;
    head = nullptr;
}
list::~list()
{
    while (head != nullptr)
    {
        Node *current = head;
        head = head->next;
        delete current;
    }
}
void list::push_back(int data)
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node *current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node(data);
    }
    size++;
}
int &list::operator[](const int index)
{
    int counter = 0;
    Node *current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        else
        {
            current = current->next;
            counter++;
        }
    }
}
void middleElement(list &linklist)
{
    int middle = linklist.getsize() / 2;
    cout << "the middle elemnt of first linklist is- " << linklist[middle] << " which index is- " << middle << endl;
}
list merging(list &linklist, list &linklist2)
{
    list newlist;
    for (int i = 0; i < linklist.getsize(); i++)
    {
        newlist.push_back(linklist[i]);
    }
    for (int i = 0; i < linklist2.getsize(); i++)
    {
        newlist.push_back(linklist2[i]);
    }
    return newlist;
}
void printlist(list &linklist)
{
    for (int i = 0; i < linklist.getsize(); i++)
    {
        cout << linklist[i] << endl;
    }
}

int main()
{
    list linklist;
    linklist.push_back(10);
    linklist.push_back(12);
    linklist.push_back(13);
    linklist.push_back(14);
    list linklist2;
    linklist2.push_back(-4);
    linklist2.push_back(-3);
    cout << " first element is " << linklist[0] << endl;
    cout << "first list" << endl;
    printlist(linklist);
    cout << "second list" << endl;
    printlist(linklist2);
    cout << "--------------------------------" << endl;
    middleElement(linklist);
    cout << "--------------------------------" << endl;
    cout << "after merging two lists" << endl;
    list mergelist = merging(linklist, linklist2);
    printlist(mergelist);

    return 0;
}
