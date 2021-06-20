#endif // RING_H_INCLUDED

template<typename Key, typename Info>
Ring<Key, Info>::Ring()
{
	head = nullptr;
	tail = nullptr;
}

template<typename Key, typename Info>
Ring<Key, Info>::~Ring()
{
	RemoveAll();
}

template<typename Key, typename Info>
bool Ring<Key, Info>::isEmpty() const
{
	return (head == nullptr);
}

template<typename Key, typename Info>
int Ring<Key, Info>::RingSize(){

    auto it = begin();
    int count = 0;

    do {
        it++;
        count++;
    } while (it != begin());

    return count;
}

template<typename Key, typename Info>
void Ring<Key, Info>::PushFront(const Key& key, const Info& info)
{
	auto new_node = new Node(key, info);

	if (isEmpty()){
		head = new_node;
		tail = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		}

	tail->next = new_node;
	new_node->prev = tail;
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
}

template<typename Key, typename Info>
void Ring<Key, Info>::PushBack(const Key& key, const Info& info){

    auto new_node = new Node(key, info);

    if (isEmpty()){
        head = new_node;
        tail = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
     }

	tail->next = new_node;
	new_node->next = head;
    new_node->prev = tail;
	head->prev = new_node;
    tail = new_node;

}

template<typename Key, typename Info>
void Ring<Key, Info>::DeleteNode(Node *node)
{
        if (!isEmpty()){

                (node)->prev->next = (node)->next;
                (node)->next->prev = (node)->prev;

                if (node == head) {
                    head = (node)->next;
                }

                if (node == tail){
                    node = (node)->prev;
                }

                delete(node);
        }
}


template<typename Key, typename Info>
bool Ring<Key, Info>::PushAfter(const Key& key, const Info& info, Key Location, int occur)
{
	auto it = begin();
	int count = 0;

	if (isEmpty()){
		return false;
	}

	do{
		if ((*it)->key == Location){
			count++;
		}

		if (count == occur){
			Node* temp = new Node(key, info);
			temp->next = (*it)->next;
			temp->prev = (*it);
			temp->next->prev = temp;
			(*it)->next = temp;
			return true;
        }

        it++;

    } while (it != begin());

    return false;
}

template<typename Key, typename Info>
void Ring<Key, Info>::PrintNode(Node *node){
    std::cout<<"Key "<<node->key<<"  "<<"Info "<<node->info<<std::endl;
}

template<typename Key, typename Info>
void Ring<Key, Info>::Print()
{
	if (isEmpty()){
		std::cout<<"List is empty"<<std::endl;
        return;
	}

	auto it = begin();

	do {
		PrintNode(*it);
		it++;
	}while (it != begin());
}

template<typename Key, typename Info>
void Ring<Key, Info>::RemoveAll()
{
    head = nullptr;
	tail = nullptr;
	
    auto it = begin();
	while (it != end()){
		delete (*it);
		it++;
	}


}

template<typename Key, typename Info>
bool Ring<Key, Info>::RemoveNode(Key key, int occur)
{
    int count = 0;
	auto it = begin();

        if (!isEmpty()){
            do{
                if ((*it)->key == key){
                    count++;
                }

                if (count == occur){
                    if(RingSize() == 1){
                        RemoveAll();
                        return true;
                    }

                (*it)->prev->next = (*it)->next;
                (*it)->next->prev = (*it)->prev;

                if (it == begin()) {
                    head = (*it)->next;
                }

                if (it == end()){
                    tail = (*it)->prev;
                }

                delete(*it);
                return true;
                }

                it++;
            } while (it != begin());
        }
    return false;

}