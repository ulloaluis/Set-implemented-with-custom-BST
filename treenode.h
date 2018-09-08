#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <ostream>

using std::ostream;

template <typename ValueType>
class TreeNode {
public:
    TreeNode(const ValueType& value);

    //public so we don't need getters
    TreeNode<ValueType>* left;
    TreeNode<ValueType>* right;
    ValueType value;
};

template <typename ValueType>
bool operator <(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2);

template <typename ValueType>
bool operator <=(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2);

template <typename ValueType>
bool operator ==(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2);

template <typename ValueType>
bool operator !=(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2);

template <typename ValueType>
bool operator >(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2);

template <typename ValueType>
bool operator >=(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2);

template <typename ValueType>
ostream& operator <<(ostream& out, const TreeNode<ValueType>& node);


#include "treenode.inl"

#endif // TREENODE_H
