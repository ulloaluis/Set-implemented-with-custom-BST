# Set-implemented-with-custom-BST
(in prog) Set collection class implemented with a binary search tree in C++


Will eventually support the collection of methods found in the Stanford C++ library found here: https://stanford.edu/~stepp/cppdoc/Set-class.html. The Set library was used in the class CS 106B (https://web.stanford.edu/class/cs106b/), and this repository is an attempt to recreate the class from the ground up. The binary search tree functionality is also written and included in this repository as a separate class (i.e., this project does not utilize std::map's red-black tree). 

*Disclaimer*: I don't have professional experience with C++ or thorough and efficient collection class design (and have not taken an algorithms class), so this code is not production-quality. This is an ongoing personal project for learning more of C++'s features and refreshing on prior knowledge (BSTs && C++). 


Quirks:
- The collection class is technically all defined in the header file. An inline (.inl) file is used to include the functionality of each method mentioned in the class definition. This was done since the classes are templatized (using cpp file would cause a Linker Error) and since templates eventually generate code, the compiler requires the definitions to be in the header file (there are other ways around this, but I found inline functions to be the easiest to understand).
- Set stores a Tree object instead of the root of a tree. This leads to the majority of the code being written in the Tree class (and Set simply calls the same-name method from Tree). This is why I opted to use so many of the namespace identifiers instead of using the "using" keyword (also because I like how the identifiers look style-wise). It is also why the tree object is exposed (public). A revamp would likely remove the abstraction of the Tree class and instead work directly with a Node struct.


### TODO: 
1) **important:** Iterators
    1a) Implement support for iterators that are compatible with the STL libraries.
    1b) Re-implement equals(), isSubsetOf(), and other methods that can be improved (efficiency wise) with iterators.
2) Implement the remaining operators defined in the Stanford Set library.
3) Additional functionality beyond that listed in the documentation.
