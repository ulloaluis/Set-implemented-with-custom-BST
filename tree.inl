#include "tree.h"

using std::cout;    using std::endl;

// pointer to root is passed in
template <typename ValueType>
inline Tree<ValueType>::Tree(TreeNode<ValueType>* root) {
    this->root = root;
    size = 0;
    if (root != nullptr) size += 1;
}

template <typename ValueType>
inline Tree<ValueType>::~Tree() {
    Tree<ValueType>::clear();
}

/*
 * Recursively deletes the entire tree in memory, though
 * user could technically pass a node in the tree to delete
 * just that portion of the tree.
 */
template <typename ValueType>
inline void Tree<ValueType>::clear(TreeNode<ValueType>* curr) {
    if (curr == nullptr) curr = root;
    Tree<ValueType>::clear_helper(curr);
    size = 0;
}

// go left, if null, go right, if also null im a leaf so delete me (postorder)
template <typename ValueType>
void Tree<ValueType>::clear_helper(TreeNode<ValueType>* curr) {
    if (curr->left != nullptr) Tree<ValueType>::clear_helper(curr->left);
    if (curr->right != nullptr) Tree<ValueType>::clear_helper(curr->right);
    delete curr;
}

template <typename ValueType>
inline void Tree<ValueType>::add(const ValueType& value) {
    Tree<ValueType>::add_helper(value, root);
}

// curr is a default variable that is used internally for recursive add
template <typename ValueType>
void Tree<ValueType>::add_helper(const ValueType& value, TreeNode<ValueType>* curr) {
    if (curr == nullptr) {
        root = new TreeNode<ValueType>(value);
        size += 1;
    } else {
        if (value > curr->value) {
            if (curr->right == nullptr) {
                curr->right = new TreeNode<ValueType>(value);
                size += 1;
            } else {
                Tree<ValueType>::add_helper(value, curr->right);
            }
        } else if (value < curr->value) {
            if (curr->left == nullptr) {
                curr->left = new TreeNode<ValueType>(value);
                size += 1;
            } else {
                Tree<ValueType>::add_helper(value, curr->left);
            }
        }
        // no duplicates, do nothing if set
    }
}

template <typename ValueType>
inline bool Tree<ValueType>::contains(const ValueType& value) const {
    return Tree<ValueType>::contains_helper(value, root); //cannot use root as default since it has to be known at compile time
}


template <typename ValueType>
bool Tree<ValueType>::contains_helper(const ValueType& value, TreeNode<ValueType>* curr) const {
    if (curr == nullptr) {
        return false;
    } else if (value == curr->value) {
        return true;
    } else {
        if (value > curr->value) {
            return Tree<ValueType>::contains_helper(value, curr->right);
        } else {
            return Tree<ValueType>::contains_helper(value, curr->left);
        }
    }
}


template <typename ValueType>
inline void Tree<ValueType>::remove(const ValueType& value) {
    Tree<ValueType>::remove_helper(value, root, nullptr);
}

/*
 * Remove cases to cover:
 * 1) Leaf: make node before point to nullptr
 * 2) Middle - Has parent and child(s)
 *  a) One child - make node before point to node after
 *  b) Two childs - make node before point to nullptr then add childs (lazy)
 *      b1) Have node before point to left child, left child's right is other child
*/
template <typename ValueType>
void Tree<ValueType>::remove_helper(const ValueType& value, TreeNode<ValueType>* curr, TreeNode<ValueType>* prev) {
    if (curr != nullptr) {  // value not found if curr == nullptr
        if (value == curr->value) {  //remove cases
            size -= 1;
            if (curr->left != nullptr) { // 2b
                if (prev == nullptr) { // removing root with 1 or 2 children
                    root = curr->left;
                } else if (prev->left == curr) {
                    prev->left = curr->left;
                } else { // right
                    prev->right = curr->left;
                }

                // in all cases, we add curr's right to curr left
                if (curr->right != nullptr) {
                    curr->left->right = curr->right;
                }
            } else if (curr->right != nullptr) { // 2a
                //if above is true, there is no curr left, so we don't have to check that
                if (prev == nullptr) {  //removing root with just right child
                    root = curr->right;
                } else if (prev->left == curr) {
                    prev->left = curr->right;
                } else { //prev right is curr
                    prev->right = curr->right;
                }
            } else {  //leaf, make prev point to nullptr in right direction (curr won't be nullptr)
                if (prev == nullptr) { // removing root
                    root = nullptr;
                } else if (prev->left == curr) {
                    prev->left = nullptr;
                } else { // else right is curr
                    prev->right = nullptr;
                }
            }
        } else if (value > curr->value){
            Tree<ValueType>::remove_helper(value, curr->right, curr);
        } else if (value < curr->value){
            Tree<ValueType>::remove_helper(value, curr->left, curr);
        }
    }
}

