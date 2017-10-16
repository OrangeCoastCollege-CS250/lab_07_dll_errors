#include "DoublyList.h"

DoublyList::DoublyList()
{
	count = 0;
}

void DoublyList::insertBack(int newData)
{
	Node *newNode = new Node(newData, nullptr);

	if (first == nullptr)
		first = newNode;
	else
	{
		last->setNext(newNode);
		newNode->setPrev(last);
	}
}

bool DoublyList::search(int searchData) const
{
    Node *current = first;	

    while (current != nullptr)	
	{		
		if (current->getData() = searchData)
			return true;
        else
            current = current->getNext();	
	}
}

void DoublyList::deleteNode(int deleteData) 
{
    if (first == nullptr)		
	{
        cerr << "Cannot delete from an empty list." << endl;
	}
    else  
    {
		Node *current = first;

        if (first->getData() == deleteData)   
		{	
			first = first->getNext();	

			if (first == nullptr)	
				last = nullptr;				

			delete current;
			current = nullptr;		
		}
		else 
		{
			bool found = false;								

			while (current != nullptr || !found) 
			{				  
				if (current->getData() == deleteData) 
					found = true;					  
				else
					current = current->getNext(); 
			}

			if (current == nullptr)	
				cerr << "The item to be deleted is not in the list." << endl;
			else         
			{
				if (current != last)		
					current->getPrev()->setNext(current->getNext());
				else
					last = current->getPrev();			
		
				--count;
				delete current;
				current = nullptr;
			}
		}
	}	
}

void print() const
{
	if (count == 0)
		cerr << "List is empty. Cannot print." << endl;
	else
	{
		Node *temp = first;
		while (first != nullptr)
		{
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		cout << endl;
	}	
}

void DoublyList::reversePrint() 
{
	if (count == 0)
		cerr << "List is empty. Cannot print." << endl;
	else
	{
		Node *temp = last;
		while (last != nullptr)
		{
			cout << temp->getData() << " ";
			temp = temp->getPrev();
		}
		cout << endl;
	}
}

void DoublyList::destroyList()
{ 
	Node  *temp = first;
	while (first != nullptr)
	{
		temp = temp->getNext();
		delete first;
		first = nullptr;
	}
	count = 0;
}

DoublyList::~DoublyList()
{}