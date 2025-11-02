/**
 * HashTableBucket.h
 * Rylan Cheetham
 */

#ifndef HASHTABLE_HASHTABLEBUCKET_H
#define HASHTABLE_HASHTABLEBUCKET_H

#include <string>
#include <iostream>

class HashTableBucket {
    /**
    * The default constructor can simply set the bucket type to ESS.
    *
    */
    HashTableBucket::HashTableBucket();
    /**
    * A parameterized constructor could initialize the key and value, as
    * well as set the bucket type to NORMAL.
    */
    HashTableBucket::HashTableBucket(const std::string& key, const size_t& value);
    /**
    * A load method could load the key-value pair into the bucket, which
    * should then also mark the bucket as NORMAL.
    */
    void HashTableBucket::load(const std::string& key, const size_t& value)
    /**
    * This method would return whether the bucket is empty, regardless of
    * if it has had data placed in it or not.
    */
    bool HashTableBucket::isEmpty() const
    /**
    * The stream insertion operator could be overloaded to print the
    * bucket's contents. Or if preferred, you could write a print method
    * instead.
    */
    friend ostream& operator<<(ostream& os, const HashTableBucket& bucket)
};


#endif //HASHTABLE_HASHTABLEBUCKET_H