cmake_minimum_required (VERSION 3.5)
project (dia2code)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# libxml2
if(WIN32)
include_directories(libxml2/include)
find_library(LIBXML2_LIBRARIES NAMES libxml2 PATHS libxml2/lib)
else(WIN32)
find_package (LibXml2 REQUIRED)
include_directories(${LIBXML2_INCLUDE_DIR})
endif(WIN32)

# jsoncpp
include_directories ("${PROJECT_SOURCE_DIR}/../extern/jsoncpp-0.10.5/dist")
file(GLOB jsoncpp_sources "${PROJECT_SOURCE_DIR}/../extern/jsoncpp-0.10.5/dist/jsoncpp.cpp")

# Sources
file(GLOB_RECURSE main_sources src/*.c)

# Executables
add_executable(dia2code ${main_sources} ${jsoncpp_sources})
target_link_libraries(dia2code ${LIBXML2_LIBRARIES})


