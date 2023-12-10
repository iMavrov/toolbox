project(examples)

add_executable(si src/si.cpp)
target_include_directories(si PRIVATE ../include)

add_executable(unit src/unit.cpp)
target_include_directories(unit PRIVATE ../include)

add_executable(generator src/generator.cpp)
target_include_directories(generator PRIVATE ../include)
