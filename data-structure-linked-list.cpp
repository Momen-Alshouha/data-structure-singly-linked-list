#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> list1,list2;

	list1.InsertBegin(10);
	list1.Contact(list2);

	list1.print();

	

}