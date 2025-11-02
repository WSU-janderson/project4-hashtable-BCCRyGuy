/**
 * HashTableBucket.h
 * Rylan Cheetham
 */

#ifndef HASHTABLE_HASHTABLEBUCKET_H
#define HASHTABLE_HASHTABLEBUCKET_H

#include <string>
#include <iostream>

enum class BucketType {NORMAL, ESS, EAR};

class HashTableBucket {
    public:
    // default constructor
    HashTableBucket();
    // parameterized constructor
    HashTableBucket(const std::string& key, const size_t& value);
    /**
    * A load method could load the key-value pair into the bucket, which
    * should then also mark the bucket as NORMAL.
    */
    void load(const std::string& key, const size_t& value);
    /**
    * This method would return whether the bucket is empty, regardless of
    * if it has had data placed in it or not.
    */
    bool isEmpty() const;
    /**
    * The stream insertion operator could be overloaded to print the
    * bucket's contents. Or if preferred, you could write a print method
    * instead.
    */
    friend std::ostream& operator<<(std::ostream& os, const HashTableBucket& bucket);
};


#endif //HASHTABLE_HASHTABLEBUCKET_H