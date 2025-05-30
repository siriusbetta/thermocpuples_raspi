cmake_minimum_required(VERSION 3.15)
project(trermo_example)

target_link_libraries(thermo )

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries( ${PROJECT_NAME} thermo mcp23017 max31855)
target_include_directories(${PROJECT_NAME} PUBLIC "../MCP23017_raspi/src")