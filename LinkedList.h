#pragma once
#include "Iterator.h"
#include "Node.h"

template <typename T = int> // int is default template argument
class LinkedList
{
private:
	Node<T>* _Head = nullptr;
	Node<T>* _Tail = nullptr;

public:

	LinkedList() : _Head(nullptr), _Tail(nullptr) {};

	Iterator<T> begin() {
		return Iterator<T>(_Head);
	}

	Iterator<T> end() {
		return Iterator<T>(_Tail->next());
	}


};

