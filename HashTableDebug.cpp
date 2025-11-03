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
    std:: cout << "Buckets after insertion:" << std::endl;
    for (size_t i = 0; i < 8; i++ ) {
        // table data moved to public temporarily
        std::cout << "Bucket " << i << ": " << testTable.tableData[i];
    }
    return 0;
}