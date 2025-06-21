#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist
{
public:
    int size;
    Node *head;

    Linkedlist()
    {
        head = NULL;
        size = 0;
    }

    void insertAtfront(int data)
    {
        Node *newnode = new Node(data);
        newnode->next = this->head;
        this->head = newnode;
        this->size++;
    }

    void insertAtend(int data)
    {
        Node *newnode = new Node(data);
        if (this->head != NULL)
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
        else
        {
            this->head = newnode;
        }
        this->size++;
    }

    void insertAtindex(int index, int element)
    {
        if (index >= 0 && index <= size)
        {
            if (index == 0)
            {
                insertAtfront(element);
                return;
            }
            Node *newnode = new Node(element);
            Node *ptr = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                ptr = ptr->next;
            }
            newnode->next = ptr->next;
            ptr->next = newnode;
            this->size++;
        }
        else
        {
            cout << "This is out of the Bound" << endl;
        }
    }

    void deleteAtfront()
    {
        if (this->head == NULL)
        {
            cout << "This list is Empty" << endl;
            return;
        }
        Node *temp = head;
        this->head = head->next;
        delete temp;
        this->size--;
    }

    void deleteAtend()
    {
        if (this->head == NULL)
        {
            cout << "This list is Empty" << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *ptr = this->head;
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            delete ptr->next;
            ptr->next = NULL;
        }
        this->size--;
    }

    void deleteAtindex(int index)
    {
        if (index >= 0 && index < size)
        {
            if (index == 0)
            {
                deleteAtfront();
                return;
            }
            Node *ptr = head;
            for (int i = 0; i < index - 1; i++)
            {
                ptr = ptr->next;
            }
            Node *temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
            this->size--;
        }
        else
        {
            cout << "This is out of the Bound" << endl;
        }
    }

    void updated(int index, int element)
    {
        if (index >= 0 && index < size)
        {
            Node *ptr = this->head;
            for (int i = 0; i < index; i++)
            {
                ptr = ptr->next;
            }
            ptr->data = element;
        }
        else
        {
            cout << "This is out of the Bound" << endl;
        }
    }

    void Displaylist()
    {
        Node *ptr = head;
        cout << "Linked list: ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()

{
    Linkedlist list;
    int n, choice, index, element;

    do

    {
        cout << endl<< "***** List of Linked list ***** " << endl;
        cout<<endl;
        cout << " Enter 1 for Insert At Front" << endl;
        cout << " Enter 2 for Insert At End" << endl;
        cout << " Enter 3 for Insert At Index" << endl;
        cout << " Enter 4  for Delete At Front" << endl;
        cout << " Enter 5  for Delete At End" << endl;
        cout << " Enter 6  for Delete At Index" << endl;
        cout << " Enter 7 for Update Value at Index" << endl;
        cout << " Enter 8 for Display List" << endl;
        cout << " Enter 0 for Exiting from list" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> element;
            list.insertAtfront(element);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> element;
            list.insertAtend(element);
            break;

        case 3:
            cout << "Enter index ";
            cin >> index;
            cout << " Enter Element ";
            cin >> element;
            list.insertAtindex(index, element);
            break;

        case 4:
            list.deleteAtfront();
            break;

        case 5:
            list.deleteAtend();
            break;

        case 6:
            cout << "Enter index to delete: ";
            cin >> index;
            list.deleteAtindex(index);
            break;

        case 7:
            cout << "Enter index for updated ";
            cin >> index;
            cout << " Enter Element for updated ";
            cin >> element;

            list.updated(index, element);
            break;

        case 8:
            list.Displaylist();
            break;

        case 0:
            cout << "Exiting program successfully!" << endl;
            break;

        default:
            cout << "Wrong choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
