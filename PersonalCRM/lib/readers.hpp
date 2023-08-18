#pragma once
#include <vector>
#include "employee.hpp"

namespace Lib
{

class IReader
{
public:
    virtual void read(std::vector<Employee>& employees) = 0;
    virtual ~IReader() = default;
};

class XmlReader : public IReader
{
public:
    XmlReader(const std::string& file_location);
    void read(std::vector<Employee>& employees) override;
protected:
    std::string m_file_location;
};

}
