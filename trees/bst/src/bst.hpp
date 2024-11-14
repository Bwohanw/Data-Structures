
template <typename T>
Bst<T>::TreeNode::TreeNode() : data(T()), left(NULL), right(NULL), parent(NULL) {}

template <typename T>
Bst<T>::TreeNode::TreeNode(const T& data) : data(data), left(NULL), right(NULL), parent(NULL) {};

template <typename T>
Bst<T>::Bst() : root(NULL), size(0) {}


template <typename T>
Bst<T>& Bst<T>::operator=(const Bst<T>& other) {
    if (this != &other) {
        _destroy(root);
        root = _copy(other.root);
        size = other.size;
    }
    return *this;
}

template <typename T>
Bst<T>::Bst(const Bst<T>& other) {
    *this = other;
}

template <typename T>
Bst<T>::~Bst() {
    _destroy(root);
    root = NULL;
    size = 0;
}


template <typename T>
void Bst<T>::_destroy(TreeNode* root) {
    if (root == NULL) return;
    _destroy(root->right);
    _destroy(root->left);
    delete root;
}

template <typename T>
Bst<T>::TreeNode* Bst<T>::_copy(TreeNode* subRoot) {
    if (subRoot == NULL) return NULL;
    TreeNode* newNode = new TreeNode(subRoot->data);
    newNode->left = copy(subRoot->left);
    newNode->right = copy(subRoot->right);
    if (newNode->left != NULL) newNode->left->parent = newNode;
    if (newNode->right != NULL) newNode->right->parent = newNode;
    return newNode;
}


void Bst<T>::insert(const T& elem) {
    insert(root, elem);
}

void Bst<T>::insert(TreeNode*& subRoot, const T& elem) {
    if (subRoot == NULL) {
        subRoot = new TreeNode(elem);
        return;
    }
    if (subRoot->data < elem) {
        insert(subRoot->right, elem);
        subRoot->right->parent = subRoot;
    } else {
        insert(subRoot->left, elem);
        subroot->left->parent = subRoot;
    }
}

