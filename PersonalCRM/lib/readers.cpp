#include <tinyxml2.h>
#include "readers.hpp"
using namespace Lib;

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
    for (XMLElement* employee_tag = root->FirstChildElement("employee"); employee_tag != nullptr; employee_tag = employee_tag->NextSiblingElement())
    {
        Employee employee;

        // Personal information block
        XMLElement* pi = employee_tag->FirstChildElement("personal_information");
        employee.gender = pi->FirstChildElement("gender")->GetText();
        employee.name = pi->FirstChildElement("name")->GetText();
        employee.surname = pi->FirstChildElement("surname")->GetText();
        employee.patronomic = pi->FirstChildElement("patronomic")->GetText();
        employee.phone = pi->FirstChildElement("phone")->GetText();
        employee.email = pi->FirstChildElement("email")->GetText();
        employee.country = pi->FirstChildElement("country")->GetText();
        employee.region = pi->FirstChildElement("region")->GetText();
        employee.city = pi->FirstChildElement("city")->GetText();

        // Employee information block
        XMLElement* ei = employee_tag->FirstChildElement("employee_information");
        employee.department = ei->FirstChildElement("department")->GetText();
        employee.position = ei->FirstChildElement("position")->GetText();
        employee.supervisor = ei->FirstChildElement("superviser")->GetText();
        employee.salary = std::stoi(ei->FirstChildElement("salary")->GetText());

        // Additional information block
        XMLElement* ai = employee_tag->FirstChildElement("additional_information");
        employee.notes = ai->GetText();

        employees.push_back(employee);
    }
}
