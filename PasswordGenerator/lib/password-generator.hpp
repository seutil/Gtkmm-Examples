#pragma once
#include <string>
#include <vector>
#include <unordered_set>

namespace Lib
{

class PasswordGenerator
{
public:
    PasswordGenerator();
    std::string generate(int length) const;
    void add(const std::string& chars);
    void remove(const std::string& chars);
protected:
    std::unordered_set<char> m_alphabet_chars;
    std::vector<char> m_alphabet;
};

}
