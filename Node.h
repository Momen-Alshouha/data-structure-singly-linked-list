#pragma once
#include <iostream>
using namespace std;

template<typename T = int> // int is default template argument
class Node
{
private:
    T _Data;
    Node<T>* _ptrToNextNode;

public:

    Node(T Data) : _Data(Data), _ptrToNextNode(nullptr) {}

    T GetData()
    {
        return _Data;
    }

    void SetData(T Data)
    {
        _Data = Data;
    }

    Node<T>* GetNext() {
        if (_ptrToNextNode != nullptr) {
            return _ptrToNextNode;
        }
        else {
            return nullptr; 
        }
    }

    void SetNext(Node<T>* ptrNext) {
        _ptrToNextNode = ptrNext;
    }


    // properties
    __declspec(property(get = GetData, put = SetData)) T data;
    __declspec(property(get = GetNext, put = SetNext)) Node<T>* _ptrNext;

};