template <typename ValueType>
inline TreeNode<ValueType>* Tree<ValueType>::get(const ValueType& value) const {
    return Tree<ValueType>::get_helper(value, root);
}

template <typename ValueType>
TreeNode<ValueType>* Tree<ValueType>::get_helper(const ValueType& value, TreeNode<ValueType>* curr) const {
    if (curr == nullptr || value == curr->value) {
        return curr;  // nullptr if not found
    } else {
        if (value > curr->value) {
            return Tree<ValueType>::get_helper(value, curr->right);
        } else {
            return Tree<ValueType>::get_helper(value, curr->right);
        }
    }
}

template <typename ValueType>
inline int Tree<ValueType>::get_size() const {
    return size;
//    if (root == nullptr) return 0;
//    int count = 0;
//    Tree<ValueType>::size_helper(root, count);
//    return count;
}

//template <typename ValueType>
//void Tree<ValueType>::size_helper(TreeNode<ValueType>* curr, int& count) { // read with preorder traversal
//    count += 1;
//    if (curr->left != nullptr) Tree<ValueType>::size_helper(curr->left, count);
//    if (curr->right != nullptr) Tree<ValueType>::size_helper(curr->right, count);
//}

template <typename ValueType>
inline std::string Tree<ValueType>::toStringInOrder() const {
    if (root == nullptr) {
        return "Empty set";
    }
    std::string res = "{";
    Tree<ValueType>::toStringInOrder_helper(root, res);
    return res.substr(0, res.length()-2) + '}'; //removed extra ", " at end
}

template <typename ValueType>
void Tree<ValueType>::toStringInOrder_helper(TreeNode<ValueType>* curr, std::string& res) const {
    if (curr->left != nullptr) Tree<ValueType>::toStringInOrder_helper(curr->left, res);

    res += std::to_string(curr->value) + ", ";

    if (curr->right != nullptr) Tree<ValueType>::toStringInOrder_helper(curr->right, res);
}

template <typename ValueType>
bool Tree<ValueType>::equals(Tree<ValueType>* other, bool subsetOf) const { //subsetOf default false
    // optimizations/edge cases
    if (size != other->size) return false;
    if (size == 0) return true; //if first passes and size is 0, then both are 0.

    // issue: structures may differ. solution: use iterators
    return equals_helper(other->root, root, subsetOf);
}


/* Currently fails when the structures differ :( */
/* ********************************************* */

// Simultaneous in-order traversal, comparing nodes as we go
template <typename ValueType>
bool Tree<ValueType>::equals_helper(TreeNode<ValueType>* other, TreeNode<ValueType>* me, bool subsetOf) const {
    if (!other && !me) return true; // reached end together
    if (subsetOf && !other && me) return true; //other finished before me, is subset (note: other == me is already checked)
    if ((!other && me) || (other && !me)) return false; // did not reach end together

    return equals_helper(other->left, me->left, subsetOf); //traverse left
    if (other->value != me->value) return false; //compare values
    return equals_helper(other->right, me->right, subsetOf); //traverse right
}

//the leftmost element in bst
template <typename ValueType>
TreeNode<ValueType>* Tree<ValueType>::first() const { //default root
    if (size < 2) return root; //nullptr if empty, root if one

    TreeNode<ValueType>* curr = root;
    while (curr) {
        if (!curr->left) return curr;
        curr = curr->left;
    }
}





