#include <iostream>
#include "set.h"

using namespace std;

std::string to_bool(int x) {
    return x == 1 ? "True" : "False";
}

void equals_1() {
    cout << "-------------- Equals 1 test --------------" << endl;
    Set<int> myset;
    myset.add(5);
    myset.add(3);
    myset.add(1);
    myset.add(0);
    myset.add(7);
    myset.add(2);
    cout << to_bool(myset.contains(5)) << endl;
    myset.add(7);
    myset.add(2);
    myset.add(1);
    cout << myset << endl;
    cout << myset.size() << endl;

    Set<int> oset;
    oset.add(5);
    oset.add(3);
    oset.add(1);
    oset.add(0);
    oset.add(7);
    oset.add(2);
    cout << to_bool(oset.contains(5)) << endl;
    oset.add(7);
    oset.add(2);
    oset.add(1);
    cout << oset << endl;
    cout << oset.size() << endl;

    cout << "equal? " << to_bool(oset.equals(myset)) << endl;
}

void equals_2() {
    cout << "-------------- Equals 2 test --------------" << endl;
    Set<int> myset;
    myset.add(1);
    myset.add(3);
    myset.add(5);
    myset.add(2);
    cout << myset << endl;

    Set<int> oset;
    oset.add(1);
    oset.add(3);
    oset.add(5);
    oset.add(2);
    cout << oset << endl;

    cout << "equal? " << to_bool(oset.equals(myset)) << endl;
}

void equals_3() {
    cout << "-------------- Equals 3 test --------------" << endl;
    Set<int> myset;
    myset.add(1);
    myset.add(3);
    myset.add(5);
    myset.add(0);
    cout << myset << endl;

    Set<int> oset;
    oset.add(1);
    oset.add(3);
    oset.add(5);
    oset.add(2);
    cout << oset << endl;

    cout << "equal? " << to_bool(oset.equals(myset)) << endl;

    Set<int> a = {1, 2, 3};
    Set<int> b = {1, 2, 3, 4, 5};
    Set<int> c = {1, 2, 3};

    cout << a << endl << b << endl;
    cout << "equal? " << to_bool(a == b) << endl;

    cout << a << endl << c << endl;
    cout << "equal? " << to_bool(a == c) << endl;
}

void equals_4() {
    cout << "-------------- Equals 4 test --------------" << endl;
    Set<int> set1 = {1, 2, 3, 4, 5};
    Set<int> set2 = {5, 4, 1, 2, 3};
    cout << set1 << endl << set2 << endl;
    cout << "equal? " << to_bool(set1.equals(set2)) << endl << endl; //true

    Set<int> set3 = {};
    Set<int> set4 = {};
    cout << set3 << endl << set4 << endl;
    cout << "equal? " << to_bool(set3.equals(set4)) << endl << endl; //true

    Set<int> set5 = {9, 9, 9, 9, 8};
    Set<int> set6 = {8, 9};
    cout << set5 << endl << set6 << endl;
    cout << "equal? " << to_bool(set5.equals(set6)) << endl << endl; //true

    Set<int> set7 = {1, 2, 3};
    Set<int> set8 = {};
    cout << set7 << endl << set8 << endl;
    cout << "equal? " << to_bool(set7.equals(set8)) << endl; //false
}

void initializer_tests() {
    cout << "-------------- Testing Initializer List --------------" << endl;
    Set<int> set1 = {1, 2, 3, 4, 5};
    cout << set1 << endl;

    Set<int> set2 = {4, 2, 1, 9, 7};
    cout << set2 << endl;

    Set<int> set3 = {4, 2, 1, 9, 7, 0, -13, -132, 2123123, 231, 3213, 123, 935};
    cout << set3 << endl;

}

void subsets() {
    cout << "-------------- Subsets --------------" << endl;
    Set<int> a = {1, 2};
    Set<int> b = {1, 2, 3};
    cout << a << " subset of " << b << " " << to_bool(a.isSubsetOf(b)) << endl;

    Set<int> c = {1, 2, 123};
    Set<int> d = {1, 2, 3};
    cout << c << " subset of " << d << " " << to_bool(c.isSubsetOf(d)) << endl;

    Set<int> e = {9, 1, 4, 6, 2};
    Set<int> f = {1, 2, 4, 6, 9};
    cout << e << " subset of " << f << " " << to_bool(e.isSubsetOf(f)) << endl;

    Set<int> g = {9, 1, 8, 0, 2, 3, 6, 5, 7, 4};
    Set<int> h = {0, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9};
    cout << g << " subset of " << h << " " << to_bool(g.isSubsetOf(h)) << endl;

}

void firsts() {
    Set<int> x = {1, 2, 3};
    cout << x.first() << endl;
    Set<int> y = {9, 8, 7, 5, 1};
    cout << y.first() << endl;
    Set<int> z = {6, 7, 6, 4, 3, 8};
    cout << z.first() << endl;
    Set<int> a = {3, 2, 4, 5};
    cout << a.first() << endl;
    // 1 1 3 2
}


/*
 * TODO:
 * 1) Implement iterator functionality
 * 2) Update equals, subset, and relevant functions to utilize iterator
 *      functionality and overall improve efficiency.
 *
 */
int main() {
    equals_1(); //true
    equals_2(); //true
    equals_3(); //false
    equals_4();
    initializer_tests(); //inorder, no dups, etc - {a1, a2, .., an} syntax
    subsets();
    firsts();


    return 0;
}
