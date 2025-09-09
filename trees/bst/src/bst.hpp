template <typename T>
Bst<T>::Bst() : root(NULL), size_(0) {}

template <typename T>
Bst<T>::Bst(const Bst<T>& other) {
    *this = other;
}

template <typename T>
Bst<T>& Bst<T>::operator=(const Bst<T>& other) {
    if (this != &other) {
        _destroy(root);
        root = _copy(other.root);
        size_ = other.size_;
    }
    return *this;
}

template <typename T>
Bst<T>::~Bst() {
    _destroy(root);
    root = NULL;
    size_ = 0;
}


template <typename T>
void Bst<T>::_destroy(TreeNode* subRoot) {
    if (subRoot == NULL) return;
    _destroy(subRoot->right);
    _destroy(subRoot->left);
    delete subRoot;
}

template <typename T>
typename Bst<T>::TreeNode* Bst<T>::_copy(TreeNode* subRoot) {
    if (subRoot == NULL) return NULL;
    TreeNode* newNode = new TreeNode(subRoot->data);
    newNode->left = _copy(subRoot->left);
    newNode->right = _copy(subRoot->right);
    if (newNode->left != NULL) newNode->left->parent = newNode;
    if (newNode->right != NULL) newNode->right->parent = newNode;
    return newNode;
}

template <typename T>
int Bst<T>::size() const {
    return size;
}

template <typename T>
void Bst<T>::insert(const T& elem) {
    insert(root, elem);
}

template <typename T>
void Bst<T>::insert(TreeNode*& subRoot, const T& elem) {
    if (subRoot == NULL) {
        subRoot = new TreeNode(elem);
        size_++;
        return;
    }
    if (subRoot->data < elem) {
        insert(subRoot->right, elem);
        subRoot->right->parent = subRoot;
    } else {
        insert(subRoot->left, elem);
        subRoot->left->parent = subRoot;
    }
}

template <typename T>
bool Bst<T>::contains(const T& elem) {
    return find(subRoot, elem) != NULL;
}

template <typename T>
typename Bst<T>::TreeNode*& Bst<T>::find(TreeNode*& subRoot, const T& elem) {
    if (subRoot == NULL) return NULL;
    if (subRoot->data == elem) return subRoot;
    if (subRoot->data < elem) return find(subRoot->right, elem);
    return find(subRoot->left, elem);
}

template <typename T>
Vector<T> Bst<T>::inOrderTraversal() const {
    Vector<T> path;
    traverse(root, path, IN_ORDER);
    return path;
}

template <typename T>
Vector<T> Bst<T>::preOrderTraversal() const {
    Vector<T> path;
    traverse(root, path, PRE_ORDER);
    return path;
}

template <typename T>
Vector<T> Bst<T>::postOrderTraversal() const {
    Vector<T> path;
    traverse(root, path, POST_ORDER);
    return path;
}

template <typename T>
Vector<T> Bst<T>::levelOrderTraversal() const {
    if (root == NULL) return Vector<T>();
    Vector<TreeNode*> levelOrder(size, NULL);
    size_t rootidx = 0;
    levelOrder[rootidx] = root;
    size_t cidx = 1;
    while (cidx < levelOrder.size()) {
        if (levelOrder[rootidx]->left != NULL) {
            levelOrder[cidx] = levelOrder[rootidx]->left;
            cidx++;
        }
        if (levelOrder[rootidx]->right != NULL) {
            levelOrder[cidx] = levelOrder[rootidx]->right;
            cidx++;
        }
        rootidx++;
    }
    Vector<T> path;
    for (TreeNode* node : levelOrder) path.push_back(node->data);
    return path;
}

template <typename T>
void Bst<T>::traverse(TreeNode* subRoot, Vector<T>& trav, TraversalType travType) const {
    if (subRoot == null) return;
    switch (travType) {
        case IN_ORDER:
            traverse(subRoot->left, trav, IN_ORDER);
            trav.push_back(subRoot->data);
            traverse(subRoot->right, trav, IN_ORDER);
            break;
        case PRE_ORDER:
            trav.push_back(subRoot->data);
            traverse(subRoot->left, trav, PRE_ORDER);
            traverse(subRoot->right, trav, PRE_ORDER);
            break;
        case POST_ORDER:
            traverse(subRoot->left, trav, POST_ORDER);
            traverse(subRoot->right, trav, POST_ORDER);
            trav.push_back(subRoot->data);
            break;
    }
}

template <typename T>
Bst<T>::TreeNode::TreeNode() : data(T()), left(NULL), right(NULL), parent(NULL) {}

template <typename T>
Bst<T>::TreeNode::TreeNode(const T& data) : data(data), left(NULL), right(NULL), parent(NULL) {};
