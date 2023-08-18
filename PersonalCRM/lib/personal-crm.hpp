#pragma once
#include <memory>
#include <string>
#include <vector>
#include "readers.hpp"
#include "writers.hpp"
#include "employee.hpp"

namespace Lib
{

class PersonalCrm
{
public:
    PersonalCrm(const std::string& location);
    void save();
    bool empty();
    Employee& employee();
    void next_employee();
    void previouse_employee();
    void add_employee();
    void remove_employee();
protected:
    std::string m_location;
    std::unique_ptr<IReader> m_reader;
    std::unique_ptr<IWriter> m_writer;
    std::vector<Employee> m_employees;
    int m_current_employee_id;
};

}