project(examples)

add_executable(si_unit_demo src/si_unit_demo.cpp)
target_link_libraries(si_unit_demo PRIVATE unit)

add_executable(unit_demo src/unit_demo.cpp)
target_link_libraries(unit_demo PRIVATE unit)

add_executable(generator src/generator.cpp)
target_include_directories(generator PRIVATE ../include)
