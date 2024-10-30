#include "QueryParser.cpp"
#include "Table.cpp"
#include "Table.h"
#include <iostream>
#include <cassert>

void testQuery(const std::string& input){
    QueryParser parser(input);
    std::string field = "";
    while(parser.getNextField(field)){
        std::cout << field << " next ";
    }
    std::cout << std::endl;
}
void testTable(const std::string& keyColumn, const std::vector<std::string>& columns) {
    Table table(keyColumn, columns);
    std::cout << "Created Table with key column: " << keyColumn << " with columns: ";
    for (const auto& col : columns) {
        std::cout << col << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<std::string> testCases = {
        "John Doe Columbia 10027",
        "John Doe 'New York' 10027",
        "Jane Smith 'Los Angeles' 90024"
    };

    for (const auto& testCase:testCases) {
        testQuery(testCase);
    }

    std::vector<std::pair<std::string, std::vector<std::string>>> tableCases = {
        {"hi", {"hi", "col2"}},
        {"name", {"firstName", "name", "age"}},
        {"id", {"country", "city", "zipcode", "id"}}
    };
    for (const auto& tableCase:tableCases) {
        testTable(tableCase.first, tableCase.second);
    }

    try {
        Table table("col1", {"col1", "col2"});
        table.insert("one two");

    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid input error: " << e.what() << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    }

    Hashmap hashmap;
    std::vector<std::string> record1 = {"Alice 23 Engineer"};
    std::vector<std::string> record2 = {"Emily 23 Engineer"};
    std::vector<std::string> record3 = {"Janice 23 Engineer"};

    assert(hashmap.insert("Alice", record1));
    assert(hashmap.insert("Emily", record2));
    assert(hashmap.insert("Janice", record3));
    std::cout << "PASSED" << std::endl;

    return 0;

}