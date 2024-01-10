#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> list;
	list.InsertBegin(1);
	list.InsertBegin(2);
	list.InsertBegin(3);
	list.InsertBegin(4);

	list.InsertAfter(1, 5);
	list.DeleteLastNode();
	list.InsertAtIndex(1,99);
	list.print();

	

}