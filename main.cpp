#include "queryparser.cpp"
#include <iostream>

void runTestCase(const std::string& input){
    QueryParser parser(input);
    std::string field = "";
    while(parser.getNextField(field)){
        std::cout << field << " next ";
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
        runTestCase(testCase);
    }
    return 0;

}