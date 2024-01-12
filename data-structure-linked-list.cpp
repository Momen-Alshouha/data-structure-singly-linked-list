#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> list;


	list.InsertEnd(5);
	
	list.InsertEnd(6);
	
	list.print();

	cout << list.GetSum() << endl;;

	list.DeleteFirstNode();

	list.print();

	list.DeleteFirstNode();

	cout << list.length << endl;
	

}