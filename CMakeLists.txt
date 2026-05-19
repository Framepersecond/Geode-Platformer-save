cmake_minimum_required(VERSION 3.29)

project(platformer_save VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE PERSISTENCE_API_SOURCES CONFIGURE_DEPENDS
    PersistenceAPI/src/*.cpp
)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    ${PERSISTENCE_API_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    PersistenceAPI/include
    PersistenceAPI/src
)

target_compile_definitions(${PROJECT_NAME} PRIVATE SABE_PA_EXPORTING)
target_compile_options(${PROJECT_NAME} PRIVATE "-Wno-invalid-offsetof")

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK is not set")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode-sdk)
setup_geode_mod(${PROJECT_NAME} DONT_INSTALL)
