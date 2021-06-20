ifndef RING_H_INCLUDED
#define RING_H_INCLUDED
#include<iostream>

template<typename Key, typename Info> class Ring {
private:
    struct Node{
        Key key;
        Info info;
        Node *next;
        Node *prev;
        Node (Key key, Info info){
            this->key = key;
            this->info = info;
        }
    };

    Node *head;
    Node *tail;
	void PrintNode(Node *node);// internal function to print a node
    void DeleteNode(Node *node);

public:
    Ring();
	~Ring();

	bool isEmpty() const;// checks if the ring is empty
    int RingSize();// counts the nodes in a ring
    bool RemoveNode(Key key, int occur = 1); // removes and deletes a node with given key and occurrence
    void RemoveAll(); // removes and deletes all nodes of the ring
	void PushFront(const Key& key,const Info& info);    // pushes to the front(head) of the ring
	void PushBack(const Key& key,const Info& info); // pushes to the end(tail) of the ring
    bool PushAfter(const Key& key,const Info& info, Key Location, int occur = 1); // pushes after a certain element with given key and occurrence
    void Print(); //prints the whole ring from head to tail



 class iterator{

        Node * current;

    public :
        iterator(Node* node) : current(node) {}
        ~iterator() {}
        iterator& operator++() { current = current->next(); return *this; }// prefix increment operator.
        iterator operator++(int) { iterator it(*this); current = current->next; return it; }// postfix increment operator.
        iterator& operator--() { current = current->prev(); return *this; }// prefix decrement operator.
        iterator operator--(int){ iterator it(*this); current = current->prev; return it; }// postfix decrement operator.
        bool operator==(const iterator& arg) const { return (current == arg.current); } // comparison operator
        bool operator!=(const iterator& arg) const { return (current != arg.current); } // comparison operator
        Node* operator*() { return current; } // returns a pointer to the current node


    };
        iterator begin() const {return iterator(head); } // head location for iterator
        iterator end() const { return iterator(tail); } // tail location for iterator

};