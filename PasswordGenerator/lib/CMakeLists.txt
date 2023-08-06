cmake_minimum_required(VERSION 3.5)
project(PasswordGeneratorLibrary VERSION 1.0.0)

set(SOURCES
    password-generator.cpp
)

add_library(passgenLib STATIC ${SOURCES})

set_target_properties(
    passgenLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
