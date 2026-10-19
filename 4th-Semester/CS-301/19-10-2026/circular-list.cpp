#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *nextNode;

    Node(int value)
    {
        this->val = value;
        this->nextNode = NULL;
    }
};

class CircularLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    int listSize;
    Node *curr;

    CircularLinkedList()
    {
        head = NULL;
        tail = NULL;
        listSize = 0;
        curr = NULL;
    }

    void add(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->nextNode = head;
            curr = head;
        }
        else
        {
            tail->nextNode = newNode;
            tail = newNode;
            tail->nextNode = head;
        }
        listSize++;
    }

    void next()
    {
        if (curr == NULL)
        {
            cout << "No node found!" << endl;
            return;
        }
        curr = curr->nextNode;
    }

    void removeCurrent()
    {
        if (head == NULL || curr == NULL)
            return;

        // If only 1 person is left
        if (head == head->nextNode)
        {
            delete head;
            head = NULL;
            curr = NULL;
            listSize = 0;
            return;
        }

        // Find the node right before 'curr' to unplug it
        Node *prev = head;
        while (prev->nextNode != curr)
        {
            prev = prev->nextNode;
        }

        Node *temp = curr;
        prev->nextNode = curr->nextNode;

        if (curr == head)
        {
            head = curr->nextNode;
        }

        curr = curr->nextNode;
        delete temp;
        listSize--;
    }

    int getWinnerValue()
    {
        if (head != NULL)
        {
            return head->val;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    // Joseph problem using list:
    vector<int> people = {1, 2, 3, 4, 5};
    int m = 2;

    int i = 0;
    while (people.size() > 1)
    {
        i = (i + m) % people.size();
        people.erase(people.begin() + i);
    }

    cout << "Winner: " << people[0] << endl;

    // Joseph problem using circular linked list:
    CircularLinkedList l1;
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        l1.add(i);
    }

    while (l1.listSize > 1)
    {
        for (int i = 1; i <= m; i++)
        {
            l1.next();
        }

        l1.removeCurrent();
    }

    cout << "Winner: " << l1.getWinnerValue() << endl;

    return 0;
}
