/**
 * HashTable.cpp
 * Rylan Cheetham
 */

#include "HashTable.h"

// default constructor with given capacity and 0 elements
HashTable::HashTable(size_t initCapacity) : tableData(initCapacity), numElements(0) {
    // fill ofsets with 1, 2, ... , N-1
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
    size_t maxBuckets = tableData.size();
    size_t homeIndex = std::hash<std::string>()(key) % maxBuckets;

    // check if home bucket is empty
    if (tableData[homeIndex].isEmpty()) {
        tableData[homeIndex].load(key, value);
        numElements++;
        return true;
    }

    // check for duplicate at home
    if (!tableData[homeIndex].isEmpty() && tableData[homeIndex].getKey() == key) {
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

    // (temporary) Table full
    return false;
}

bool HashTable::remove(const std::string &key) {

}

bool HashTable::contains(const std::string &key) const {

}

std::optional<size_t> HashTable::get(const std::string &key) const {

}

size_t & HashTable::operator[](const std::string &key) {

}

std::vector<std::string> HashTable::keys() const {

}

double HashTable::alpha() const {

}

size_t HashTable::capacity() const {

}

size_t HashTable::size() const {

}

