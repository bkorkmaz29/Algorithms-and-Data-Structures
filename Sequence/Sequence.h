#ifndef SEQUENCE_H_INCLUDED
#define SEQUENCE_H_INCLUDED

#include <iostream>


template <typename Key, typename Info>
class Sequence {
private:
    class Node;
    void PrintAll(Node *node, int count); // internal print function
    Node *head = NULL; // the head of the Sequence
    Node *GetNode(Key key, int occurrence); // returns the node with input key
    int GetNodeIndex(Node *node); //returns the index of a node
    Node *GetNodeByIndex(int index);//returns the node at the index

    class Node { // Private class Node - can be used only in Sequence class
    public:
        Key key;
        Info info;
        Node *next;

        Node (Key key, Info info){
            this->key = key;
            this->info = info;
            this->next = NULL;
        };

    };

public:
    // Sequence();  // No need for constructor
    // ~Sequence(); // No need for destructor
    void PushBack(Key key, Info info); // Adds an element to the back
    void RemoveAtIndex(int index); // Removes en element at given index
    void Clear(); // Removes every element of the sequence
    int Count(); // Counts the sequence;
    void PrintAll(); // prints the whole sequence
    bool IsNull(int index); //checks if the element at index is null
    Key GetKeyAt(int index);//get key by index
    Info GetInfoAt(int index); //get info by index

    class InvalidArgumentException {
    private:
        std::string message;
    public:
        explicit InvalidArgumentException(const std::string& message){
            this->message = message;
        }
        friend std::ostream &operator<<(std::ostream &os, const Sequence<Key, Info>::InvalidArgumentException &ex);
    };
};

template <typename Key, typename Info>
std::ostream &operator<<(std::ostream &os, const typename Sequence<Key, Info>::InvalidArgumentException &ex) {
    return os << "Invalid value of argument: " << ex.message << std::endl;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::PushBack(Key key, Info info)  {
    Node *newElement = new Node(key, info);

    if (head == NULL){
        head = newElement;
        return;
    }
    Node *ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next=newElement;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::PrintAll(Node *node, int count){
    if (node == NULL && count == 0){
        node = head;
    }
    if (node==NULL)
        return;
    std::cout << count << ": (" << node->key<< "\t" << node->info << ")" << std::endl;
    PrintAll(node->next, ++count);
}

template <typename Key, typename Info>
void Sequence<Key, Info>::PrintAll(){
    PrintAll(NULL, 0);
}

template<typename Key, typename Info>
void Sequence<Key, Info>::RemoveAtIndex(int index) {
    if (index < 0){
        throw InvalidArgumentException("Index must be non-negative");
    }
    Node *nodeToRemove = GetNodeByIndex(index);

    if (nodeToRemove == NULL){
        throw InvalidArgumentException("Index out of bounds");
    }

    int nodeToRemoveIndex = GetNodeIndex(nodeToRemove);
    if (nodeToRemoveIndex > 0) {
        Node *previousNode = GetNodeByIndex(nodeToRemoveIndex - 1);

        if (previousNode) {
            previousNode->next = nodeToRemove->next;
        }
    }

    if (nodeToRemove == this->head){
        head = head->next;
    }
    delete nodeToRemove;

}

template<typename Key, typename Info>
typename Sequence<Key,Info>::Node *Sequence<Key, Info>::GetNode(Key key, int occurrence) {
    Node *node = head;
    int occuranceCounter = 0;
    while(node){
        if (node->refKey() == key && ++occuranceCounter == occurrence)
            return node;
        node = node->next;
    }
    return NULL;
}

template<typename Key, typename Info>
int Sequence<Key, Info>::GetNodeIndex(Sequence::Node *node) {
    if (node == NULL){
        throw InvalidArgumentException("Node cannot be null");
    }
    Node *tmpNode = head;
    int index = 0;
    while(tmpNode){
        if (tmpNode == node)
            return index;
        index++;
        tmpNode = tmpNode->next;
    }
    return -1;
}

template<typename Key, typename Info>
typename Sequence<Key, Info>::Node *Sequence<Key, Info>::GetNodeByIndex(int index) {
    if (index < 0){
        throw InvalidArgumentException("Index must be non-negative");
    }
    Node *tmpNode = head;
    for(int i = 0; tmpNode && i < index; i++){
        tmpNode = tmpNode->next;
    }
    return tmpNode;
}


template<typename Key, typename Info>
Key Sequence<Key, Info>::GetKeyAt(int index) {
    return this->GetNodeByIndex(index)->key;

}

template<typename Key, typename Info>
Info Sequence<Key, Info>::GetInfoAt(int index) {
    return this->GetNodeByIndex(index)->info;

}

template<typename Key, typename Info>
void Sequence<Key, Info>::Clear() {
    if (head == NULL)
        return;

    while(head != NULL)
        RemoveAtIndex(0);
}

template<typename Key, typename Info>
int Sequence<Key, Info>::Count() {
    int count = 0;

    while(!this->IsNull(count)){

        count++;
    }
    return count;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::IsNull(int index) {
    if (GetNodeByIndex(index) == NULL)
        return 1;
    else
        return 0;
}


#endif // SEQUENCE_H_INCLUDED
