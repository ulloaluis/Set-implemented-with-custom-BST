#include "set.h"

/* Note that most of set's main functionality is found in Tree.
 * I only have this abstraction so I could use Tree for other projects.
 */

template <typename ValueType>
inline Set<ValueType>::Set() {
    tree = new Tree<ValueType>();
}

// use initializer list to initialize set, given arbitrary # of values
// syntax: Set<ValueType> varName = {a1, a2, ..., an};
template <typename ValueType>
inline Set<ValueType>::Set(std::initializer_list<ValueType> items) {
    tree = new Tree<ValueType>();
    for (auto it = items.begin(); it != items.end(); ++it) {
        tree->add(*it);
    }
}

template <typename ValueType>
inline Set<ValueType>::~Set() {
    tree->clear();
    //tree is garbage collected once all of its contents are deleted
}

template <typename ValueType>
inline void Set<ValueType>::add(const ValueType& value) {
    tree->add(value);
}

template <typename ValueType>
inline void Set<ValueType>::remove(const ValueType& value) {
    tree->remove(value);
}

template <typename ValueType>
inline bool Set<ValueType>::contains(const ValueType& value) const {
    return tree->contains(value);
}

template <typename ValueType>
inline void Set<ValueType>::clear() {
    tree->clear();
}

template <typename ValueType>
inline int Set<ValueType>::size() const {
    return tree->get_size();
}

template <typename ValueType>
inline bool Set<ValueType>::isEmpty() {
    return Set<ValueType>::size() == 0;
}


// will be valid if contents are the same, even if the internal tree structures are different
template <typename ValueType>
bool Set<ValueType>::equals(const Set<ValueType>& other) const {
    // sort of a hack, but still runs in big O(N) speed, size mismatch optimization
    if (Set<ValueType>::size() != other.size()) return false;
    return Set<ValueType>::toString() == other.toString();
    // technically O(2N), could do O(N) if I add a Tree iterator method and compare in one loop

    //could do this using iterators with slightly better efficiency
    // return tree->equals(other.tree);
}

// also a hack, need iterators
template <typename ValueType>
bool Set<ValueType>::isSubsetOf(const Set<ValueType>& other) const {
    std::string me = Set<ValueType>::toString();
    std::string them = other.toString();
    for (size_t i = 1; i < me.length()-1; i ++) { //skip { and }
        if (me[i] != them[i]) return false;
    }
    return true;

    // once iterators are implemented
    // return tree->equals(other.tree, true); //subsetOf flag turned on
}


template <typename ValueType>
inline std::string Set<ValueType>::toString() const{
    return tree->toStringInOrder();
}

template <typename ValueType>
inline ValueType Set<ValueType>::first() {
    return tree->first()->value;
}

template <typename ValueType>
inline ostream& operator <<(ostream& out, const Set<ValueType>& items) {
    out << items.toString();
    return out;
}

template <typename ValueType>
inline bool operator ==(const Set<ValueType>& set1, const Set<ValueType>& set2) {
    return set1.equals(set2);
}

template <typename ValueType>
inline bool operator !=(const Set<ValueType>& set1, const Set<ValueType>& set2) {
    return !set1.equals(set2);
}
