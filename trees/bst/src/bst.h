#pragma once

#include "../../../vectors/src/vector.h"


enum TraversalType {
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER
};
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
    Bst(const Bst<T>& other);
    Bst<T>& operator=(const Bst<T>& other);
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
    int size_;


    void _destroy(TreeNode* subRoot);
    TreeNode* _copy(TreeNode* subRoot);
    void insert(TreeNode*& subRoot, const T& elem);
    TreeNode*& find(TreeNode*& subRoot, const T& elem);
    void traverse(TreeNode* subRoot, Vector<T>& trav, TraversalType travType) const;
};

#include "Bst.hpp"