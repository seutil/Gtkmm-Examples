cmake_minimum_required(VERSION 3.5)
project(PersonalCrm VERSION 1.0.0)

find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)

set(SOURCES
    main.cpp
    main-window.cpp
)
set(GRESOURCES_RESOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../resources/main-window.glade
)
set(GRESOURCES_RESOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/../resources/gresources.xml
)
set(GRESOURCES_C
    ${CMAKE_CURRENT_BINARY_DIR}/gresources.c
)

add_custom_command(
    OUTPUT ${GRESOURCES_C}
    COMMAND ${GLIB_COMPILE_RESOURCES}
    ARGS --target=${GRESOURCES_C} --sourcedir=${CMAKE_CURRENT_SOURCE_DIR}/../resources --generate-source ${GRESOURCES_RESOURCE}
    DEPENDS ${GRESOURCES_RESOURCES}
)
add_custom_target(gresources DEPENDS ${GRESOURCES_C})
add_executable(personalCrm ${SOURCES} ${GRESOURCES_C})
add_dependencies(personalCrm gresources)

set_source_files_properties(${GRESOURCES_C} PROPERTIES
    GENERATED TRUE
)
set_target_properties(personalCrm PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_include_directories(personalCrm
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
    ${GTKMM_INCLUDE_DIRS}
)
target_link_libraries(personalCrm
    personalCrmLib
    ${GTKMM_LIBRARIES}
    tinyxml2
)
