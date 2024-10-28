#include "Table.h"
#include<stdexcept>
#include<cstdlib>
#include<vector>
#include<string>


Table::Table(std::string keyColumn, const std::vector<std::string>& columns){
    // throw exception of key column or columns is empty
    if (columns.empty() || keyColumn.empty()) // Check for empty keyColumn or empty columns vector
        throw std::invalid_argument("Key column or columns cannot be empty");

    this->keyColumn = keyColumn;
    columnHeaders = columns;  

    bool keyFound = false;
    for (int i = 0; i < columnHeaders.size(); i++){
        //check for empty column names
        if (columnHeaders[i].empty()){
            throw std::invalid_argument("Column names cannot be empty.");
        }
        //check if column matches key column
        if (columnHeaders[i] == keyColumn) {
            // if key if found for the first time
            if(!keyFound){
                keyFound = true;
                keyColumnNumber = i + 1;
            }
            else{ // if key is found more than once
                throw std::invalid_argument("Key column appears multiple times in the columns list");
            }
        }
        }
        //if key column is missing from list
        if (!keyFound)
            throw std::invalid_argument("Key column is not found in the columns list.");
        totalColumns = columns.size();
        // std::cout << totalColumns << std::endl;
    
}