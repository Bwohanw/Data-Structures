
template <typename T>
BST<T>::TreeNode::TreeNode() : data(T()), left(NULL), right(NULL), parent(NULL) {}

template <typename T>
BST<T>::TreeNode::TreeNode(const T& data) : data(data), left(NULL), right(NULL), parent(NULL) {};

template <typename T>
BST<T>::BST() : root(NULL), size(0) {}

