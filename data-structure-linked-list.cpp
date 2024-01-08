#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<string> list;
	list.InsertEnd("end");
	list.InsertBegin("Ahmad");
	list.InsertBegin("mohammed");
	list.InsertEnd("hani");
	list.print();
	
}