#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED

template <typename Key, typename Info>
class Dictionary {
public:
    struct Node {
        Key key;
        Info info;
        Node* left = nullptr;
        Node* right = nullptr;
        int height = 1;

        Node (Key key, Info info){
            this->key = key;
            this->info = info;

        };
    };
    Node *root = nullptr;

    void insert(const Key& k, const Info& i);
    void remove(const Key& k);
    bool hasKey(const Key& k);
    Info* find(const Key& k);
    void printInorder();
    void printPostorder();
    void print2D();

private:
    Node* singleRightRotate(Node* node);
    Node* singleLeftRotate(Node* node);
    Node* doubleLeftRotate(Node* node);
    Node* doubleRightRotate(Node* node);
    Node* insertNode(Node*node, const Key& k, const Info& i);
    Node* searchKey(Node* node, const Key& k);
    Node* removeNode(Dictionary::Node *node, const Key &key);
    void inorder(Node *node);
    void postorder(Node *node);
    void print2DD(Node *root, int space);

    int getHeight(Node *node){
        return node ? node->height : 0;
    }

     int getBalance(Node *node) {
        if (node == nullptr)
            return 0;
        auto left_height = getHeight(node->left);
        auto right_height = getHeight(node->right);

        return left_height - right_height;
    }

};

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Node* Dictionary<Key, Info>::insertNode(Node*node, const Key& k, const Info& i){

    if (node == nullptr) {
         return new Node(k, i);
    }

    if (k < node->key)
        node->left = insertNode(node->left, k, i);
    else if (k > node->key)
        node->right = insertNode(node->right, k, i);
    else
        std::cout<<"Key already exist"<<std::endl;


    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return singleRightRotate(node);

     if (balance < -1 && getBalance(node->right) <= 0)
        return singleLeftRotate(node);

    if (balance > 1 && getBalance(node->left) < 0) {
        return doubleRightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
        return doubleLeftRotate(node);
    }

    return node;
}


template <typename Key, typename Info>
void Dictionary<Key,Info>::insert(const Key& k, const Info& i){
    root = insertNode(root, k, i);
}

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Node* Dictionary<Key,Info>::singleRightRotate(Node* node) {
    Node *left = node->left;
    Node *right = left->right;

    left->right = node;
    node->left = right;

    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    left->height = std::max(getHeight(left->left), getHeight(left->right)) + 1;

    return left;
}

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Node* Dictionary<Key,Info>::singleLeftRotate(Node* node) {
    Node *right = node->right;
    Node *left = right->left;

    right->left = node;
    node->right = left;

    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    right->height = std::max(getHeight(right->left), getHeight(right->right)) + 1;

    return right;
}

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Node* Dictionary<Key,Info>::doubleLeftRotate(Node* node) {
    node->right = singleRightRotate(node->right);
    return singleLeftRotate(node);
}

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Node* Dictionary<Key,Info>::doubleRightRotate(Node* node) {
    node->left = singleLeftRotate(node->left);
    return singleRightRotate(node);
}

template<typename Key, typename Info>
typename Dictionary<Key, Info>::Node* Dictionary<Key, Info>::searchKey(Node* node,const Key& k){
    if (node){
        if (node->key == k){
            return node;
        }
        if (k < node->key){
            return searchKey(node->left, k);
        }
        else {
            return searchKey(node->right, k);
        }
    }
    return nullptr;
}

template<typename Key, typename Info>
bool Dictionary<Key, Info>::hasKey(const Key& k){
    if(root == nullptr)
        return false;

    if(searchKey(root,k) != nullptr)
        return true;
    else
        return false;
}

template <typename Key, typename Info>
Info* Dictionary<Key,Info>::find(const Key& k){
    if(root == nullptr)
        return nullptr;

    Info* ptr ;
    if(hasKey(k)){
        ptr = &searchKey(root,k)->info;
            return ptr ;
    }
    else
        return nullptr;
}

template<typename Key, typename Info>
typename Dictionary<Key, Info>::Node *Dictionary<Key, Info>::removeNode(Dictionary::Node *node, const Key &key) {
    if (node == nullptr)
        return node;

    if (key < node->key) {
        node->left = removeNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = removeNode(node->right, key);
    }
    else {
        if (node->right == nullptr || node->left == nullptr) {
            Node *temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            }
            else {
                *node = *temp;
            }
            free(temp);
        }
        else {
        Node* temp = node->right;

        while (temp->left != nullptr){
            temp = temp->left;
        }
            node->key = temp->key;
            node->info = temp->info;
            node->right = removeNode(node->right, temp->key);
        }
    }

    if (node == nullptr)
        return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return singleRightRotate(node);

     if (balance < -1 && getBalance(node->right) <= 0)
        return singleLeftRotate(node);


    if (balance > 1 && getBalance(node->left) < 0) {
        return doubleRightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
        return doubleLeftRotate(node);
    }

    return node;
}

template <typename Key, typename Info>
void Dictionary<Key,Info>::remove(const Key& k){
    if (root == nullptr)
        return;
    root = removeNode(root,k);
}


template<typename Key, typename Info>
void Dictionary<Key,Info>::print2DD(Node *root, int space)
{
    int vCount = 7;

    if (root == NULL)
        return;

    space += vCount;
    print2DD(root->right, space);

    std::cout<<std::endl;
    for (int i = vCount; i < space; i++)
        std::cout<<" ";

    std::cout<<root->key<<"\n";
    print2DD(root->left, space);
}

template<typename Key, typename Info>
void Dictionary<Key,Info>::print2D()
{
    print2DD(root, 0);
}

template <typename Key, typename Info>
void Dictionary<Key,Info>::inorder(Node *node) {
    if (node!=nullptr) {
    inorder(node->left);
    std::cout << node->key<< " ";
    inorder(node->right);
    }
}

template <typename Key, typename Info>
void Dictionary<Key,Info>::postorder(Node *node){
    if (node!=nullptr) {
    postorder(node->left);
    postorder(node->right);
    std::cout << node->key<< " ";
    }


}

template <typename Key, typename Info>
void Dictionary<Key,Info>::printInorder() {
    if(root == nullptr)
        std::cout<<"Dictionary is empty"<<std::endl;
    else
        inorder(root);
        std::cout<<std::endl<<std::endl;
}

template <typename Key, typename Info>
void Dictionary<Key,Info>::printPostorder() {
    if(root == nullptr)
        std::cout<<"Dictionary is empty"<<std::endl;
    else
        postorder(root);
        std::cout<<std::endl<<std::endl;
}


#endif // DICTIONARY_H_INCLUDED
