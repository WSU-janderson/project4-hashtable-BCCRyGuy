/**
 * HashTable.cpp
 * Rylan Cheetham
 */

#include "HashTable.h"

// default constructor with given capacity and 0 elements
HashTable::HashTable(size_t initCapacity) : tableData(initCapacity), numElements(0) {
    // fill offsets with 1, 2, ... , N-1
    for (size_t i = 1; i < initCapacity; i++) {
        offsets.push_back(i);
    }

    // shuffle offsets
    for (size_t i = 0; i < offsets.size(); i++) {
        // arbitrary fixed formula for swaping
        size_t j = (i * 7 + 1) % offsets.size();
        std::swap(offsets[i], offsets[j]);
    }
}

bool HashTable::insert(const std::string &key, const size_t &value) {
    // if table is full, resize before inserting
    if (alpha() >= 0.5) {
        resize();
    }


    size_t maxBuckets = tableData.size();
    size_t homeIndex = std::hash<std::string>()(key) % maxBuckets;

    // check if home bucket is empty
    if (tableData[homeIndex].isEmpty()) {
        tableData[homeIndex].load(key, value);
        numElements++;
        return true;
    }

    // check for duplicate at home
    if (tableData[homeIndex].getKey() == key) {
        return false;
    }

    // probe using offset sequence
    for (size_t offset : offsets) {
        size_t bucketIndex = (homeIndex + offset) % maxBuckets;

        // check if empty
        if (tableData[bucketIndex].isEmpty()) {
            tableData[bucketIndex].load(key, value);
            numElements++;
            return true;
        }

        // check for duplicate
        if (tableData[bucketIndex].getKey() == key) {
            return false;
        }
    }



    // table full or slot not found
    return false;
}

bool HashTable::remove(const std::string &key) {
    size_t maxBuckets = tableData.size();
    size_t homeIndex = std::hash<std::string>()(key) % maxBuckets;

    // check home bucket
    if (tableData[homeIndex].getKey() == key) {
        tableData[homeIndex].setEmptyAfterRemove();
        numElements--;
        return true;
    }

    // probe through offsets
    for (size_t offset : offsets) {
        size_t bucketIndex = (homeIndex + offset) % maxBuckets;

        // stop early if hitting ESS
        if (tableData[bucketIndex].isEmptySinceStart()) {
            return false;
        }

        // key found
        if (tableData[bucketIndex].getKey() == key) {
            tableData[bucketIndex].setEmptyAfterRemove();
            numElements--;
            return true;
        }
    }

    // not found
    return false;
}

bool HashTable::contains(const std::string &key) const {
    size_t maxBuckets = tableData.size();
    size_t homeIndex = std::hash<std::string>()(key) % maxBuckets;

    // check home bucket first
    if (tableData[homeIndex].getKey() == key) {
        return true;
    }

    // probe through offsets
    for (size_t offset : offsets) {
        size_t bucketIndex = (homeIndex + offset) % maxBuckets;

        // stop early if ESS bucket is reached
        if (tableData[bucketIndex].isEmpty()) {
            return false;
        }

        // if key is found
        if (tableData[bucketIndex].getKey() == key) {
            return true;
        }

    }
    // key is not found
    return false;
}

std::optional<size_t> HashTable::get(const std::string &key) const {
    size_t maxBuckets = tableData.size();
    size_t homeIndex = std::hash<std::string>()(key) % maxBuckets;

    // check home bucket
    if (tableData[homeIndex].getKey() == key) {
        return tableData[homeIndex].getValue();
    }

    // probe through offsets
    for (size_t offset : offsets) {
        size_t bucketIndex = (homeIndex + offset) % maxBuckets;

        // stop probing when hitting ESS bucket
        if (tableData[bucketIndex].isEmptySinceStart()) {
            return std::nullopt;
        }

        // get the value stored in the bucket
        if (tableData[bucketIndex].getKey() == key) {
            return tableData[bucketIndex].getValue();
        }
    }

    // not found
    return std::nullopt;
}

size_t & HashTable::operator[](const std::string &key) {
    size_t maxBuckets = tableData.size();
    size_t homeIndex = std::hash<std::string>()(key) % maxBuckets;

    // check home bucket
    if (tableData[homeIndex].getKey() == key) {
        return tableData[homeIndex].valueReference();
    }

    // probe through offsets
    for (size_t offset : offsets) {
        size_t bucketIndex = (homeIndex + offset) % maxBuckets;
        if (tableData[bucketIndex].getKey() == key) {
            return tableData[bucketIndex].valueReference();
        }
    }

    // key not found return nothing
}

std::vector<std::string> HashTable::keys() const {
    // vector to store keys
    std::vector<std::string> keys;
    keys.reserve(numElements);

    // check all buckets for keys
    for (const HashTableBucket& bucket : tableData) {
        // only include buckets with NORMAL type
        if (!bucket.isEmpty()) {
            // store key in vector
            keys.push_back(bucket.getKey());
        }
    }

    // return the vector with all keys
    return keys;
}

double HashTable::alpha() const {
    return static_cast<double>(numElements) / (tableData.size());
}

size_t HashTable::capacity() const {
    return tableData.size();
}

size_t HashTable::size() const {
    return numElements;
}

// simply double the size of the table if it is full
void HashTable::resize() {
    size_t oldCapacity = tableData.size();
    size_t newCapacity = oldCapacity * 2;

    // save old table
    std::vector<HashTableBucket> oldTable = tableData;

    // Resize tableData with empty buckets
    tableData.clear();
    tableData.resize(newCapacity);

    // reset number of elements temporarily
    numElements = 0;

    // Recreate offsets for new capacity
    offsets.clear();
    for (size_t i = 1; i < newCapacity; i++) {
        offsets.push_back(i);
    }
    // Shuffle offsets (same deterministic formula)
    for (size_t i = 0; i < offsets.size(); i++) {
        size_t j = (i * 7 + 1) % offsets.size();
        std::swap(offsets[i], offsets[j]);
    }

    // Reinsert old key-value pairs into new table
    for (const auto& bucket : oldTable) {
        if (!bucket.isEmpty()) {
            insert(bucket.getKey(), bucket.getValue());
        }
    }
}

