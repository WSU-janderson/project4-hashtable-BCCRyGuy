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
    size_t index = std::hash<std::string>()(key) % maxBuckets;

    for (size_t i = 0; i < maxBuckets; i++) {

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

