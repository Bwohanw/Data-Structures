#pragma once

#include "../vectors/src/vector.h"

template <typename T>
class BST {
    private:
    class TreeNode {
        public:
        TreeNode();
        TreeNode(const T& data);

        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        T data;
    };

    public:
    BST();
    BST(const BST<T>& other);
    BST<T>& operator=(const BST<T>& other);
    ~BST();

    void insert(const T& elem);
    void remove(const T& elem);
    bool contains(const T& elem);

    int size() const;

    Vector<T> inOrderTraversal() const;
    Vector<T> preOrderTraversal() const;
    Vector<T> postOrderTraversal() const;
    Vector<T> levelOrderTraversal() const;



    private:

    TreeNode* root;
    int size;

    _copy(const BST<T>& other);
    _destroy();


};

#include "bst.hpp"