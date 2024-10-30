#ifndef TABLE_H
#define TABLE_H

#include<iostream>
#include<vector>

class Table
{
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