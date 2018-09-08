#ifndef TREE_H
#define TREE_H

#include <string>
#include <initializer_list>  //alt constructor
#include "treenode.h"

template <typename ValueType>
class Tree {
public:
    Tree(TreeNode<ValueType>* root = nullptr);
    ~Tree();  //especially important to delete each heap allocated node

    /* cannot default values to root since it must be known at compile time.*/
    void add(const ValueType& value);
    void clear(TreeNode<ValueType>* curr = nullptr);
    bool contains(const ValueType& value) const;
    void remove(const ValueType& value);
    TreeNode<ValueType>* get(const ValueType& value) const;
    int get_size() const;
    std::string toStringInOrder() const;
    bool equals(Tree<ValueType>* other, bool subsetOf = false) const;
    TreeNode<ValueType>* first() const; //first element from in order traversal

    TreeNode<ValueType>* root;
    int size;

//    // creds to https://stackoverflow.com/a/12684238/8208107 for tree iterator template
//    struct TreeIterator {
//      TreeIterator(TreeNode<ValueType>* curr) : curr(curr) { }
//      TreeIterator &operator++(); //pre inc
//      TreeIterator operator++(int); //post inc
//      bool operator==(const TreeIterator &) const;

//      private:
//        TreeNode<ValueType> *curr;
//    };

//    TreeIterator begin() { return this->first(); }
//    TreeIterator end() { return nullptr; }

private:
    void add_helper(const ValueType& value, TreeNode<ValueType>* curr);
    void clear_helper(TreeNode<ValueType>* curr);
    bool contains_helper(const ValueType& value, TreeNode<ValueType>* curr) const;
    void remove_helper(const ValueType& value, TreeNode<ValueType>* curr, TreeNode<ValueType>* prev);
    TreeNode<ValueType>* get_helper(const ValueType& value, TreeNode<ValueType>* curr) const;
//    void size_helper(TreeNode<ValueType>* curr, int& count);
    void toStringInOrder_helper(TreeNode<ValueType>* curr, std::string& res) const;
    bool equals_helper(TreeNode<ValueType>* other, TreeNode<ValueType> *me, bool subsetOf = false) const;
};

#include "tree.inl"

#endif // TREE_H
