cmake_minimum_required(VERSION 3.5)
project(PasswordGenerator VERSION 1.0.0)

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
set(GRESOURCE_RESOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/../resources/gresources.xml
)
set(GRESOURCE_C
    ${CMAKE_CURRENT_BINARY_DIR}/gresources.c
)

add_custom_command(
    OUTPUT ${GRESOURCE_C}
    COMMAND ${GLIB_COMPILE_RESOURCES}
    ARGS --target=${GRESOURCE_C} --sourcedir=${CMAKE_CURRENT_SOURCE_DIR}/../resources --generate-source ${GRESOURCE_RESOURCE}
    DEPENDS ${GRESOURCE_RESOURCES}
)
add_custom_target(gresource DEPENDS ${GRESOURCE_C})
add_executable(passgen ${SOURCES} ${GRESOURCE_C})
set_source_files_properties(${GRESOURCE_C} PROPERTIES
    GENERATED TRUE
)
add_dependencies(passgen gresource)

set_target_properties(passgen PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_include_directories(
    passgen
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib
        ${GTKMM_INCLUDE_DIRS}
)
target_link_libraries(passgen
    passgenLib
    ${GTKMM_LIBRARIES}
)
