//
//  Leaf.hpp
//  MurkyTree
//
//  Created by Dieter Shirley on 2021-02-21.
//

#ifndef Leaf_hpp
#define Leaf_hpp

#include "HashKey.hpp"

class Leaf {
public:
    Leaf(const HashKey& key, uint64_t value): _key(key), _value(value) {}
    
    const HashKey& key() const { return _key; }
    uint64_t value() const { return _value; }
    
    void updateValue(uint64_t newValue) { _value = newValue; }

private:
    HashKey _key;
    uint64_t _value;
};

#endif /* Leaf_hpp */
