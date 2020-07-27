#include "LinkedList.h"
#include <iostream>

int main()
{
	std::unique_ptr<List<int>> myLinkedList = std::make_unique<LinkedList<int>>();

#if 0
	myLinkedList->insert(1);
	myLinkedList->insert(2);
	myLinkedList->insert(3);
	myLinkedList->insert(4);
	myLinkedList->traverseList();

	//O(1)
	myLinkedList->remove(4);
	myLinkedList->traverseList();
#endif
	myLinkedList->Remove(4);
	
	return 0;
}
