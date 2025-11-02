/**
 * HashTable.cpp
 * Rylan Cheetham
 */

#include "HashTable.h"

// default constructor with given capacity and 0 elements
HashTable::HashTable(size_t initCapacity) : tableData(initCapacity), numElements(0) {

}

bool HashTable::insert(const std::string &key, const size_t &value) {
    size_t maxBuckets = tableData.size();
    size_t homeIndex = std::hash<std::string>()(key) % maxBuckets;

    // check if first bucket is empty
    if (tableData[homeIndex].isEmpty()) {
        tableData[homeIndex].load(key, value);
        numElements++;
        return true;
    }

    // check for duplicate
    if (!tableData[homeIndex].isEmpty() && tableData[homeIndex].getKey() == key) {
        return false;
    }
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

