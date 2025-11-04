/**
 * HashTable.h
 * Rylan Cheetham
 * CS 3100
 * Project 4 Hash Table
 *
 * Declaration of HashTable class
 * uses basic operations: insert, remove, contains, get, etc.
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <optional>
#include <iostream>

#include "HashTableBucket.h"

class HashTable {
 public:

// core methods and functions

 // default constructor (default capacity 8)
 HashTable(size_t initCapacity = 8);

// insert new key-value pair. return true if successful, false on duplicate
 bool insert(const std::string& key, const size_t& value);

 // remove key-value pair if found. return true if removed, false otherwise
 bool remove(const std::string& key);

 // return true if key exists in table
 bool contains(const std::string& key) const;

 // return value for given key, or nullopt if not found
 std::optional<size_t> get(const std::string& key) const;

 // access key by reference, undefined if key DNE
 size_t& operator[](const std::string& key);

// return vector of all keys currently in table
std::vector<std::string> keys() const;

// returns load factor (size/capacity)
double alpha() const;

// return current capacity of table (number of buckets)
size_t capacity() const;

// return number of key-value pairs in table
size_t size() const;

 // stream output for printing
 friend std::ostream& operator<<(std::ostream& os, const HashTable& table);

private:
 // table data member
 std::vector<HashTableBucket> tableData;

 // vector for pseudo-random probing
 std::vector<size_t> offsets;

 // number of key-value pairs in table
 size_t numElements;

 // resize member function
 void resize();
};

#endif // HASHTABLE_H

