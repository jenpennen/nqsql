#ifndef TABLE_H
#define TABLE_H

#include<iostream>
#include<vector>
#include<list>
#include <memory>

// key-value pair to store in the hash map
struct KeyValuePair {
    std::string key;
    std::vector<std::string> rowValues;

    KeyValuePair(std::string k, std::vector<std::string> values) 
        : key(std::move(k)), rowValues(std::move(values)) {}
};

// hash map node with a chain for handling collisions
struct HashmapNode {
    std::list<KeyValuePair> chain; // to handle collisions
};

class Hashmap {
public:
    Hashmap(): buckets(1000), data(new HashmapNode [buckets]()){}

    bool insert(const std::string& key, const std::vector<std::string>& recordString) {
        int index = hashFunction(key);
        // insert the new key-value pair into the chain
        data[index].chain.emplace_back(key, recordString);
        return true;
    }

private:
    int buckets;
    std::unique_ptr<HashmapNode[]> data; // unique pointer to an array of HashmapNode objects
    // basic has function summing ascii value of record string
    int hashFunction(const std::string& key) const {
        int sum = 0;
        for (char ch: key) {
            sum += static_cast<int>(ch);
        }
        return sum % buckets;
    }


    
};

class Table {
public:
    Table(std::string keyColumn, const std::vector<std::string>& columns);
    ~Table() {};
    void insert(const std::string& recordString);
    void find(std::string key, std::vector<std::vector<std::string>>& records) const {};
    // Table(const Table&) = delete;
    // Table& operator=(const Table&) = delete;
private:
    std::string keyColumn;
    std::vector<std::string> columnHeaders;
    int keyColumnNumber;
    int totalColumns;
};
#endif