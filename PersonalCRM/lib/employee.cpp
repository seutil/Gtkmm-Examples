#include "employee.hpp"
using namespace Lib;

bool
Employee::valid() const
{
    return !name.empty() && !surname.empty() && !patronomic.empty();
}
