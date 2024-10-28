#include "queryparser.cpp"
#include <iostream>

int main() {
    QueryParser parser1("John Doe Columbia 10027"); // John next Doe next Columbia next 10027 next 
    std::string field = "";
    while (parser1.getNextField(field))
    {
        std::cout << field << " next ";
    }
    std::cout << std::endl;
    QueryParser parser2("John Doe 'New York' 10027"); // John next Doe next
    while (parser2.getNextField(field))
    {
        std::cout << field << " next ";
    }
}