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

    // load key value into bucket and mark as NORMAL
    void load(const std::string& key, const size_t& value);

    // check if empty (ESS or EAR)
    bool isEmpty() const;
    /**
    * The stream insertion operator could be overloaded to print the
    * bucket's contents. Or if preferred, you could write a print method
    * instead.
    */
    friend std::ostream& operator<<(std::ostream& os, const HashTableBucket& bucket);

    private:
    std::string key;
    size_t value;
    BucketType type;
};


#endif //HASHTABLE_HASHTABLEBUCKET_H