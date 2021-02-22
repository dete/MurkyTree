//
//  main.cpp
//  MurkyTree
//
//  Created by Dieter Shirley on 2021-02-21.
//

#include <cstdio>

#include "MurkyTree.hpp"

int main(int argc, const char * argv[]) {
    
    
    MurkyTree t;
    
    t.DEBUG_print();
    
    for (int i = 0; i < 256; i++) {
        t.insert(HashKey::randomHash(), i);
        t.DEBUG_print();
    }
    
    return 0;
}
