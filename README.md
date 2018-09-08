# Set-implemented-with-custom-BST
(in prog) Set collection class implemented with a binary search tree in C++


Will eventually support the collection of methods found in the Stanford C++ library found here: https://stanford.edu/~stepp/cppdoc/Set-class.html. The Set library was used in the class CS 106B (https://web.stanford.edu/class/cs106b/), and this repository is an attempt to recreate the class from the ground up. The binary search tree functionality is also written and included in this repository as a separate class (i.e., this project does not utilize std::map's red-black tree). 

*Disclaimer*: I don't have professional experience with C++ or thorough and efficient collection class design (and have not taken an algorithms class), so this code is not production-quality. This is an ongoing personal project for learning more of C++'s features and refreshing on prior knowledge (BSTs && C++). 



### TODO: 
1) **important:** Iterators
    1a) Implement support for iterators that are compatible with the STL libraries.
    1b) Re-implement equals(), isSubsetOf(), and other methods that can be improved (efficiency wise) with iterators.
2) Implement the remaining operators defined in the Stanford Set library.
3) Additional functionality beyond that listed in the documentation.
