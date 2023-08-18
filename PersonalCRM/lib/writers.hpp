#pragma once
#include <string>
#include <vector>
#include "employee.hpp"

namespace Lib
{

class IWriter
{
public:
    virtual void write(const std::vector<Employee>& employees) = 0;
    virtual ~IWriter() = default;
};

class XmlWriter : public IWriter
{
public:
    XmlWriter(const std::string& file_location);
    void write(const std::vector<Employee>& employees) override;
protected:
    std::string m_file_location;
};

}
