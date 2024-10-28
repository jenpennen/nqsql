#include<cstdlib>
#include<iostream>
// parse fields from a query string, separating them by whitespace
class QueryParser
{
public:
    QueryParser(std::string text = ""): m_text(text), m_start(0) {}
    
    void setString(std::string text){
        m_text = text;
        m_start = 0;
    }

    //retrieve the next field from the input string
    bool getNextField(std::string& fieldText)
    {   
        //find the next non-whitespace character
        m_start = m_text.find_first_not_of(" \t\r\n", m_start);

        // if no more non-white space characters, clear fieldText and return false
        if(m_start == std::string::npos){
            fieldText.clear();
            return false;
        }

        // if the current character is not a quote, parse a regular field
        if(m_text[m_start] != '\''){
            size_t end = m_text.find_first_of(" \t\r\n", m_start);
            fieldText = m_text.substr(m_start, end - m_start);
            m_start = (end == std::string::npos) ? m_text.size() : end;
            return true; // retrieved a non-quoted field
        }

        return false;
    }
private:
    std::string m_text;
    size_t m_start;
};
//END OF STRING PARSER
