//
//  Node.cpp
//  MurkyTree
//
//  Created by Dieter Shirley on 2021-02-21.
//

#include "Node.hpp"


bool Node::find(const HashKey& key, uint64_t& value, int depth) const {
    int whichChild = key.bitValue(depth);
    
    switch(_childrenType[whichChild]) {
        case NoChild:
            return false;

        case NodeChild:
        {
            Node* theChild = (Node*)_children[whichChild];
            return theChild->find(key, value, depth+1);
        }

        case LeafChild:
        {
            Leaf* theChild = (Leaf*)_children[whichChild];

            if (theChild->key() == key) {
                value = theChild->value();
                return true;
            }

            return false;
        }
    }
}

void Node::insert(const HashKey& key, uint64_t value, int depth) {
    int whichChild = key.bitValue(depth);
    
    switch(_childrenType[whichChild]) {
        case NoChild:
        {
            _children[whichChild] = new Leaf(key, value);
            _childrenType[whichChild] = LeafChild;
            break;
        }
        case NodeChild:
        {
            Node* theChild = (Node*)_children[whichChild];
            theChild->insert(key, value, depth+1);
            break;
        }
        case LeafChild:
        {
            Leaf* theChild = (Leaf*)_children[whichChild];

            if (theChild->key() == key) {
                theChild->updateValue(value);
            }
            else {
                _children[whichChild] = createNodeForLeaves(theChild, new Leaf(key, value), depth + 1);
                _childrenType[whichChild] = NodeChild;
            }
            break;
        }
    }
}

Node* Node::createNodeForLeaves(Leaf* leafA, Leaf* leafB, int depth) {
    int aSide = leafA->key().bitValue(depth);
    int bSide = leafB->key().bitValue(depth);

    Node* result = new Node();

    if (aSide == bSide) {
        result->_children[aSide] = createNodeForLeaves(leafA, leafB, depth+1);
        result->_childrenType[aSide] = NodeChild;
    } else {
        result->_children[aSide] = leafA;
        result->_childrenType[aSide] = LeafChild;
        result->_children[bSide] = leafB;
        result->_childrenType[bSide] = LeafChild;
    }
    
    return result;
}

void Node::remove(const HashKey& key, int depth) {
    
}

void Node::DEBUG_print() const {
    printf("(");
    
    switch(_childrenType[0]) {
        case NoChild:
            break;
        case NodeChild:
        {
            Node* theChild = (Node*)_children[0];
            theChild->DEBUG_print();
            break;
        }
        case LeafChild:
        {
            Leaf* theChild = (Leaf*)_children[0];
            printf("%lld", theChild->value());
            break;
        }
    }
    
    printf(", ");

    switch(_childrenType[1]) {
        case NoChild:
            break;
        case NodeChild:
        {
            Node* theChild = (Node*)_children[1];
            theChild->DEBUG_print();
            break;
        }
        case LeafChild:
        {
            Leaf* theChild = (Leaf*)_children[1];
            printf("%lld", theChild->value());
            break;
        }
    }
    
    printf(")");
}
