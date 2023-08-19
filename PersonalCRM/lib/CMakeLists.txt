cmake_minimum_required(VERSION 3.5)
project(PersonalCrmLib VERSION 1.0.0)

set(SOURCES
    employee.cpp
    readers.cpp
    writers.cpp
    personal-crm.cpp
)

add_library(personalCrmLib STATIC ${SOURCES})

set_target_properties(personalCrmLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
    LANGUAGE CXX
)
