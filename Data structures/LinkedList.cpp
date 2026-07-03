#include "LinkedList.hpp"
#include <iostream>

Node::Node(int val) : value(val), nextPointer(nullptr) {}

LinkedList::LinkedList() : head(nullptr), isCircularList(false) {}

LinkedList::~LinkedList() {
    if (isCircularList) {
        breakCircular();
    }
}

void LinkedList::insertNode(std::shared_ptr<Node> newNode) {
    if (isCircularList) {
        std::cout << "Cannot insert into circular linked list \n";
        return;
    }

    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    std::shared_ptr<Node> currentNode = head;
    while (currentNode->nextPointer) {
        currentNode = currentNode->nextPointer;
    }
    currentNode->nextPointer = newNode;
}

void LinkedList::deleteNode(int value) {
    if (isCircularList) {
        std::cout << "Cannot delete from a circular list \n";
        return;
    }

    if (!head) {
        std::cout << "List is empty\n";
        return;
    }
    
    if (head->value == value) {
        head = head->nextPointer;
        std::cout << "Deleted head node\n";
        return;
    }
    
    std::shared_ptr<Node> currentNode = head;
    while (currentNode->nextPointer) {
        if (currentNode->nextPointer->value == value) {
            currentNode->nextPointer = currentNode->nextPointer->nextPointer;
            std::cout << "Deleted node with value " << value << "\n";
            return;
        }
        currentNode = currentNode->nextPointer;
    }
    
    std::cout << "Node with value " << value << " not found\n";
}

void LinkedList::findNode(int value) {
    if (!head) {
        std::cout << "Node not found (empty list)\n";
        return;
    }
    
    if (head->value == value) {
        std::cout << "Value found at head node\n";
        return;
    }
    
    std::shared_ptr<Node> currentNode = head->nextPointer;
    while (currentNode && currentNode != head) {
        if (currentNode->value == value) {
            std::cout << "Node found in linked list\n";
            return;
        }
        currentNode = currentNode->nextPointer;
    }
    
    std::cout << "Node not found in linked list\n";
}

void LinkedList::makeCircular() {
    if (!head) {
        std::cout << "Cannot make empty list circular \n";
        return;
    }

    if (isCircularList) {
        std::cout << "List is already circularly linked \n";
        return;
    }

    
    std::shared_ptr<Node> currentNode = head;
    while (currentNode->nextPointer) {
        currentNode = currentNode->nextPointer;
    }
    
    endNode = currentNode;
    currentNode->nextPointer = head;
    isCircularList = true;

    std::cout << "Linked list is now circular \n";
}

void LinkedList::breakCircular() {
    if (!isCircularList) {
        std::cout << "List isn't circular \n";
        return;
    }

    if (auto lastNode = endNode.lock()) {
        lastNode->nextPointer = nullptr;
        std::cout << "List is no longer circular";
    }

    isCircularList = false;
    endNode.reset();
}

bool LinkedList::isCircular() {
    if (!head) return false;

    std::shared_ptr<Node> slowPointer = head;
    std::shared_ptr<Node> fastPointer = head;

    while (fastPointer && fastPointer) {
        slowPointer = slowPointer->nextPointer;
        fastPointer = fastPointer->nextPointer->nextPointer;

        if (slowPointer == fastPointer) {
            return true;
        }
    }
    
    return false;
}