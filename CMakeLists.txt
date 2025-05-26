cmake_minimum_required(VERSION 3.15)
project(thermo)

set(SRC "src/data_handler.cpp"
        "src/thermodata_handler.cpp")

add_library(thermo STATIC ${SRC})
