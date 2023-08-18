#include <tinyxml2.h>
#include "writers.hpp"
using namespace Lib;

XmlWriter::XmlWriter(const std::string& file_location)
    : m_file_location{file_location}
{}

void
XmlWriter::write(const std::vector<Employee>& employees)
{
    using namespace tinyxml2;
    XMLDocument xml_doc;
    XMLElement* employees_tag = xml_doc.NewElement("employees");
    xml_doc.InsertFirstChild(employees_tag);
    for (const auto& e : employees)
    {
        XMLElement* employee_tag = xml_doc.NewElement("employee");

        // Personal information block
        XMLElement* pi_tag = xml_doc.NewElement("personal_information");
        XMLElement* pi_gender_tag = xml_doc.NewElement("gender");
        XMLElement* pi_name_tag = xml_doc.NewElement("name");
        XMLElement* pi_surname_tag = xml_doc.NewElement("surname");
        XMLElement* pi_patronomic_tag = xml_doc.NewElement("patronomic");
        XMLElement* pi_phone_tag = xml_doc.NewElement("phone");
        XMLElement* pi_email_tag = xml_doc.NewElement("email");
        XMLElement* pi_country_tag = xml_doc.NewElement("country");
        XMLElement* pi_region_tag = xml_doc.NewElement("region");
        XMLElement* pi_city_tag = xml_doc.NewElement("city");
        pi_gender_tag->SetText(e.gender.c_str());
        pi_name_tag->SetText(e.name.c_str());
        pi_surname_tag->SetText(e.surname.c_str());
        pi_patronomic_tag->SetText(e.patronomic.c_str());
        pi_phone_tag->SetText(e.phone.c_str());
        pi_email_tag->SetText(e.email.c_str());
        pi_country_tag->SetText(e.country.c_str());
        pi_region_tag->SetText(e.region.c_str());
        pi_city_tag->SetText(e.city.c_str());
        pi_tag->InsertEndChild(pi_gender_tag);
        pi_tag->InsertEndChild(pi_name_tag);
        pi_tag->InsertEndChild(pi_surname_tag);
        pi_tag->InsertEndChild(pi_patronomic_tag);
        pi_tag->InsertEndChild(pi_phone_tag);
        pi_tag->InsertEndChild(pi_email_tag);
        pi_tag->InsertEndChild(pi_country_tag);
        pi_tag->InsertEndChild(pi_region_tag);
        pi_tag->InsertEndChild(pi_city_tag);
        employee_tag->InsertEndChild(pi_tag);

        // Employee information block
        XMLElement* ei_tag = xml_doc.NewElement("employee_information");
        XMLElement* ei_depratment_tag = xml_doc.NewElement("department");
        XMLElement* ei_position_tag = xml_doc.NewElement("position");
        XMLElement* ei_superviser_tag = xml_doc.NewElement("superviser");
        XMLElement* ei_salary_tag = xml_doc.NewElement("salary");
        ei_depratment_tag->SetText(e.department.c_str());
        ei_position_tag->SetText(e.position.c_str());
        ei_superviser_tag->SetText(e.superviser.c_str());
        ei_salary_tag->SetText(e.salary);
        ei_tag->InsertEndChild(ei_depratment_tag);
        ei_tag->InsertEndChild(ei_position_tag);
        ei_tag->InsertEndChild(ei_superviser_tag);
        ei_tag->InsertEndChild(ei_salary_tag);
        employee_tag->InsertEndChild(ei_tag);

        // Additional infromation block
        XMLElement* ai_tag = xml_doc.NewElement("additional_information");
        XMLElement* ai_notes_tag = xml_doc.NewElement("notes");
        ai_notes_tag->SetText(e.notes.c_str());
        ai_tag->InsertEndChild(ai_notes_tag);
        employee_tag->InsertEndChild(ai_tag);

        employees_tag->InsertEndChild(employee_tag);
    }

    xml_doc.SaveFile(m_file_location.c_str());
}
