cmake_minimum_required(VERSION 3.15)
project(trermo_example)
set(THERMO_SRC "../src/data_handler.cpp"
        "../src/thermodata_handler.cpp")

add_library(thermo STATIC ${THERMO_SRC})

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries( ${PROJECT_NAME} thermo )