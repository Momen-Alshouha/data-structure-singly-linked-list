#pragma once
#include "Node.h"

template <typename T = int > // int is default template argument
class Iterator
{
private:
	Node<T>* _CurrentNode;

public:

	Iterator()
	{
		_CurrentNode = nullptr;
	}

	Iterator(Node<T>* CurrentNode)
	{
		_CurrentNode = CurrentNode;
	}

	T data()
	{
		return _CurrentNode->data;
	}

	void next() {
		_CurrentNode = _CurrentNode->next();
	}

	Node<T> GetCurrentNode() {
		return _CurrentNode;
	}

};
