#include <tinyxml2.h>
#include "readers.hpp"
using namespace Lib;

inline std::string
value_or_empty(const char* str)
{
    return str ? str : "";
}

XmlReader::XmlReader(const std::string& file_location)
    : m_file_location{file_location}
{}

void
XmlReader::read(std::vector<Employee>& employees)
{
    using namespace tinyxml2;
    employees.clear();
    XMLDocument xml_doc;
    XMLError error = xml_doc.LoadFile(m_file_location.c_str());
    if (error != XML_SUCCESS)
        return;

    XMLElement* root = xml_doc.FirstChildElement("employees");
    for (XMLElement* employee_tag = root->FirstChildElement("employee"); employee_tag; employee_tag = employee_tag->NextSiblingElement("employee"))
    {
        Employee employee;

        // Personal information block
        XMLElement* pi = employee_tag->FirstChildElement("personal_information");
        employee.gender = value_or_empty(pi->FirstChildElement("gender")->GetText());
        employee.name = value_or_empty(pi->FirstChildElement("name")->GetText());
        employee.surname = value_or_empty(pi->FirstChildElement("surname")->GetText());
        employee.patronomic = value_or_empty(pi->FirstChildElement("patronomic")->GetText());
        employee.phone = value_or_empty(pi->FirstChildElement("phone")->GetText());
        employee.email = value_or_empty(pi->FirstChildElement("email")->GetText());
        employee.country = value_or_empty(pi->FirstChildElement("country")->GetText());
        employee.region = value_or_empty(pi->FirstChildElement("region")->GetText());
        employee.city = value_or_empty(pi->FirstChildElement("city")->GetText());

        // Employee information block
        XMLElement* ei = employee_tag->FirstChildElement("employee_information");
        employee.department = value_or_empty(ei->FirstChildElement("department")->GetText());
        employee.position = value_or_empty(ei->FirstChildElement("position")->GetText());
        employee.supervisor = value_or_empty(ei->FirstChildElement("supervisor")->GetText());
        employee.salary = ei->FirstChildElement("salary")->IntText();

        // Additional information block
        XMLElement* ai = employee_tag->FirstChildElement("additional_information");
        employee.notes = value_or_empty(ai->FirstChildElement("notes")->GetText());

        employees.push_back(employee);
    }
}
