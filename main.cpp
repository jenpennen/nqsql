#include "queryparser.cpp"
#include <iostream>

int main() {
    QueryParser parser1("John Doe 'New York' 10027");
    std::string field = "";
    while (parser1.getNextField(field))
    {
        std::cout << field << " next ";
    }
}