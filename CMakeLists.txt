cmake_minimum_required(VERSION 3.15)
project(thermo)

set(SRC "src/process.cpp"
        "src/data_handler.cpp"
        "src/thermodata_handler.cpp")

add_subdirectory("MAX31855_raspi")
add_subdirectory("MCP23017_raspi")

add_library(thermo STATIC ${SRC})
target_include_directories(thermo PUBLIC "src" "MAX31855_raspi/src" "MCP23017_raspi/src" "spi")
target_link_libraries(thermo "max31855" "mcp23017")
set(EXAMPLE "OFF" CACHE STRING "On/Off example")
if(EXAMPLE) 
  add_subdirectory(example)
endif()
