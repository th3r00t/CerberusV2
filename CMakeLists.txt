# minimum CMake version required
cmake_minimum_required(VERSION 3.15)
# Project name, version and description
project(SeDiver-bot VERSION 0.1.0 DESCRIPTION "A Space Engineers discovery discord bot")
 
# find_package(nlohmann_json 3.2.0 REQUIRED)
 
# Create an executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/embeds.h
    src/gameobjects.h
)
add_subdirectory(lib/json) 
# Linking libraries
target_link_libraries(${PROJECT_NAME}
    dpp
    nlohmann_json::nlohmann_json
)
 
# Specify includes
target_include_directories(${PROJECT_NAME} PRIVATE)
 
# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17 # or 20 if you want something more recent
    CXX_STANDARD_REQUIRED ON
)

