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

	T GetData()
	{
		return _CurrentNode->data;
	}

	void SetData(T Data) {
		_CurrentNode->data = Data;
	}

	void next() {
		_CurrentNode = _CurrentNode->_ptrNext;
	}

	Node<T>* GetCurrentNode() {
		return _CurrentNode;
	}

	bool operator!=(const Iterator& other) const {
		return _CurrentNode != other._CurrentNode;
	}

	__declspec(property(get = GetData ,put = SetData)) T data;
	__declspec(property(get = GetCurrentNode)) Node<T>* current_node;
};
