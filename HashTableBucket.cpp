/**
 * HashTableBucket.cpp
 * Rylan Cheetham
 */

#include "HashTableBucket.h"

// default constructor
HashTableBucket::HashTableBucket() : key("EMPTY_SINCE_START"), value(0), type(BucketType::ESS) {
}

// parameterized constructor
HashTableBucket::HashTableBucket(const std::string &k, const size_t &v) : key(k), value(v), type(BucketType::NORMAL) {

}

// load key value into bucket and mark as NORMAL
void HashTableBucket::load(const std::string &k, const size_t &v) {
    key = k;
    value = v;
    type = BucketType::NORMAL;
}

// check if empty (ESS or EAR)
bool HashTableBucket::isEmpty() const {
    return type != BucketType::NORMAL;
}

// check if ESS
bool HashTableBucket::isEmptySinceStart() const {
    return type == BucketType::ESS;
}

// check if EAR
bool HashTableBucket::isEmptyAfterRemove() const {
    return type == BucketType::EAR;
}

// overload operator<< for printing
std::ostream & operator<<(std::ostream &os, const HashTableBucket &bucket) {
    if (bucket.type == BucketType::NORMAL) {
        os << "Key: " << bucket.key << " Value: " << bucket.value << std::endl;
    } else if (bucket.type == BucketType::ESS) {
        os << "ESS" << std::endl;
    } else {
        os << "EAR" << std::endl;
    }
    return os;
}
