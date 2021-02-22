//
//  node.hpp
//  MurkyTree
//
//  Created by Dieter Shirley on 2021-02-21.
//

#ifndef Node_hpp
#define Node_hpp

#include "Leaf.hpp"

enum ChildType {
    NoChild,
    NodeChild,
    LeafChild
};

class Node {
public:
    Node() {
        _children[0] = NULL;
        _children[1] = NULL;
        _childrenType[0] = NoChild;
        _childrenType[1] = NoChild;
    }

    bool find(const HashKey& key, uint64_t& value, int depth) const;

    void insert(const HashKey& key, uint64_t value, int depth);
    void remove(const HashKey& key, int depth);
    
    void DEBUG_print() const;
    
private:
    Node* createNodeForLeaves(Leaf* leafA, Leaf* leafB, int depth);
    
    void* _children[2];
    ChildType _childrenType[2];
};

#endif /* Node_hpp */
