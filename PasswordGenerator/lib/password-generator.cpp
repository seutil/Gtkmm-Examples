#include <random>
#include <algorithm>
#include "password-generator.hpp"
using namespace Lib;

PasswordGenerator::PasswordGenerator()
{
    srand((unsigned)time(NULL));
    add("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

std::string
PasswordGenerator::generate(int length) const
{
    if (length <= 0)
        return "";

    std::string out;
    out.reserve(length);
    while (length-- > 0)
        out.push_back(m_alphabet[rand() % m_alphabet.size()]);

    return out;
}

void
PasswordGenerator::add(const std::string& chars)
{
    for (auto iter = chars.begin(); iter != chars.end(); ++iter)
    {
        if (m_alphabet_chars.find(*iter) == m_alphabet_chars.end())
        {
            m_alphabet.push_back(*iter);
            m_alphabet_chars.insert(*iter);
        }
    }
}

void
PasswordGenerator::remove(const std::string& chars)
{
    m_alphabet.erase(std::remove_if(
        m_alphabet.begin(),
        m_alphabet.end(),
        [&](char c){ return chars.find_first_of(c) != std::string::npos; }),
        m_alphabet.end()
    );
    for (char c : chars)
        m_alphabet_chars.erase(c);
}
