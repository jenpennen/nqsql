#pragma once
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
            // update m_start for the next search, handling end case
            m_start = (end == std::string::npos) ? m_text.size() : end;
            return true; // retrieved a non-quoted field
        }

        // if the field starts with quote, parse quoted field
        return parseQuotedField(fieldText);
    }
private:
    std::string m_text;
    size_t m_start;

    bool parseQuotedField(std::string& fieldText) {
        fieldText.clear(); // clear field output

        while(true){
            // move past initial quote
            m_start++;
            //find next quote quote
            size_t end = m_text.find('\'', m_start);
            fieldText += m_text.substr(m_start, end - m_start);
            m_start = (end != std::string::npos) ? end + 1: m_text.size();
        
            //break if we reach the end of the string or next character is not a quote
            if (m_start == m_text.size() || m_text[m_start] != '\'') {
                break;
            }
            fieldText += '\''; //handle escaped quote by adding it to the field text
        }
        return true;
    }
};
//END OF STRING PARSER
