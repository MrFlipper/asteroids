// *********************************************************
// Implementation file ListP.cpp for the ADT list.
// Pointer-based implementation.
// *********************************************************
#include "list.h" // header file   
#include <stddef.h> // for NULL
#include <assert.h> // for assert()
#include <iostream> //for cout
using namespace std;

List::List(): size(0), head(NULL)
    {
    } // end default constructor

List::List(const List & L): size(L.size)
    {
    if (L.head == NULL)
        head = NULL; // original list is empty

    else
        { // copy first node
        head = new ListNode;
        assert(head != NULL); // check allocation
        head->item = L.head->item;

        // copy rest of list
        ListNode * NewPtr = head; // new list pointer
        // NewPtr points to last node in new list 
        // OrigPtr points to nodes in original list
        for (ListNode * OrigPtr = L.head->next;OrigPtr != NULL;OrigPtr = OrigPtr->next)
            { NewPtr->next = new ListNode;
            assert(NewPtr->next != NULL);
            NewPtr = NewPtr->next;
            NewPtr->item = OrigPtr->item;
            } // end for

        NewPtr->next = NULL;
        } // end if
    } // end copy constructor

List::~List()
    {
    bool Success;

    while (not isEmpty())
        remove(1, Success);
    } // end destructor

bool List::isEmpty() const
    {
    return bool(size == 0);
    } // end ListIsEmpty

int List::getLength() const
    {
    return size;
    } // end ListLength

List::ListNode * List::find(int Position) const
    // --------------------------------------------------
    // Locates a specified node in a linked list.
    // Precondition: Position is the number of the 
    // desired node.
    // Postcondition: Returns a pointer to the desired 
    // node. If Position < 1 or Position > the number of 
    // nodes in the list, returns NULL.
    // --------------------------------------------------
    {
    if ( (Position < 1) || (Position > getLength()) )
        return NULL;

    else // count from the beginning of the list
        { ListNode * Cur = head;
        for (int Skip = 1; Skip < Position; ++Skip)
            Cur = Cur->next;
        return Cur;
        } // end if
    } // end find

void List::retrieve(int Position,ListItemType & Dataitem, bool & Success) const
    {
    ListNode * Cur;
    Success = bool( (Position >= 1) and (Position <= getLength()) );

    if (Success)
        { // get pointer to node, then data in node
        Cur = find(Position);
        if(Cur->next !=NULL)
            cout<<"Next Item: "<<Cur -> next -> item<<endl;
        else
            cout<<"No next Item.\n";
        if(Cur->prior !=NULL)
            cout<<"Previous Item: "<<Cur-> prior -> item<<endl;
        else
            cout<<"No Previous Item.\n";
        Dataitem = Cur->item;
        } // end if
    } // end retrieve

void List::insert(int NewPosition,ListItemType Newitem, bool & Success)
    {
    ListNode * Prev;
    ListNode * NewPtr;
    int NewLength = getLength() + 1;

    Success = bool( (NewPosition >= 1) and (NewPosition <= NewLength) );

    if (Success)
        { // create new node and place Newitem in it
        NewPtr = new ListNode;
        Success = bool(NewPtr != NULL);
        if (Success)
            { size = NewLength;
            NewPtr->item = Newitem;

            // attach new node to list
            if (NewPosition == 1)
                { // insert new node at beginning of list
                NewPtr->next = head;
                head = NewPtr;
                NewPtr->prior = NULL;// Set previous node to NULL
                if(NewPtr->next != NULL)
                    NewPtr->next->prior = NewPtr;
                }

            else
                { Prev = find(NewPosition-1);
                // insert new node after node 
                // to which Prev points
                NewPtr->prior = Prev;
                if(Prev->next !=NULL){
                    NewPtr->next = Prev->next;
                    Prev->next->prior = NewPtr;
                }
                Prev->next = NewPtr;

                } // end if
            } // end if
        } // end if
    } // end insert

void List::remove(int Position, bool & Success)
    {
    ListNode * Cur;
    ListNode * Prev;

    Success = bool( (Position >= 1) and (Position <= getLength()) );

    if (Success)
        { --size;
        if (Position == 1)
            { // delete the first node from the list
            Cur = head; // save pointer to node
            if(head->next != NULL)
                head = head->next;
            Cur->next = NULL;
            head->prior = NULL;
            }

        else
            { Prev = find(Position-1);
            // delete the node after the
            // node to which Prev points
            Cur = Prev->next; // save pointer to node
            Cur->prior = Prev;
            if(Cur->next != NULL){
                Prev->next = Cur->next;
                Cur->next->prior = Prev;
            }
            else
                Prev->next = NULL;
                        } // end if

        // return node to system
        Cur->next = NULL;
        delete Cur;
        Cur = NULL;
        } // end if
    } // end Cur->next->prior = Prev;
