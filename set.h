#ifndef SET_H
#define SET_H

#include <string>
#include <ostream>
#include <initializer_list>  //for additional constructor
#include "tree.h"
#include "treenode.h"

using std::ostream;

template <typename ValueType>
class Set {
public:
    Set();
    Set(std::initializer_list<ValueType> items);
    ~Set();

    void add(const ValueType& value);
    void remove(const ValueType& value);
    bool contains(const ValueType& value) const;
    void clear();
    int size() const;
    bool isEmpty();
    std::string toString() const;
    bool equals(const Set<ValueType>& other) const;
    bool isSubsetOf(const Set<ValueType>& other) const;
    ValueType first();

    Tree<ValueType>* tree;
};

template <typename ValueType>
inline ostream& operator <<(ostream& out, const Set<ValueType>& items);

template <typename ValueType>
inline bool operator ==(const Set<ValueType>& set1, const Set<ValueType>& set2);

template <typename ValueType>
inline bool operator !=(const Set<ValueType>& set1, const Set<ValueType>& set2);


#include "set.inl"

#endif // SET_H
