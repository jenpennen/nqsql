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
void testHashmapInsertAndGet() {
    Hashmap hashmap;
    std::vector<std::string> record1 = {"Alice", "23", "Engineer"};
    std::vector<std::string> record2 = {"Bob", "30", "Doctor"};
    std::vector<std::string> record3 = {"Alice", "29", "Scientist"};

    // insert records with a unique key
    assert(hashmap.insert("Alice", record1));
    assert(hashmap.insert("Bob", record2));

    // insert a record with the same key to test chaining (collision handling)
    assert(hashmap.insert("Alice", record3));

    // retrieve records
    auto recordsAlice = hashmap.get("Alice");
    assert(recordsAlice.size() == 2);
    assert(recordsAlice[0] == record1);
    assert(recordsAlice[1] == record3);

    auto recordsBob = hashmap.get("Bob");
    assert(recordsBob.size() == 1);
    assert(recordsBob[0] == record2);

    auto recordsNonExistent = hashmap.get("NonExistentKey");
    assert(recordsNonExistent.empty());

    std::cout << "TEST HASHMAP INSERT AND GET PASSED\n";
}
void testHashmapRetrieveAllData() {
    Hashmap hashmap;
    std::vector<std::string> record1 = {"Alice", "23", "Engineer"};
    std::vector<std::string> record2 = {"Bob", "30", "Doctor"};
    std::vector<std::string> record3 = {"Charlie", "27", "Teacher"};

    // insert multiple records
    hashmap.insert("Alice", record1);
    hashmap.insert("Bob", record2);
    hashmap.insert("Charlie", record3);

    
    auto allData = hashmap.retrieveAllRecords();
    assert(allData.size() == 3);

    // Since the data isn't ordered, verify presence instead of order
    assert((allData[0] == record1 || allData[1] == record1 || allData[2] == record1));
    assert((allData[0] == record2 || allData[1] == record2 || allData[2] == record2));
    assert((allData[0] == record3 || allData[1] == record3 || allData[2] == record3));

    std::cout << "TEST HASHMAP RETRIEVE ALL DATA PASSED!\n";
}

// void testTableBadInsert() {
//     Table table("Name", {"Name", "Age", "Occupation"});

//     // insert invalid records
//     std::cout << "Here" <<std::endl;
//     assert(!table.insert("Alice,23"));  // Not enough fields
//     assert(!table.insert(",23,Engineer"));  // Missing key
//     assert(!table.insert("Alice,23,Engineer,Extra"));  // Too many fields

//     std::cout << "BAD INSERT TEST PASSED\n";
// }

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
    testHashmapRetrieveAllData();
    testHashmapInsertAndGet();
    // testTableBadInsert();

    return 0;

}