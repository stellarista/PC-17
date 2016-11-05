#include <iostream>

using namespace std;

struct Node {
	double value;
	Node *next;
};

Node *head;

class LinkedList
{
public:
  //  LinkedList();
	~LinkedList()
	{
        Node *nodePtr;
        Node *nextNode;

        nodePtr = head;

        while (nodePtr != 0)
        {
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }

	}

    int appendNode(double num)
	{
        Node *newNode, *nodePtr;
        newNode = new Node;
        newNode->value=num;
        newNode->next=0;

        if(!head)
            head = newNode;
        else {
            nodePtr = head;
        } while(nodePtr->next)

        nodePtr->next = newNode;
	}

	int insertNode(double num)
	{
	    Node *newNode;
	    Node *nodePtr;
	    Node *prevNode = 0;

        newNode = new Node;
        newNode->value=num;

	    if (!head)
        {
            head = newNode;
            newNode->next = 0;
        } else
        {
            nodePtr = head;
            prevNode = 0;
            while (nodePtr != 0 && nodePtr->value < num)
            {  prevNode = nodePtr;
            nodePtr = nodePtr->next;
            }
            if (prevNode == 0)
            {   head = newNode;
                newNode->next = nodePtr;
            } else
            {   prevNode->next = newNode;
                newNode->next = nodePtr;
            }
        }
	}

	void deleteNode(double num)
	{
        Node *nodePtr;
	    Node *prevNode;

	    if(!head)
            return;

        if(head->value == num)
        {
            nodePtr = head->next;
            delete head;
            head = nodePtr;
        } else
        {
            nodePtr = head;

            while(nodePtr!=0 && nodePtr->value!= num)
            {
               prevNode = nodePtr;
               nodePtr = nodePtr->next;
            }

            if (nodePtr)
            {
                prevNode->next = nodePtr->next;
                delete nodePtr;
            }
        }

	}


	void displayList() const
    {
        Node *nodePtr;
        nodePtr = head;

        while (nodePtr)
        {
            cout << nodePtr->value << endl;
            nodePtr = nodePtr->next;
        }
    }
};

int main()
{
    LinkedList num;
    num.appendNode(3);
    num.appendNode(5);
    num.appendNode(7);

    num.insertNode(9);

    num.displayList();
    cout<<"-----------------"<<endl;
    num.deleteNode(3);

    num.displayList();


    return 0;
}
