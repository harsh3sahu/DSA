#include <iostream>
#include <list>

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

void insertAtHead(int value, Node *&head)
{

    Node *node1 = new Node(value);
    node1->next = head;
    head = node1;
}

void insertAtTail(int value, Node *&tail)
{

    Node *node1 = new Node(value);
    Node *tail1 = tail;
    while (tail1->next != NULL)
    {
        tail1 = tail1->next;
    }

    tail1->next = node1;
    node1->next = NULL;
    tail = node1;
}

void printLinkedList(Node *head)
{
    if (head == NULL)
    {
        cout << "NULL\n";
    }

    else
        while (head != NULL)
        {
            cout << head->data << endl;
            head = head->next;
        }
}

void createLoop(Node *head, Node *tail, int value)
{

    tail->next = head->next->next;
}

void detectLoop(Node* &head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != slow && fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    

    if (slow == fast)
    {
        slow = head;

        while (fast->next!= slow->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next->next = NULL;
    }
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(15, head);
    insertAtHead(20, head);
    insertAtHead(25, head);
    insertAtHead(30, head);
    insertAtHead(35, head);
    insertAtHead(40, head);
    insertAtHead(45, head);

    printLinkedList(head);

    createLoop(head, tail, 30);

    printLinkedList(head);

    detectLoop(head);

    cout << "after loop removal\n";
    
    printLinkedList(head);

    return 0;
}