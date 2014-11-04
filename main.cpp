#include <iostream>

using namespace std;


/*

	Verkefni 2.

	H�rna eigi� �i� a� b�a til tv�tengdan lista.

	Tv�tengdur listi

	B�a til struct sem geymir int t�lu, forward link og back link
	struct Node


	B�a svo til fall tekur vi� int t�lu og b�r til n�ja n��u og skilar henni.
	Node* CreateMe(int dasNumber);

	B�a svo til fall sem tekur vi� tveim n��um, �nnur er n��an sem vi� �tlum a� setja inn � listan
	og seinni n��an er �ar sem n�ja n��an � a� koma eftir �.
	void InsertNodeAfterMe(Node* &InsertNode, Node* &AfterMe);


	B�a svo til fall sem tekur vi� tveim n��um, �nnur er header af listanum og seinni er n��an sem
	� a� fjarl�gja �r listanum.
	void EraseMe(Node* &head ,Node* &Erase);

	B�a svo til tvo prent f�ll. Anna� sem prentar � r�ttri r�� og hitt sem prentar � Reverse Order
	void prenta(Node* Front);
	void prentaReverse(Node* Front);


*/





struct Node
{
    int data;
    Node* Forward_Link;
    Node* Back_Link;
};

void InsertNodeAfterMe(Node* &InsertNode, Node* &AfterMe);
void EraseMe(Node* &head ,Node* &Erase);
Node* CreateMe(int dasNumber);
void prenta(Node* Front);
void prentaReverse(Node* Front);

int main()
{
    Node* head;
    Node* nodePtr1;
    Node* nodePtr2;
    Node* nodePtr3;

    head = NULL;

    nodePtr1 = CreateMe(1);
    InsertNodeAfterMe(nodePtr1,head);
    nodePtr2 = CreateMe(2);
    InsertNodeAfterMe(nodePtr2,head);
    nodePtr3 = CreateMe(3);
    InsertNodeAfterMe(nodePtr3,head);
    prenta(head);
    prentaReverse(head);

    EraseMe(head,nodePtr2);
    prenta(head);

    Node* NodePtr4;

    NodePtr4 = CreateMe(5);

    //InsertNodeAfterMe(NodePtr4,nodePtr3);
    InsertNodeAfterMe(NodePtr4,nodePtr1);

    prenta(head);

    EraseMe(head,NodePtr4),
    prenta(head);

    EraseMe(head,nodePtr1);
    prenta(head);

    EraseMe(head,nodePtr3);
    prenta(head);





}

void prenta(Node* Front)
{

    if(Front == NULL) // If the list is empty
    {
        cout << "Empty list" << endl;
        return;
    }

    Node* tmp = Front;

    while(tmp != NULL)
    {
        cout << tmp ->data << " ";
        tmp = tmp->Forward_Link; // tmp is moving through the list
    }
    cout << endl;
}

void prentaReverse(Node* Front)
{
    if(Front == NULL)// if the list is empty
    {
        cout << "Empty list" << endl;
        return;
    }
    Node* tmp = Front;
    while(tmp->Forward_Link != NULL) // Go to the last node with tmp
    {
        tmp = tmp->Forward_Link; //moving through the list
    }

    while(tmp != NULL) // while tmp have not reach the end
    {
        cout << tmp->data << " "; // print out data
        tmp = tmp->Back_Link; // Going backwards through the list
    }
    cout << endl;

}

Node* CreateMe(int dasNumber)
{
    Node* Head = new Node; // Create new node from the heap
    Head->Forward_Link = NULL; //
    Head->Back_Link = NULL; // make forward and back link equall to NULL
    Head->data = dasNumber; // Enter data into the node
    return Head;
}


void InsertNodeAfterMe(Node* &InsertNode, Node* &AfterMe)
{

    if(AfterMe == NULL) // If the list is empty
    {
        AfterMe = InsertNode;
    }
    else
    {
        if(AfterMe->Forward_Link == NULL) // if afterme is the last node in the list
        {
            AfterMe->Forward_Link = InsertNode;
            InsertNode->Back_Link = AfterMe;
            InsertNode->Forward_Link = NULL;
        }
        else // if Afterme is in between two nodes
        {
            InsertNode->Forward_Link = AfterMe->Forward_Link;
            (InsertNode->Forward_Link)->Back_Link = InsertNode;
            AfterMe->Forward_Link = InsertNode;
            InsertNode->Back_Link = AfterMe;
        }
    }
}
void EraseMe(Node* &head,Node* &Erase)
{
    if(Erase->Back_Link == NULL) // if EraseMe is the first node in the list
    {
        head = Erase->Forward_Link;
        if(head != NULL)
        {
            head->Back_Link = NULL;
        }
    }
    else // if EraseMe is between two nodes or the last node
    {
        (Erase->Back_Link)->Forward_Link = Erase->Forward_Link;
        if(Erase->Forward_Link != NULL)
        {
            (Erase->Forward_Link)->Back_Link = Erase->Back_Link;
        }
    }
    delete Erase; // delete the node without breaking the list
}
