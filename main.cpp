// Richard Ruth
// COP2535.CM1
// Project 3
// Program reads in characters from a text file LinkedText.txt contained in the working project directory
// into a linked list. Program then displays contents of linked list, then creates new linked list with elements in
// reverse order. The program then displays the contents of the reversed linked list.

#include <iostream>
#include <fstream>
using namespace std;

class ListNode
{
public:
    ListNode(char letter, ListNode *p)
    {
        letterData = letter; next = p;
    }
private:
    char letterData;
    ListNode *next;
    friend class LinkedList;            // LinkedList class has friend status
};

class LinkedList
{
public:
    void add(char letter);
    LinkedList() {head = NULL;}         // Constructor
    ~LinkedList();
    void print();
    void reverse();
private:
    ListNode * head;                    // List head pointer
    ListNode * tail;                    // List tail pointer
};

/****************************************************************************
 *                                                                          *
 *                           LinkedList::add                                *
 * Adds a given character to the end of the linked list.                    *
 *                                                                          *
 ***************************************************************************/

void LinkedList::add(char letter)
{
    if (head == NULL)
    {
        head = new ListNode(letter, head);
    }
    else
    {
        // List is not empty - add element to end
        // use pointer to traverse the list
        
        ListNode *p = head;
        while (p->next != NULL)
            p = p->next;
        
        // create a new node and add it after the last node
        
        p->next = new ListNode(letter, tail);
    }
}

/****************************************************************************
 *                                                                          *
 *                           LinkedList::print                              *
 * Prints all elements of the list.                                         *
 *                                                                          *
 ***************************************************************************/

void LinkedList::print()
{
    ListNode *p = head;                 //  start at head of list
    while (p != NULL)
    {
        // print value in current node
        
        cout << p->letterData << " ";
        
        // move to next node
        
        p = p->next;
    }
    cout << endl;
}

/****************************************************************************
 *                                                                          *
 *                           LinkedList::reverse                            *
 * Rearranges the elements of the list to put them in reverse order.        *
 *                                                                          *
 ***************************************************************************/

void LinkedList::reverse()
{
    ListNode *rev = NULL;
    ListNode *p = head;
    ListNode *mover;
    
    while (p)
    {
        mover = p;
        p = p->next;
        mover->next = rev;
        rev = mover;
    }
    head = rev;
}

/****************************************************************************
 *                                                                          *
 *                           Destructor                                     *
 *                                                                          *
 ***************************************************************************/

LinkedList::~LinkedList()
{
    ListNode *p = head;
    ListNode *q;
    while (p != NULL)
    {
        q = p->next;
        delete p;
        p = q;
    }
}

// Program driver

int main()
{
    LinkedList list1;
    char dataInput;
    
    ifstream inputFile;     //input file stream object
    
    // Open the data file for linked list input
    
    inputFile.open("linkedText.txt");
    
    if (!inputFile)
        cout << "Error opening data file\n";
    else
    {
        // Read the character data from the input file into list using add method
        
        while (inputFile >> dataInput)
        {
            list1.add(dataInput);
        }
        
        // Close the input file
        
        inputFile.close();
    }
    
    cout << "Linked List 1 contains the following elements:" << endl;
    
    // Call print method to print contents of linked list
    
    list1.print();
    
    cout << endl;
    
    // Call reverse method to create new reversed linked list
    
    list1.reverse();
    
    cout << "Linked List 2 contains the following elements:" << endl;
    
    // Call print method to print contents of reversed linked list
    
    list1.print();
    
    cout << endl;

    return 0;
}

