#include "treenode.h"

template <typename ValueType>
inline TreeNode<ValueType>::TreeNode(const ValueType& value) {
    this->left = nullptr;
    this->right = nullptr;
    this->value = value;
}

template <typename ValueType>
inline bool operator <(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2) {
    return node1.value < node2.value;
}

template <typename ValueType>
inline bool operator <=(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2) {
    return node1.value <= node2.value;
}

template <typename ValueType>
inline bool operator ==(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2) {
    return node1.value == node2.value;
}

template <typename ValueType>
inline bool operator !=(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2) {
    return node1.value != node2.value;
}

template <typename ValueType>
inline bool operator >(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2) {
    return node1.value > node2.value;
}

template <typename ValueType>
inline bool operator >=(const TreeNode<ValueType>& node1, const TreeNode<ValueType>& node2) {
    return node1.value >= node2.value;
}

template <typename ValueType>
inline ostream& operator <<(ostream& out, const TreeNode<ValueType>& node) {
    out << node.value;
    return out;
}
