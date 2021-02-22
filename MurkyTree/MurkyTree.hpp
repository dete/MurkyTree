//
//  MurkyTree.hpp
//  MurkyTree
//
//  Created by Dieter Shirley on 2021-02-21.
//

#ifndef MurkyTree_hpp
#define MurkyTree_hpp

#include "Node.hpp"

class MurkyTree {
public:
    MurkyTree() { rootNode = new Node();}
    
    bool find(const HashKey& key, uint64_t& value) const {
        return rootNode->find(key, value, 0);
    }

    void insert(const HashKey& key, uint64_t value) {
        rootNode->insert(key, value, 0);
    }

    void remove(const HashKey& key) {
        rootNode->remove(key, 0);
    }
    
    void DEBUG_print() const {
        rootNode->DEBUG_print();
        printf("\n");
    }

    
private:
    Node* rootNode;
};

#endif /* MurkyTree_hpp */
