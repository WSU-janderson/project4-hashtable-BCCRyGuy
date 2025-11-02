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

