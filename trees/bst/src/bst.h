#pragma once

#include "../../vectors/src/vector.h"

template <typename T>
class Bst {
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
    Bst();
    Bst(const BST<T>& other);
    Bst<T>& operator=(const BST<T>& other);
    ~Bst();

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


    void _destroy(TreeNode* root);
    TreeNode* _copy(TreeNode* subRoot);

    void insert(TreeNode*& subRoot, const T& elem);


};

#include "bst.hpp"