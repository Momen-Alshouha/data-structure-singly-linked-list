#pragma once
#include "Iterator.h"
#include "Node.h"

template <typename T = int> // int is default template argument
class LinkedList
{
private:
	
	Node<T>* _Head = nullptr;
	
	Node<T>* _Tail = nullptr;

	Iterator<T> _begin() {
		return Iterator<T>(_Head);
	}

	Iterator<T> _end() {
		return Iterator<T>(_Tail->_ptrNext);
	}

public:

	LinkedList() : _Head(nullptr), _Tail(nullptr) {};



	void InsertBegin(T DataToInsert) {
		Node<T>* NewNode = new(nothrow) Node<T>(DataToInsert);
		
		if (NewNode==nullptr)
		{
			cout << "Error Throw Memory Allocation!\n";
		}
		else {
			if (_Head==nullptr)
			{
				_Head = _Tail = NewNode;
			}
			else {
				NewNode->_ptrNext = _Head;
				_Head = NewNode;
			}
		}
	}

	void print() {
		if (_Head == nullptr) {
			cout << "Linked List Is Empty!\n";
			return;
		}
		Iterator<T> itr = _begin();
		for (; itr != _end(); itr.next()) {
			cout << itr.data << " ";
		}
		cout << endl;
	}


};

