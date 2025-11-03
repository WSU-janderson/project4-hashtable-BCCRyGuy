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

    // test bracket operator function
    std::cout << "Rylan before update: " << testTable["Rylan"] << std::endl;
    testTable["Rylan"] = 999;
    std::cout << "Rylan after update: " << testTable["Rylan"] << std::endl;
    std::cout << std::endl;

    // print buckets
    std::cout << "Current Table" << std::endl;
    for (size_t i = 0; i < testTable.capacity(); i++) {
        // tabledata temporarily moved to public for test
        std::cout << "Bucket " << i << ": " << testTable.tableData[i];
    }

    std::cout << std::endl;
    std::cout << "Table Info" << std::endl;
    std::cout << "Size: " << testTable.size() << std::endl;
    std::cout << "Capacity: " << testTable.capacity() << std::endl;
    std::cout << "Alpha: " << testTable.alpha() << std::endl;

    // test get() function
    std::optional<size_t> val = testTable.get("Greg");
    if (val.has_value()) {
        std::cout << std::endl;
        std::cout << "Greg found: " << val.value() << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "Greg not found" << std::endl;
    }

    // test remove
    std::cout << std::endl;
    std::cout << "Removing Greg..." << std::endl;

    if (testTable.remove("Greg")) {
        std::cout << "Greg removed" << std::endl;
    } else {
        std::cout << "Failed to remove Greg" << std::endl;
    }

    // check get after remove
    val = testTable.get("Greg");
    if (val.has_value()) {
        std::cout << "Greg found after remove: " << val.value() << std::endl;
    } else {
        std::cout << "Greg not found after remove" << std::endl;
    }


    // insert new key to test EAR
    std::cout << std::endl;
    std::cout << "Inserting Cedric..." << std::endl;
    testTable.insert("Cedric", 555);


    // print final table
    std::cout << std::endl;
    std::cout << "Table after remove and insert:" << std::endl;
    for (size_t i = 0; i < testTable.capacity(); i++) {
        std::cout << "Bucket " << i << ": " << testTable.tableData[i];
    }

    return 0;
}