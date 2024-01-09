#pragma once
#include "Iterator.h"
#include "Node.h"

template <typename T = int> // int is default template argument
class LinkedList
{
private:
	
	Node<T>* _Head = nullptr;
	
	Node<T>* _Tail = nullptr;

	short _length;

	Iterator<T> _begin() {
		return Iterator<T>(_Head);
	}

	Iterator<T> _end() {
		return Iterator<T>(_Tail->_ptrNext);
	}


public:

	LinkedList() : _Head(nullptr), _Tail(nullptr) {
		_length = _Length();
	};

	Node<T>* GetHead() {
		return _Head;
	}

	Node<T>* GetTail() {
		return _Tail;
	}

	__declspec(property(get = GetLength)) short length;
	__declspec(property(get = GetHead)) Node<T>* head;
	__declspec(property(get = GetTail)) Node<T>* tail;

	short GetLength() {
		short length = 0;
		if (_Head == nullptr)
		{
			return length;
		}
		else {
			for (Iterator<T> itr = _begin(); itr != _end(); itr.next())
			{
				length++;
			}
		}
		return length;
	}


	bool Find(T DataToFind) {
		for (Iterator<T> itr = _begin(); itr != _end(); itr.next()) {
			if (itr.data == DataToFind) {
				return true;
			}
		}
		return false;
	}

	bool Find(T DataToFind, Node<T>*& FoundNode) {
		for (Iterator<T> itr = _begin(); itr != _end(); itr.next()) {
			if (itr.data == DataToFind) {
				FoundNode = itr.current_node;
				return true;
			}
		}
		FoundNode = nullptr;
		return false;
	}

	Node<T>* FindParentNode(Node<T>* NodeToFindParent) {
		if (_Head == nullptr || NodeToFindParent == _Head) {
			return nullptr;
		}

		Node<T>* currentNode = _Head;

		// Traverse the list to find the parent of the given node
		while (currentNode != nullptr && currentNode->_ptrNext != NodeToFindParent) {
			currentNode = currentNode->_ptrNext;
		}

		return currentNode;
	}

	void InsertAfter(T DataToInsertAfter, T DataToInsert) {

		Node<T>* NodeToInsertAfter = new Node<T>(DataToInsertAfter);

		bool IsExist = Find(DataToInsertAfter, NodeToInsertAfter);

		if (!IsExist) {
			cout << "Data To Insert Before Not Found!\n";
			return;
		}

		Node<T>* NewNode = new (nothrow) Node<T>(DataToInsert);

		if (NewNode == nullptr) {
			cout << "Error Throw Memory Allocation!\n";
			return;
		}

		NewNode->_ptrNext = NodeToInsertAfter->_ptrNext;
		NodeToInsertAfter->_ptrNext = NewNode;

		if (NodeToInsertAfter==_Tail)
		{
			_Tail = NewNode;
		}
	}




	void InsertBefore(T DataToInsertBefore, T DataToInsert) {
		Node<T>* currentNode = _Head;
		Node<T>* prevNode = nullptr;

		while (currentNode != nullptr && currentNode->data != DataToInsertBefore) {
			prevNode = currentNode;
			currentNode = currentNode->_ptrNext;
		}

		if (currentNode == nullptr) {
			cout << "Data To Insert Before Not Found!\n";
			return;
		}

		Node<T>* newNode = new (nothrow) Node<T>(DataToInsert);
		
		if (newNode == nullptr) {
			cout << "Error Thrown: Memory Allocation!\n";
			return;
		}

		newNode->_ptrNext = currentNode;
		if (prevNode == nullptr) {
			_Head = newNode;
		}
		else {
			prevNode->_ptrNext = newNode;
		}
	}



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

	void InsertEnd(T DataToInsert) {
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
				_Tail->_ptrNext = NewNode;
				_Tail = NewNode;
			}
		}
	}

	void DeleteFirstNode() {
		if (_Head==nullptr)
		{
			cout << "Linkedlist is empty!\n";
			return;
		}
		else {
			Node<T>* Temp = _Head;
			_Head = _Head->_ptrNext;
			delete Temp;
		}
	}

	void DeleteNode(T DataToDelete) {
		Node<T>* NodeToDelete = nullptr;
		Find(DataToDelete, NodeToDelete);
		if (NodeToDelete==nullptr)
		{
			cout << "Node Not Found!\n";
		}
		else {
			if (NodeToDelete == _Head)
			{
				Node<T>* temp= _Head->_ptrNext;
				delete _Head;
				_Head = temp;
			}
			else if (NodeToDelete==_Tail) {
				Node<T>* tailParent = FindParentNode(_Tail);
				delete _Tail;
				_Tail = tailParent;
			}
			else {
				Node<T>* NodeParent = FindParentNode(NodeToDelete);
				NodeParent->_ptrNext = NodeToDelete->_ptrNext;
				delete NodeToDelete;
			}
		}
	}

	void DeleteLastNode() {
		if (_Head == nullptr) {
			cout << "Linkedlist is empty!\n";
			return;
		}
		else if (_Head->_ptrNext == nullptr) {
			// If there's only one node in the list
			delete _Head;
			_Head = _Tail = nullptr;
			return;
		}

		Node<T>* TailParent = FindParentNode(_Tail);

		if (TailParent == nullptr) {
			cout << "Unable to find parent of tail!\n";
			return;
		}

		delete _Tail;
		TailParent->_ptrNext= nullptr;
		_Tail = TailParent;
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

