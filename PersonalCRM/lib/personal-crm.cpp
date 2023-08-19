#include <istream>
#include "personal-crm.hpp"
using namespace Lib;

void
PersonalCrm::load(const std::string& location)
{
    m_reader = std::make_unique<XmlReader>(location);
    m_writer = std::make_unique<XmlWriter>(location);
    m_reader->read(m_employees);
    m_current_employee_id = m_employees.empty() ? -1 : 0;
}

void
PersonalCrm::save()
{
    m_writer->write(m_employees);
}

Employee&
PersonalCrm::employee()
{
    return m_employees[m_current_employee_id];
}

std::vector<Employee>&
PersonalCrm::employees()
{
    return m_employees;
}

bool
PersonalCrm::have_next() const
{
    return m_current_employee_id < m_employees.size();
}

bool
PersonalCrm::have_previouse() const
{
    return m_current_employee_id > 0;
}

void
PersonalCrm::next_employee()
{
    if (m_current_employee_id + 1 < m_employees.size())
        ++m_current_employee_id;
}

void
PersonalCrm::previouse_employee()
{
    if (m_current_employee_id - 1 >= 0)
        --m_current_employee_id;
}

void
PersonalCrm::add_employee()
{
    m_employees.emplace_back();
    m_current_employee_id = m_employees.size() - 1;
}

void
PersonalCrm::remove_employee()
{
    m_employees.erase(m_employees.begin() + m_current_employee_id);
    if (m_current_employee_id == m_employees.size() - 1)
        --m_current_employee_id;
}
