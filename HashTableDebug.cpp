/**
 * HashTableDebug.cpp
 * Rylan Cheetham
 * Write your tests in this file
 */
#include <iostream>
#include "HashTable.h"


int main() {
    // default capacity 8
    HashTable testTable;

    // insert key-value pairs
    testTable.insert("Rylan", 100);
    testTable.insert("Greg", 237);
    testTable.insert("Mumford", 891);

    // print buckets
    std::cout << "Current Table" << std::endl;
    for (size_t i = 0; i < testTable.capacity(); i++) {
        std::cout << "Bucket " << i << ": " << testTable.tableData[i];
    }

    std::cout << std::endl;
    std::cout << "Table Info" << std::endl;
    std::cout << "Size: " << testTable.size() << std::endl;
    std::cout << "Capacity: " << testTable.capacity() << std::endl;
    std::cout << "Alpha: " << testTable.alpha() << std::endl;


    return 0;
}