#pragma once
#include <string>

namespace Lib
{

struct Employee
{
    std::string gender,
                name,
                surname,
                patronomic;
    std::string phone,
                email;
    std::string country,
                region,
                city;
    std::string department,
                superviser,
                position;
    uint salary;
    std::string notes;
};

}
