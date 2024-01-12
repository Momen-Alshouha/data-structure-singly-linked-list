# Singly Linked List Implementation in C++

This repository contains an implementation of a singly linked list using C++ and Object-Oriented Programming principles.

## Overview

### Classes
- **Node**: Represents individual nodes in the singly linked list.
- **Iterator**: Provides iteration capabilities over the linked list.
- **LinkedList**: Implements the singly linked list and its functionalities.

## Classes and Functionality

### Node Class
The `Node` class represents individual elements in the singly linked list. Each node holds:
- `_Data`: Data of type `T`.
- `_ptrToNextNode`: Pointer to the next node.

### Iterator Class
The `Iterator` class provides functionality for iterating through the singly linked list. It includes methods to:
- Access node data.
- Set node data.
- Move to the next node.
- Access the current node.

### LinkedList Class
The `LinkedList` class implements a basic singly linked list with the following functionalities:
- Retrieving the head and tail nodes.
- Finding elements by index or data.
- Inserting elements before or after specified nodes or at specific indices.
- Deleting nodes by data or index.
- Concatenating two linked lists.
- Calculating the sum of elements (if the template type is arithmetic).
- Getting the length of the linked list.

## Usage

To use this singly linked list implementation, follow these steps:
1. Clone the repository.
2. Include the necessary header files in your C++ code: `Node.h`, `Iterator.h`, and `LinkedList.h`.
3. Create a `LinkedList` object and utilize its functionalities as per your requirements.

## Example

```cpp
// Example usage of the LinkedList class
#include "LinkedList.h"

int main() {
    LinkedList<int> myList;
    
    // Perform operations like insertion, deletion, and retrieval here
    
    return 0;
}
