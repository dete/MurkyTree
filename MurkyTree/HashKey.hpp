//
//  HashKey.hpp
//  MurkyTree
//
//  Created by Dieter Shirley on 2021-02-21.
//

#ifndef HashKey_hpp
#define HashKey_hpp

#include <cstdlib>
#include <cstdio>

class HashKey {
public:
    HashKey() {
        _hash[0] = 0;
        _hash[1] = 0;
        _hash[2] = 0;
        _hash[3] = 0;
    }
    
    HashKey(uint64_t hash[4]) {
        _hash[0] = hash[0];
        _hash[1] = hash[1];
        _hash[2] = hash[2];
        _hash[3] = hash[3];
    }
    
    HashKey(const HashKey& other) {
        *this = other;
    }
    
    HashKey(int seed): HashKey() {
        _hash[0] = seed;
    }
    
    static HashKey randomHash() {
        uint64_t buffer[4];
        
        arc4random_buf(buffer, sizeof(buffer));

        return HashKey(buffer);
    }
    
    const char* toString() const {
        static char evilCharacterBuffer[67];
        
        sprintf(evilCharacterBuffer, "0x%016llx%016llx%016llx%016llx", _hash[0], _hash[1], _hash[2], _hash[3]);
        
        return evilCharacterBuffer;
    }
    
    const char* toMap() const {
        static char evilCharacterBuffer[256];
        
        for (int i=0; i < 256; i++) {
            evilCharacterBuffer[i] = bitValue(i) ? '+' : '.';
        }
        
        return evilCharacterBuffer;
    }
    
    void operator=(const HashKey& other) {
        _hash[0] = other._hash[0];
        _hash[1] = other._hash[1];
        _hash[2] = other._hash[2];
        _hash[3] = other._hash[3];
    }
    
    bool operator==(const HashKey& other) const {
        return ((_hash[0] == other._hash[0]) &&
                (_hash[1] == other._hash[1]) &&
                (_hash[2] == other._hash[2]) &&
                (_hash[3] == other._hash[3]));
    }
    
    int bitValue(int bitIndex) const { return (_hash[bitIndex / 64] >> (bitIndex % 64)) & 1; }

private:
    uint64_t _hash[4];
};

#endif /* HashKey_hpp */
