#include "LinkedList.h"
#include <iostream>
#include "LinkedList.h"

int main()
{
	std::unique_ptr<List<int>> myLinkedList = std::make_unique<LinkedList<int>>();

	myLinkedList->Insert(1);
	myLinkedList->Insert(2);
	myLinkedList->Remove(4);
	myLinkedList->Insert(3);
	myLinkedList->Insert(4);
	myLinkedList->Insert(2);
	//myLinkedList->Insert(4);
	myLinkedList->TraverseList();

	//O(1)
	//myLinkedList->Remove(4);
	//myLinkedList->TraverseList();
	
	return 0;
}
